#pragma once

#include <list>
#include <vector>
#include "ABC.h"


enum PICKUP_TYPE { PU_HEALTH, PU_INVULNERABLE, PU_MISSILE };

class Pickup : public ABC
{
public:
	Pickup() : ABC() {}
	void update(const float);
	bool init(const int modelId, const int textureId) { return true; }
	void shutdown() {}
	void Activate();
private:
	PICKUP_TYPE Type;
	bool Alive;
	//depending on the type of pick up, this could be amount of health gained,
	//seconds of invulnerability gained, or missile ammo received
	int Value;
};


class PickupManager
{
public:
	void add(Pickup);
	void remove(std::list<Pickup>::reverse_iterator);
	void update(const float);
	void clear();
private:
	std::list<Pickup> Pickups;
	std::vector<int> Flags;
};
