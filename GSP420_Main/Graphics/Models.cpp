#include "Models.h"
#include "Textures.h"

using namespace GFXCore;

int Models::nIdGenerator = -1;

Models::Models()
{
}


Models::~Models()
{
}

void Models::init(const int startNumModels /*= 10*/)
{
	modelList.resize(startNumModels);
}

int Models::loadModel(IDirect3DDevice9* device, wchar_t* fileName,  
								Textures& textures,
								const D3DXVECTOR3& initPos /*= D3DXVECTOR3(0.0f, 0.0f, 0.0f)*/, 
								const D3DXVECTOR3& initRot /*= D3DXVECTOR3(0.0f, 0.0f, 0.0f)*/, 
								const D3DXVECTOR3& initScale /*= D3DXVECTOR3(1.0f, 1.0f, 1.0f)*/, 
								DWORD options /*= D3DXMESH_MANAGED*/)
{
	XModelData modelData;
	memset(&modelData, NULL, sizeof(XModelData));

	if (FAILED(D3DXLoadMeshFromX(fileName, options, device, &modelData.pAdjacency,
		&modelData.pMaterials, &modelData.pEffectInstances,
		&modelData.dwNumMaterials, &modelData.pMesh))) {

		ErrorMsg(L"Load Mesh failure - Models::loadModel().", fileName);

		return -1;

	}

	D3DXMATERIAL* modelMats = (D3DXMATERIAL*)modelData.pMaterials->GetBufferPointer();
	if (NULL == modelMats)
		return -1;

	modelData.materialList.resize(modelData.dwNumMaterials);
	modelData.textureList.resize(modelData.dwNumMaterials);

	for (DWORD i = 0; i < modelData.dwNumMaterials; ++i) {
		modelData.materialList[i].Ambient = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f); // TODO: change this to a func param
		modelData.materialList.push_back(modelMats[i].MatD3D);

		if (modelMats[i].pTextureFilename) {
			int len = 0;
			len = (int)strlen(modelMats[i].pTextureFilename) + 1;
			wchar_t* wstr = new wchar_t[len];
			mbstowcs(wstr, modelMats[i].pTextureFilename, len);
			int texId = textures.loadTexture(device, wstr);
			modelData.textureList.push_back(texId);
			delete[] wstr;
			wstr = NULL;
		}
	}

	D3DXMatrixIdentity(&modelData.translationMat);
	D3DXMatrixIdentity(&modelData.rotationMat);
	D3DXMatrixIdentity(&modelData.scalingMat);
	D3DXMatrixIdentity(&modelData.worldTranformMat);

	D3DXMatrixTranslation(&modelData.translationMat, initPos.x, initPos.y, initPos.z);
	D3DXMatrixRotationYawPitchRoll(&modelData.rotationMat, initRot.x, initRot.y, initRot.z);
	D3DXMatrixScaling(&modelData.scalingMat, initScale.x, initScale.y, initScale.z);

	D3DXMatrixMultiply(&modelData.scalingMat, &modelData.scalingMat, &modelData.rotationMat);
	D3DXMatrixMultiply(&modelData.worldTranformMat, &modelData.scalingMat, &modelData.translationMat);
	// TODO: add functionality to be able to set a particular shader to the model
	modelList.push_back(modelData);

	return ++nIdGenerator;
}

void GFXCore::Models::update(const int id, const D3DXVECTOR3& position, 
											const bool rotChange /*= false*/, const bool scaleChange /*= false*/,
											const D3DXVECTOR3& rotation /*= D3DXVECTOR3(0.0f, 0.0f, 0.0f)*/, 
											const D3DXVECTOR3& scaling /*= D3DXVECTOR3(1.0f, 1.0f, 1.0f)*/)
{
	setTranslation(id, position);
	if (rotChange)
		setRotation(id, rotation);
	if (scaleChange)
		setScaling(id, scaling);

	D3DXMatrixMultiply(&modelList[id].scalingMat, &modelList[id].scalingMat, &modelList[id].rotationMat);
	D3DXMatrixMultiply(&modelList[id].worldTranformMat, &modelList[id].scalingMat, &modelList[id].translationMat);
}

void Models::render(IDirect3DDevice9* device, const int id)
{

}

void Models::shutdown()
{
	for (unsigned int i = 0; i < modelList.size(); ++i) {
		if (modelList[i].pAdjacency)
			ReleaseCom(modelList[i].pAdjacency);
		if (modelList[i].pEffectInstances)
			ReleaseCom(modelList[i].pEffectInstances);
		if (modelList[i].pMaterials)
			ReleaseCom(modelList[i].pMaterials);
		if (modelList[i].pMesh)
			ReleaseCom(modelList[i].pMesh);

		modelList[i].materialList.clear();
		modelList[i].materialList.resize(0);

		modelList[i].textureList.clear();
		modelList[i].textureList.resize(0);
	}
}

