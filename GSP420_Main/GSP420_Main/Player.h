#pragma once

#include "GSP420_ABC.h"
//keeping the score amounts in one place to make them easier to alter
const static int ENEMY_1_SCORE = 15;
const static int ENEMY_2_SCORE = 25;
const static int ENEMY_3_SCORE = 50;
const static int ENEMY_BOSS_SCORE = 250;
const static int ASTEROID_SMALL_SCORE = 20;
const static int ASTEROID_LARGE_SCORE = 20;

const static float HURT_INVULNERABILITY = 1.f;//how long player is invulnerable after being harmed

class Player : public GSP420_ABC
{
public:
	Player() : GSP420_ABC(), missileAmmo(0), maxHealth(25), invulnerable(0.f) {}
	void fireBullet();
	void fireMissile();
	void heal(int);
	void hurt(int);
	void move(D3DXVECTOR3);
	void endGame();
	void update(const float);
	bool init(const int modelId, const int textureId) { return true; }
	void shutdown() {}
	inline int getMissileAmmo() { return missileAmmo; }
	inline int getMaxHealth() { return maxHealth; }
	inline void giveScore(int s) { score += s; }
	inline void makeInvulnerable(float secs) { invulnerable = secs; }
	inline void giveMissileAmmo(int ammo) { missileAmmo += ammo; }
private:
	int missileAmmo;
	int maxHealth;
	float invulnerable;//seconds of invulnerability left
	int score;
};
