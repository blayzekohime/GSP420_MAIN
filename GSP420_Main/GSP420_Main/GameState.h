#pragma once

enum GAMESTATE { STATE_INIT, STATE_MENU, STATE_CREDIT, STATE_PLAY, STATE_PAUSE, STATE_EXIT };

class GameState
{
public:
	GameState() {}
	~GameState() {}
};

class InitState : public GameState
{
public:
	InitState() {}
	~InitState() {}
};

class MenuState : public GameState
{
public:
	MenuState() {}
	~MenuState() {}
};

class CreditsState : public GameState
{
public:
	CreditsState() {}
	~CreditsState() {}
};

class PauseState : public GameState
{
public:
	PauseState() {}
	~PauseState() {}
};

class ExitState : public GameState
{
public:
	ExitState() {}
	~ExitState() {}
};