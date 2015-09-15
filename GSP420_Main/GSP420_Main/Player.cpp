#include "Player.h"

#include "Graphics.h"


void Player::fireBullet()
{
	//create bullet with velocity and position

}

void Player::fireMissile()
{
	if (missileAmmo > 0)
	{
		//create missile with velocity, position, and target

		--missileAmmo;
	}
}

void Player::heal(int h)
{
	//set to minimum of (health + h) and maxHealth without branching
	nHealth = maxHealth + (((nHealth + h) - maxHealth) & (((nHealth + h) - maxHealth) >> 31));
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
	}
}

void Player::move(D3DXVECTOR3 move)
{
	position += move;
}

void Player::endGame()
{
	//end game

}

void Player::update(const float dt)
{
	//update movement and check for inputs
}


