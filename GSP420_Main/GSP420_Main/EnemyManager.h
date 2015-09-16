#pragma once

#include <list>
#include <vector>

#include "GSP420_ABC.h"

//keep some data all together here so it is easier to change later
const static int ENEMY_1_HEALTH = 1;
const static int ENEMY_2_HEALTH = 2;
const static int ENEMY_3_HEALTH = 3;
const static int ENEMY_BOSS_HEALTH = 25;

class Enemy : public GSP420_ABC
{
public:
	Enemy(D3DXVECTOR3 pos, OBJ_TYPE t);
	bool init(const int modelId, const int textureId) { return true; }
	void update(const float) {}
	void shutdown() {}
	void fireBullet(D3DXVECTOR3 velocity);
	void fireMissile();
	void dropMine();
	inline int getDamage() { return damage; }
	inline int getScore() { return score; }
protected:
	//score player gets for the enemy
	int score;
	int damage;//damage taken so far. If this exceeds their health, they are destroyed
};

class EnemyManager
{
public:
	void add(Enemy);
	void update(const float);
	inline void clear() { Enemies.clear(); }
private:
	std::list<Enemy> Enemies;
};

