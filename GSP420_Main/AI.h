#pragma once
using namespace std;
#include <list>
#include "EnemyManager.h"
class AI
{
public:
	AI(void);
	~AI(void);
	void init() {}
	void update(const float) {}
	void update(const float, std::list<Enemy>, std::list<GSP420::ABC>, GSP420::ABC);
	void shutdown() {}

	void enemy1Update(Enemy, GSP420::ABC);
	void enemy2Update(Enemy);
	void enemy3Update(Enemy);
	void enemyBossUpdate(Enemy);
	void playerMissUpdate(GSP420::ABC);
	void enemyMissUpdate(GSP420::ABC, GSP420::ABC);
};

