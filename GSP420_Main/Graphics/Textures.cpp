#include "Textures.h"

using namespace GFXCore;

int Textures::nIdGenerator = -1;

Textures::Textures()
{
}


Textures::~Textures()
{
}

void Textures::init(const int startNumTex /*= 20*/)
{
	texList.resize(startNumTex);
}

int Textures::loadTexture(IDirect3DDevice9* device, const wchar_t* fileName)
{
	TexureData tex;
	memset(&tex, NULL, sizeof(TexureData));

	D3DXIMAGE_INFO texInfo;
	memset(&texInfo, NULL, sizeof(D3DXIMAGE_INFO));

	HR(D3DXGetImageInfoFromFile(fileName, &texInfo));
	tex.nHeight = texInfo.Height;
	tex.nWidth = texInfo.Width;

	if (FAILED(D3DXCreateTextureFromFile(device, fileName, &tex.pTex))) {
		ErrorMsg(L"Create Texture Failure.", fileName);
		return -1;
	}
	
	texList.push_back(tex);

	return ++nIdGenerator;
}

void Textures::shutdown()
{
	for (unsigned int i = 0; i < texList.size(); ++i){
		if (texList[i].pTex)
			ReleaseCom(texList[i].pTex);
	}

	texList.clear();
	texList.resize(0);
}
