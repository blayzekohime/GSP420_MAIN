#include "Game.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Logger.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, int)
{
	srand((unsigned)time(NULL));
	Game::Instance()->Run();
	Game::Instance()->Delete();
	return 1;
}



//global initialization to facilitate singleton design pattern
Game* Game::Singleton = NULL;

//retrieve singleton instance
Game* Game::Instance()
{
	if (Singleton == 0)
		Singleton = new Game;
	return Singleton;
}

void Game::Delete()
{
	if (Singleton)
	{
		delete Singleton;
		Singleton = NULL;
	}
}

void Game::init()
{
	States[STATE_INIT] = InitState();
	States[STATE_MENU] = MenuState();
	States[STATE_CREDIT] = CreditsState();
	States[STATE_PLAY] = PlayState();
	States[STATE_EXIT] = ExitState();
	//will always start with the Init and then Menu states
	States[STATE_INIT].init();
	States[STATE_MENU].init();
}

void Game::onLostDevice()
{
	States[State].onLostDevice();
}

void Game::onResetDevice()
{
	States[State].onLostDevice();
}

void Game::update(const float dt)
{
	States[State].update(dt);
}

void Game::render()
{
	States[State].render();
}

void Game::shutdown()
{
	//will always end by exiting through the menu state
	States[STATE_MENU].shutdown();
	States[STATE_EXIT].shutdown();

}

void Game::changeState(GAMESTATE newstate)
{
	States[State].shutdown();
	State = newstate;
	States[State].init();
	paused = false;
}
