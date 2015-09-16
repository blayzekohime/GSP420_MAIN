#include "EnemyManager.h"

#include "Game.h"

Enemy::Enemy(D3DXVECTOR3 pos, OBJ_TYPE t) : GSP420_ABC(pos, t), damage(0), minBulletTime(-1.f), maxBulletTime(-1.f),
	minMissileTime(-1.f), maxMissileTime(-1.f), minMineTime(-1.f), maxMineTime(-1.f), 
	nextVelocity(D3DXVECTOR3(0.f, 0.f, 0.f))
{
	switch (t)
	{
	case OT_ENEMY1:
		nHealth = ENEMY_1_HEALTH;
		score = ENEMY_1_SCORE;
		minBulletTime = 1.f;
		maxBulletTime = 2.f;
		break;
	case OT_ENEMY2:
		nHealth = ENEMY_2_HEALTH;
		score = ENEMY_2_SCORE;
		minMissileTime = 2.f;
		maxMissileTime = 3.f;
		break;
	case OT_ENEMY3:
		nHealth = ENEMY_3_HEALTH;
		score = ENEMY_3_SCORE;
		minBulletTime = .8f;
		maxBulletTime = 1.f;
		minMineTime = 3.f;
		maxMineTime = 4.f;
		break;
	case OT_ENEMYBOSS:
		nHealth = ENEMY_BOSS_HEALTH;
		score = ENEMY_BOSS_SCORE;
		minBulletTime = .7f;
		maxBulletTime = .9f;
		minMissileTime = 1.5f;
		maxMissileTime = 2.5f;
		minMineTime = 2.5f;
		maxMineTime = 3.5f;
		break;
	}
}

void Enemy::fireBullet(D3DXVECTOR3 vel)
{
	//create projectile starting at current position
	PROJECTILES.addBullet(Bullet(position, vel, OT_ENEMY_BULLET));
}

void Enemy::fireMissile()//or auto-target the one existing player?
{
	//create missile with position and target, velocity will be determined by target
	PROJECTILES.addMissile(Missile(position, OT_ENEMY_MISSILE));
}

void Enemy::dropMine()
{
	PICKUPS.add(Pickup(position, PU_MINE));
}

void EnemyManager::add(Enemy e)
{
	Enemies.push_front(e);
}
#include <iostream>
void EnemyManager::update(const float dt)
{
	std::list<Enemy>::iterator it = Enemies.begin();
	while (it != Enemies.end())
	{
		it->update(dt);
		if (it->getDamage() >= it->getHealth())
		{
			//check if any missiles are targeting it and  mark their target as NULL for re-targeting
			std::cout << it->getHealth();
			PROJECTILES.removeTarget(&*it);
			//give player score
			PLAYER.giveScore(it->getScore());
			//then delete
			Enemies.erase(it++);
		}
	}
}

