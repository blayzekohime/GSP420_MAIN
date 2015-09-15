#include "ProjectileManager.h"

#include "Graphics.h"



void Projectile::update(const float dt)
{
	//todo::query AI/Physics to find Projectile movement and if it should be destroyed
	if (Players)
	{
		//check for collision with enemies and asteroids
	}
	else
	{
		//check for collision with player
	}
}

void ProjectileManager::add(Projectile p)
{
	p.IsPlayers() ? PlayerProjectiles.push_front(p) : EnemyProjectiles.push_front(p);
}

void ProjectileManager::remove(std::list<Projectile>::reverse_iterator which, bool players)
{
	players ? PlayerProjectiles.erase(--which.base()) : EnemyProjectiles.erase(--which.base());
}

void ProjectileManager::update(const float dt)
{
	for (std::list<Projectile>::reverse_iterator it = PlayerProjectiles.rbegin(),
		rend = PlayerProjectiles.rend(); it != rend; ++it)
	{
		it->update(dt);
	}
	for (std::list<Projectile>::reverse_iterator it = EnemyProjectiles.rbegin(),
		rend = EnemyProjectiles.rend(); it != rend; ++it)
	{
		it->update(dt);
	}
}

void ProjectileManager::clear()
{
	EnemyProjectiles.clear();
	PlayerProjectiles.clear();
	std::vector<int>().swap(Flags);
}

