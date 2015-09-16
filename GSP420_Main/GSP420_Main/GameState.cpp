#include "GameState.h"

#include "Game.h"

void InitState::init()
{
	LOGGER->open();
	INPUT->init(GAMECLASS->GameGraphics, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	//init graphics, audio, ui
}

void InitState::shutdown()
{
	//need to define because ChangeState automatically calls it, but don't actually need to do anything here
}

void MenuState::init()
{
	//load graphics textures needed for menu
}

void MenuState::update(const float dt)
{
	if (INPUT->KeyDown(DIK_ESCAPE))
	{
		GAMECLASS->changeState(STATE_EXIT);
	}
	//listen for input
	//call update for audio, ui
}

void MenuState::render()
{
	//call render for ui
}

void MenuState::onLostDevice()
{
	//call lost device for ui
}

void MenuState::onResetDevice()
{
	//call reset device for ui
}

void MenuState::shutdown()
{
	//unload graphics textures for menus
}

void CreditsState::init()
{
	//load graphics textures needed for credits screen
}

void CreditsState::update(const float dt)
{
	//listen for input
	//call update for ui, audio
}

void CreditsState::render()
{
	//call render for ui
}

void CreditsState::onLostDevice()
{
	//call lost device for ui
}

void CreditsState::onResetDevice()
{
	//call reset device for ui
}

void CreditsState::shutdown()
{
	//unload graphics textures for credit
}

void PlayState::init()
{
	//load model/texture resources
	//init player
	//init enemymanager, projectilemanager, asteroidmanager, pickupmanager
	//init graphics textures for ui and pause menu
}

void PlayState::update(const float dt)
{
	//listen for input
	//if unpaused
		//update player
		//update managers
		//update ui, ai, physics (as part of updating managers)
	//if paused
		//update ui/pause menu
}

void PlayState::render()
{
	//if unpaused
		//render player, managers, ui
	//if paused
		//render ui
}

void PlayState::onLostDevice()
{
	//call lost device for graphics/ui
}

void PlayState::onResetDevice()
{
	//call reset device for graphics/ui
}

void PlayState::shutdown()
{
	//unload models/textures for gameplay, ui, pause menu
}


void ExitState::init()
{
	LOGGER->close();
	INPUT->shutdown();
	//unload main graphics/ui/audio resources and then quit
}


