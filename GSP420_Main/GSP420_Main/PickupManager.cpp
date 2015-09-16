#include "PickupManager.h"

#include "Game.h"

void Pickup::activate()
{
	switch (Type)
	{
	case PU_HEALTH:
		PLAYER.heal(HEALTH_REGAINED);
		break;
	case PU_INVULNERABLE:
		PLAYER.makeInvulnerable(INVULNERABLE_TIME);
		break;
	case PU_MISSILE:
		PLAYER.giveMissileAmmo(MISSILES_GIVEN);
		break;
	case PU_MINE:
		PLAYER.hurt(MINE_DAMAGE);
		break;
	}
}

void PickupManager::add(Pickup p)
{
	Pickups.push_front(p);
}

void PickupManager::update(const float dt)
{
	std::list<Pickup>::iterator it = Pickups.begin();
	while (it != Pickups.end())
	{
		if (it->isTaken())
		{
			it->activate();
			Pickups.erase(it++);
		}
		else if (!it->isEnabled())
		{
			Pickups.erase(it++);
		}
	}
}



