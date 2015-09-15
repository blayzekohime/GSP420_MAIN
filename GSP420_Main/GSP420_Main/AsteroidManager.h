#pragma once

#include <list>
#include "ABC.h"

class LargeAsteroid : public ABC
{
public:
	LargeAsteroid() : ABC() {}
	void update(const float);
	bool init(const int modelId, const int textureId) { return true; }
	void shutdown() {}
private:
};

class SmallAsteroid : public ABC
{
public:
	SmallAsteroid() : ABC() {}
	void update(const float);
	bool init(const int modelId, const int textureId) { return true; }
	void shutdown() {}
private:
	
};

class AsteroidManager
{
public:
	void update(const float);
	void init(const int modelId, const int textureId) {}
	void shutdown() {}
	void add(LargeAsteroid);
	void Break(std::list<LargeAsteroid>::reverse_iterator);
	void add(SmallAsteroid);
	void remove(std::list<SmallAsteroid>::reverse_iterator);
	void clear();
private:
	std::list<LargeAsteroid> LargeAsteroids;
	std::list<SmallAsteroid> SmallAsteroids;
};

