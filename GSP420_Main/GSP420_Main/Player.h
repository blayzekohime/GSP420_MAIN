#pragma once

#include "ABC.h"


class Player : public ABC
{
public:
	Player() : ABC(), missileAmmo(0), maxHealth(10), invulnerable(0.f) {}
	void fireBullet();
	void fireMissile();
	void heal(int);
	void hurt(int);
	void move(D3DXVECTOR3);
	void endGame();
	void update(const float);
	bool init(const int modelId, const int textureId) {}
	void shutdown() {}
	int getMissileAmmo() { return missileAmmo; }
	int getMaxHealth() { return maxHealth; }
private:
	int missileAmmo;
	int maxHealth;
	float invulnerable;//seconds of invulnerability left
};
