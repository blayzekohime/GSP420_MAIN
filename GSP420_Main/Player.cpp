#include "Player.h"

#include "Game.h"

void Player::fireBullet()
{
	//create bullet with velocity and position
	if(lastBullet <= 0)
	{
		Bullet b = Bullet(position, BULLET_START_DIRECTION * BULLET_SPEED, 
			OT_PLAYER_BULLET);
		//b.init(1,1);//need to find out what ID to use from graphics
		PROJECTILES.addBullet(b);
		lastBullet = BULLET_COOL_DOWN;
	}
}

void Player::fireMissile()
{
	if (lastMissile <= 0 && missileAmmo > 0)
	{
		//create missile with velocity, position, and target
		Missile m = Missile(position, OT_PLAYER_MISSILE);
		//m.init(1, 1); need to find out what to use for IDs from graphics
		PROJECTILES.addMissile(m);
		--missileAmmo;
		lastMissile = MISSILE_COOL_DOWN;
	}
}

void Player::heal(int h)
{
	//set to minimum of (health + h) and maxHealth without branching
	int newHealth = nHealth + h;
	nHealth = maxHealth + ((newHealth - maxHealth) & ((newHealth - maxHealth) >> 31));
}

void Player::hurt(int h)
{
	if (invulnerable <= 0.f)//only if player isn't invulnerable
	{
		nHealth -= h;//set health
		//see if dead
		if (nHealth <= 0)
		{
			endGame();
		}
		//set invulnerability when hit again
		invulnerable = HURT_INVULNERABILITY;
	}
}

void Player::move(D3DXVECTOR3 move)
{
	//rather than set position, we set velocity so that physics can check for collisions
	//before they are moved
	D3DXVec3Normalize(&velocity, &move);
}

void Player::endGame()
{
	//end game
	bEnabled = false;
}

void Player::update(const float dt)
{
	if (invulnerable > 0.f)
		invulnerable -= dt;
	if (lastBullet > 0.f)
		lastBullet -= dt;
	if(lastMissile > 0.f)
		lastMissile -= dt;
}

void Player::shutdown()
{
	missileAmmo = score = 0; 
	nHealth = maxHealth = 25; 
	invulnerable = lastBullet = lastMissile = 0.f;
}
