#pragma once


//d3d includes and libraries
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")



class ABC
{
public:
	virtual bool init(const int modelId, const int textureId) = 0;
	virtual void update(const float dt) = 0;
	virtual void shutdown() = 0;

	inline D3DXVECTOR3& getPosition();
	inline D3DXVECTOR3& getVelocity();
	inline int getHealth();
	inline int getModelId();
	inline int getTextureId();
	inline bool isEnabled();
	inline void setPosition(const D3DXVECTOR3& pos);
	inline void setVelocity(const D3DXVECTOR3& velo);
	inline void setHealth(const int health);
	inline void toggleEnabled();
	inline void setEnabled(const bool enabled);

protected:
	D3DXVECTOR3		position;
	D3DXVECTOR3		velocity;

	int		nHealth;
	int		nTextureId;
	int		nModelId;
	int		nObjectId;

	bool bEnabled;
};

D3DXVECTOR3& ABC::getPosition() { return position; }
D3DXVECTOR3& ABC::getVelocity() { return velocity; }
int ABC::getHealth() { return nHealth; }
int ABC::getModelId() { return nModelId; }
int ABC::getTextureId() { return nTextureId; }
bool ABC::isEnabled() { return bEnabled; }
void ABC::setPosition(const D3DXVECTOR3& pos) { position = pos; }
void ABC::setVelocity(const D3DXVECTOR3& velo) { velocity = velo; }
void ABC::setHealth(const int health) { nHealth = health; }
void ABC::toggleEnabled() { bEnabled = !bEnabled; }
void ABC::setEnabled(const bool enabled) { bEnabled = enabled; }
