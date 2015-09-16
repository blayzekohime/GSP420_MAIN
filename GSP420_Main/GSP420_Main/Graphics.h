#pragma once

#include <Windows.h>

//d3d includes and libraries
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")

class Graphics
{
public:
	Graphics() {}
	~Graphics() {}
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

