//Created by Darrell Smith and Brent Spector
#pragma once

#include "ABC.h"
using namespace GSP420;

#include <list>
//keep some data all together here so it is easier to change later
const static int ENEMY_1_HEALTH = 1;
const static int ENEMY_2_HEALTH = 2;
const static int ENEMY_3_HEALTH = 3;
const static int ENEMY_BOSS_HEALTH = 25;

class Enemy : public GSP420::ABC
{
public:
	Enemy(D3DXVECTOR3 pos, ObjType t);
	bool init(const int modelId, const int textureId) { return true; }
	void update(const float) {}
	void shutdown() {}
	void fireBullet(D3DXVECTOR3 velocity);
	void fireMissile(D3DXVECTOR3 velocity);
	void dropMine();
	inline void takeDamage(int d) { damage += d; }
	inline int getDamage() { return damage; }
	inline int getScore() { return score; }
	inline float getBulletFireRate() { return bulletFireRate; }
	inline float getMissileFireRate() { return missileFireRate; }
	inline float getMineFireRate() { return mineFireRate; }
	inline void setBulletFireRate(float r) { bulletFireRate = r; }
	inline void setMissileFireRate(float r) { missileFireRate = r; }
	inline void setMineFireRate(float r) { mineFireRate = r; }
protected:
	//score player gets for the enemy
	int score;
	int damage;//damage taken so far. If this exceeds their health, they are destroyed
	//fire rates for bullets, missiles, and mines, to be set and used by AI
	//set the ones not being used to -1.0f
	float bulletFireRate, missileFireRate, mineFireRate;
};

class EnemyManager
{
	friend class AI;
	friend class D3DCore;
	friend class Physics;
public:
	void add(Enemy);
	void update(const float);
	inline void clear() { Enemies.clear(); }
private:
	std::list<Enemy> Enemies;
	inline std::list<Enemy>& getEnemies() { return Enemies; }
};

