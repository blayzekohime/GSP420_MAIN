#pragma once

#include <list>
#include "ABC.h"
#include "EnemyManager.h"


static const int BULLET_DAMAGE = 1;
static const int MISSILE_DAMAGE = 2;
static const int COLLISION_DAMAGE = 1;
static const int MISSILE_RADIUS = 50;

class Bullet : public GSP420::ABC
{
public:
	Bullet(const D3DXVECTOR3 pos, const D3DXVECTOR3 vel, const ObjType t) : ABC(pos, vel, t) {}
	void update(const float) {}
	bool init(const int modelId, const int textureId) { return true; }
	void shutdown() {}
	inline bool isPlayers() { return eType == OT_PLAYER_BULLET; }
protected:
};

class Missile : public GSP420::ABC
{
public:
	Missile(const D3DXVECTOR3 pos, const D3DXVECTOR3 vel, const ObjType t, Enemy* targ = NULL) :
		ABC(pos, vel, t), target(targ)
	{}
	void update(const float) {}
	bool init(const int modelId, const int textureId) { return true; }
	void shutdown() {}
	inline void setEnemyTarget(Enemy*e) { target = e; }
	inline Enemy* getEnemyTarget() { return target; }//returns NULL if it needs re-targeted or if player is target
	inline bool isPlayers() { return eType == OT_PLAYER_MISSILE; }
private:
	Enemy* target;//applies only to player's missiles, will be null if it is player's or if it needs re-targeted
};

class ProjectileManager
{
	friend class D3DCore;
	friend class Physics;
public:
	inline void addBullet(Bullet b) { Projectiles.push_front(b); }
	inline void addMissile(Missile m) { Projectiles.push_front(m); }
	void update(const float);
	inline void clear() { Projectiles.clear(); }
	void removeTarget(Enemy*);//if any missiles are targeting that enemy, set their targets to NULL instead
private:
	std::list<GSP420::ABC> Projectiles;
};
