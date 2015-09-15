#include "EnemyManager.h"

#include "Graphics.h"
#include "ProjectileManager.h"


void Enemy::update(const float dt)
{
	//todo: get movement or collisions or if firing from AI/Physics
}

void Enemy::FireBullet()
{
	//create bullet with a speed and direction

	//pass to projectiles to be put in the list for enemy projectiles
}

void Enemy::FireMissile(Player Target)//or auto-target the one existing player?
{
	//create missile with speed, direction, and target

	//pass to projectiles to be put in the list for enemy projectiles
}

void EnemyManager::add(Enemy e)
{
	Enemies.push_front(e);
}

void EnemyManager::remove(std::list<Enemy>::reverse_iterator which)
{
	Enemies.erase(--which.base());
}

void EnemyManager::update(const float dt)
{
	for (std::list<Enemy>::reverse_iterator it = Enemies.rbegin(), rend = Enemies.rend(); it != rend; ++it)
	{
		it->update(dt);
		//erase if needed

	}
}

void EnemyManager::clear()
{
	Enemies.clear();
	Flags.clear();
}

