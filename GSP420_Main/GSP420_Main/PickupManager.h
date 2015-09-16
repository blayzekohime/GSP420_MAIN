#pragma once

#include <list>
#include <vector>
#include "GSP420_ABC.h"

const static int HEALTH_REGAINED = 10;
const static float INVULNERABLE_TIME = 10.f;
const static int MISSILES_GIVEN = 5;
const static int MINE_DAMAGE = 10;

enum PICKUP_TYPE { PU_HEALTH, PU_INVULNERABLE, PU_MISSILE, PU_MINE };

class Pickup : public GSP420_ABC
{
public:
	Pickup(D3DXVECTOR3 pos, PICKUP_TYPE t) : GSP420_ABC(pos, OT_PICKUP), taken(false) {}
	void update(const float) {}
	bool init(const int modelId, const int textureId) { return true; }
	void shutdown() {}
	void activate();
	inline bool isTaken() { return taken; }
private:
	PICKUP_TYPE Type;
	bool taken;//if taken by player. If it has been, then it will be activated on removal
	//depending on the type of pick up, this could be amount of health gained,
	//seconds of invulnerability gained, or missile ammo received
	int Value;
};


class PickupManager
{
public:
	void add(Pickup);
	void update(const float);
	inline void clear() { Pickups.clear(); }
private:
	std::list<Pickup> Pickups;
};
