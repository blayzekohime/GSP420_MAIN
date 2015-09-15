#pragma once

#include <list>
#include <vector>
#include "ABC.h"
#include "EnemyManager.h"
#include "Player.h"



class Projectile : public ABC
{
public:
	Projectile() : ABC() {}
	void update(const float);
	bool init(const int modelId, const int textureId) { return true; }
	void shutdown() {}
	bool IsPlayers() { return Players; }
protected:
	bool Players;
};

class Missile : public Projectile
{
public:
	void update(const float) {}
	bool init(const int modelId, const int textureId) { return true; }
	void shutdown() {}
	Missile() : Projectile() {}
	inline Player getPlayerTarget() { return PlayerTarget; }
	inline Enemy getEnemyTarget() { return EnemyTarget; }
private:
	Player PlayerTarget;
	Enemy EnemyTarget;
};

class ProjectileManager
{
public:
	void add(Projectile);
	void remove(std::list<Projectile>::reverse_iterator, bool = false);
	void update(const float);
	inline void ClearEnemyProjectiles() { EnemyProjectiles.clear(); }
	inline void ClearPlayerProjectiles() { PlayerProjectiles.clear(); }
	inline void ClearFlags() { std::vector<int>().swap(Flags); }
	void clear();
private:
	std::list<Projectile> EnemyProjectiles;
	std::list<Projectile> PlayerProjectiles;
	std::vector<int> Flags;
};
