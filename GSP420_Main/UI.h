#pragma once
#include "GameState.h"

class UI
{
public:
	UI() {}
	~UI() {}
	void init() {}
	//UI will either have separate methods for us to call in each game state, or one method
	//that takes the state and paused status, for now we will use this as a placeholder
	void update(const float, const GAMESTATE, const bool = false) {}
	GAMESTATE checkStateChanges(){ return STATE_MENU; }
	void render() {}
	void onLostDevice() {}
	void onResetDevice() {}
	void shutdown() {}
};

