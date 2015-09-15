#include "PickupManager.h"

#include "Player.h"

#include "Graphics.h"


void Pickup::update(const float dt)
{
	//todo: update position and check for collision with player
}

void Pickup::Activate()
{
	switch (Type)
	{
	case PU_HEALTH:
		//add value to player's health
		break;
	case PU_INVULNERABLE:
		//add value seconds of invulnerable status to player
		break;
	case PU_MISSILE:
		//give value missiles to player
		break;
	}
}

void PickupManager::add(Pickup p)
{
	Pickups.push_front(p);
}

void PickupManager::remove(std::list<Pickup>::reverse_iterator which)
{
	Pickups.erase(--which.base());
}

void PickupManager::update(const float dt)
{
	for (std::list<Pickup>::reverse_iterator it = Pickups.rbegin(), rend = Pickups.rend(); it != rend; ++it)
	{
		it->update(dt);
	}
}

void PickupManager::clear()
{
	Pickups.clear();
	std::vector<int>().swap(Flags);
}

