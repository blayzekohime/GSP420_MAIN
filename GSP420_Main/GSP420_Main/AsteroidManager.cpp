#include "AsteroidManager.h"

#include <iostream>

#include "Graphics.h"


void AsteroidManager::update(const float dt)
{
	for (std::list<SmallAsteroid>::reverse_iterator it = SmallAsteroids.rbegin(), rend = SmallAsteroids.rend();
	it != rend; ++it)
	{
		it->update(dt);
	}
	for (std::list<LargeAsteroid>::reverse_iterator it = LargeAsteroids.rbegin(), rend = LargeAsteroids.rend();
	it != rend; ++it)
	{
		it->update(dt);
	}
	//SmallAsteroids.remove_if(Pred());
}

void AsteroidManager::add(LargeAsteroid a)
{
	LargeAsteroids.push_front(a);
}

void AsteroidManager::Break(std::list<LargeAsteroid>::reverse_iterator which)
{
	//erase the reverse iterator index from the list
	LargeAsteroids.erase(--which.base());
	//replace with 3-5 random small asteroids
	int num_asteroids = 3 + rand() % 3;
	for (int i = 0; i < num_asteroids; ++i)
	{
		//todo: get new asteroid from physics
	}
}

void AsteroidManager::add(SmallAsteroid a)
{
	SmallAsteroids.push_front(a);
}

void AsteroidManager::remove(std::list<SmallAsteroid>::reverse_iterator which)
{
	SmallAsteroids.erase(--which.base());
}

void AsteroidManager::clear()
{
	SmallAsteroids.clear();
	LargeAsteroids.clear();
}

void LargeAsteroid::update(const float dt)
{
	//todo: update asteroid position and collisions from AI
}

void SmallAsteroid::update(const float dt)
{
	//todo: update asteroid position and collisions from AI
}


