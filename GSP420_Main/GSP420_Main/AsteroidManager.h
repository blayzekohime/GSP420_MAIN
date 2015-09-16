#pragma once

#include <list>
#include "GSP420_ABC.h"

class LargeAsteroid : public GSP420_ABC
{
public:
	LargeAsteroid(const D3DXVECTOR3 pos) : GSP420_ABC(pos, OT_LARGE_ASTEROID) {}
	void update(const float) {}
	bool init(const int modelId, const int textureId) { return true; }
	void shutdown() {}
private:
};

class SmallAsteroid : public GSP420_ABC
{
public:
	SmallAsteroid(const D3DXVECTOR3 pos) : GSP420_ABC(pos, OT_SMALL_ASTEROID) {}
	void update(const float) {}
	bool init(const int modelId, const int textureId) { return true; }
	void shutdown() {}
private:
	
};

class AsteroidManager
{
public:
	void update(const float);
	void init(const int modelId, const int textureId) {}
	inline void add(LargeAsteroid a) { LargeAsteroids.push_front(a); }
	void shutdown() {}
	void clear();
private:
	std::list<LargeAsteroid> LargeAsteroids;
	std::list<SmallAsteroid> SmallAsteroids;
};

