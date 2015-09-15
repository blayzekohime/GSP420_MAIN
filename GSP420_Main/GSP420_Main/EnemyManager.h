#pragma once

#include <list>
#include <vector>

#include "ABC.h"
#include "Player.h"

class Enemy : public ABC
{
public:
	Enemy() : ABC() {}
	bool init(const int modelId, const int textureId) { return true; }
	void update(const float);
	void shutdown() {}
	void FireBullet();
	void FireMissile(Player Target);
private:
};

class EnemyManager
{
public:
	void add(Enemy);
	void remove(std::list<Enemy>::reverse_iterator);
	void update(const float);
	void clear();
private:
	std::list<Enemy> Enemies;
	std::vector<int> Flags;
};

