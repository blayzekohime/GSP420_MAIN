#include "ProjectileManager.h"

#include "Game.h"

void ProjectileManager::update(const float dt)
{
	std::list<GSP420::ABC>::iterator it = Projectiles.begin();
	while (it != Projectiles.end())
	{
		if (!it->isEnabled())
			Projectiles.erase(it++);
		else
			++it;
	}
}

void ProjectileManager::removeTarget(Enemy* targ)
{
	for (std::list<GSP420::ABC>::iterator it = Projectiles.begin(), end = Projectiles.end();
	it != end; ++it)
	{
		//if it is a player missile and has a matching target, set the target to NULL instead
		if (it->getObjectType() == GSP420::OT_PLAYER_MISSILE && ((Missile*)&it)->getEnemyTarget() == targ)
		{
			((Missile*)&it)->setEnemyTarget(NULL);
		}
	}
}

