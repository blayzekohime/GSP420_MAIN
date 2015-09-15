#pragma once

#include <Windows.h>
#include "ABC.h"

class Graphics
{
public:
	Graphics();
	~Graphics();
	void init() {}
	void update(const float) {}
	void render() {}
	void onLostDevice() {}
	void onResetDevice() {}
	void shutdown() {}

	inline IDirect3DDevice9* GetDevice() { return D3DDevice; }
	inline HINSTANCE GetAppInst() { return AppInst; }
	inline HWND GetMainWnd() { return MainWnd; }
	
private:
	HINSTANCE			AppInst;
	HWND				MainWnd;
	IDirect3DDevice9*	D3DDevice;

};

