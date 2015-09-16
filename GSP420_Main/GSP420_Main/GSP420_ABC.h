#pragma once

//d3d includes and libraries
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")

enum OBJ_TYPE {
	OT_BEGIN = -1,
	OT_LARGE_ASTEROID,
	OT_SMALL_ASTEROID,
	OT_ENEMY1,
	OT_ENEMY2,
	OT_ENEMY3,
	OT_ENEMYBOSS,
	OT_PICKUP,
	OT_PLAYER_BULLET,
	OT_ENEMY_BULLET,
	OT_PLAYER_MISSILE,
	OT_ENEMY_MISSILE,
	OT_PLAYER,
	OT_END
};

class GSP420_ABC
{
public:
	GSP420_ABC() : bEnabled(true) {}
	GSP420_ABC(const OBJ_TYPE t) : eType(t), bEnabled(true) {}
	GSP420_ABC(const D3DXVECTOR3 p, const OBJ_TYPE t) :
		position(p), eType(t), bEnabled(true), velocity(D3DXVECTOR3(0.f, 0.f, 0.f)) {}
	GSP420_ABC(const D3DXVECTOR3 p, const D3DXVECTOR3 v, const OBJ_TYPE t) :
		position(p), velocity(v), eType(t), bEnabled(true) {}
	GSP420_ABC(const D3DXVECTOR3 p, const int h, const OBJ_TYPE t) :
		position(p), velocity(D3DXVECTOR3(0.f, 0.f, 0.f)), nHealth(h), eType(t), bEnabled(true) {}
	GSP420_ABC(const D3DXVECTOR3 p, const D3DXVECTOR3 v, const int h, const OBJ_TYPE t) :
		position(p), velocity(v), nHealth(h), eType(t), bEnabled(true) {}

	virtual bool init(const int modelId, const int textureId) { return true; }
	virtual void update(const float dt) {}
	virtual void shutdown() {}

	inline D3DXVECTOR3& getPosition()						{ return position; }
	inline D3DXVECTOR3& getVelocity()						{ return velocity; }
	inline int getHealth()									{ return nHealth; }
	inline int getModelId()									{ return nModelId; }
	inline int getTextureId()								{ return nTextureId; }
	inline OBJ_TYPE getObjectType()							{ return eType; }
	inline bool isEnabled()									{ return bEnabled; }
	inline void setPosition(const D3DXVECTOR3& pos)			{ position = pos; }
	inline void setVelocity(const D3DXVECTOR3& velo)		{ velocity = velo; }
	inline void setFixedRotation(const D3DXVECTOR3& rot)	{ fixedRotation = rot; }
	inline void setHealth(const int health)					{ nHealth = health; }
	inline void toggleEnabled()								{ bEnabled = !bEnabled; }
	inline void setEnabled(const bool enabled)				{ bEnabled = enabled; }
	inline void setObjectType(OBJ_TYPE e)					{ eType = e; }

	//ABC(const ABC&);
	virtual ~GSP420_ABC() {}

protected:
	D3DXVECTOR3		position;
	D3DXVECTOR3		velocity;
	D3DXVECTOR3		fixedRotation;

	OBJ_TYPE		eType;

	int		nHealth;
	int		nTextureId;
	int		nModelId;
	int		nObjectId;

	bool	bEnabled;
};

