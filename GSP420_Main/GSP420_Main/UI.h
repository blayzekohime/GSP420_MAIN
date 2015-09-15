#pragma once
class UI
{
public:
	UI();
	~UI();
	void init() {}
	void update(const float) {}
	void render() {}
	void onLostDevice() {}
	void onResetDevice() {}
	void shutdown() {}
};

