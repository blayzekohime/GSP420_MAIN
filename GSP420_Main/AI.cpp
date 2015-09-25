#include "AI.h"
//#include "Game.h"

AI::AI(void)
{
}


AI::~AI(void)
{
}

void AI::update(const float dt, std::list<Enemy> enemies, std::list<GSP420::ABC> projectiles, GSP420::ABC player)
{
	// Iterate through the list of enemies and updtae their AI based on their type
	std::list<Enemy>::iterator enemyIt = enemies.begin();
	while (enemyIt != enemies.end())
	{
		switch(enemyIt->getObjectType())
		{
		case OT_ENEMY1:
			{
				enemy1Update(*enemyIt, player);
			} break;
		case OT_ENEMY2:
			{
				enemy2Update(*enemyIt);
			} break;
		case OT_ENEMY3:
			{
				enemy3Update(*enemyIt);
			} break;
		case OT_ENEMYBOSS:
			{
				enemyBossUpdate(*enemyIt);
			} break;
		}

		enemyIt++;
	}

	// Iterate through the list of projectiles and updtae their AI based on their type
	std::list<GSP420::ABC>::iterator projectileIt = projectiles.begin();
	while (projectileIt != projectiles.end())
	{
		switch(projectileIt->getObjectType())
		{
		case OT_PLAYER_MISSILE:
			{
				playerMissUpdate(*projectileIt);
			} break;
		case OT_ENEMY_MISSILE:
			{
				enemyMissUpdate(*projectileIt, player);
			} break;
		}

		projectileIt++;
	}
}

/////// This enemy behavior seeks out the player ////////
/////// until they reach a set Y value at which  ////////
/////// point they simply fly straight.          ////////
void AI::enemy1Update(Enemy enemy, GSP420::ABC player)
{
	// Check if enemy Y position is higher than half the game height
	if (enemy.getPosition().y > 0.0f) // TODO: Modify for exact game height constant
	{
		D3DXVECTOR3 tempVel;
		tempVel = player.getPosition() - enemy.getPosition();
		D3DXVec3Normalize(&tempVel, &tempVel);
		// TODO: Multiply tempVel by enemy speed constant

		enemy.setVelocity(tempVel);
	}

	if (enemy.getBulletFireRate() == 0.0f)
		enemy.fireBullet(D3DXVECTOR3(0.0f, 5.0f, 0.0f)); // TODO: Modify for a fixed bullet speed constant
}

void AI::enemy2Update(Enemy enemy)
{

}

void AI::enemy3Update(Enemy enemy)
{

}

void AI::enemyBossUpdate(Enemy enemy)
{

}

void AI::playerMissUpdate(GSP420::ABC proj)
{

}

//////// Missile tracks player and follows them ////////
//////// Has a limited turning radius.          ////////
//////// Has a limited lifetime until it        ////////
//////// explodes								////////
void AI::enemyMissUpdate(GSP420::ABC proj, GSP420::ABC player)
{
	D3DXVECTOR3 currDir, newDir;
	// Get the missiles current direction from its velocity
	currDir = proj.getVelocity();
	D3DXVec3Normalize(&currDir, &currDir);

	// Get the missiles new direction according to player position
	newDir = player.getPosition() - proj.getPosition();
	D3DXVec3Normalize(&newDir, &newDir);

	// Find the angle between the two vectors
	float angle = D3DXVec3Dot(&currDir, &newDir);
	angle = acos(angle);

	// Re-use newDir vector for updating projectile velocity
	newDir = proj.getVelocity();

	// Check if angle is larger than our missile's turning radius
	// Then update the missiles velocity
	if (abs(angle) > 5.0f) // TODO: modify for a constant max turning radius value
	{
		if (angle > 0.0f)
		{
			newDir.x += 5.0f;
			proj.setVelocity(newDir);
		}
		else
		{
			newDir.x -= 5.0f;
			proj.setVelocity(newDir);
		}
	}
	else
	{
		if (angle > 0.0f)
		{
			newDir.x += angle;
			proj.setVelocity(newDir);
		}
		else
		{
			newDir.x -= angle;
			proj.setVelocity(newDir);
		}
	}

	// TODO: Modify orientation of projectile

	// TODO: Add check for missile lifetime to see if it has run out of time
}