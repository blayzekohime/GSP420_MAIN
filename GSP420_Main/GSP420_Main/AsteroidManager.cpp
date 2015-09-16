#include "AsteroidManager.h"

#include "Game.h"

void AsteroidManager::update(const float dt)
{
	std::list<LargeAsteroid>::iterator it1 = LargeAsteroids.begin();
	while (it1 != LargeAsteroids.end())
	{
		if (!it1->isEnabled())
		{
			//make 3-5 new small asteroids to replace the large one
			int new_smalls = 3 + rand() % 3;
			for (int i = 0; i < new_smalls; ++i)
			{
				SmallAsteroids.push_front(SmallAsteroid(it1->getPosition()));
			}
			//remove the large one
			LargeAsteroids.erase(it1++);
			//score
			PLAYER.giveScore(ASTEROID_LARGE_SCORE);
		}
	}
	std::list<SmallAsteroid>::iterator it2 = SmallAsteroids.begin();
	while (it2 != SmallAsteroids.end())
	{
		if (!it2->isEnabled())
		{
			//remove
			SmallAsteroids.erase(it2++);
			//score
			PLAYER.giveScore(ASTEROID_SMALL_SCORE);
		}
	}
}

void AsteroidManager::clear()
{
	SmallAsteroids.clear();
	LargeAsteroids.clear();
}

