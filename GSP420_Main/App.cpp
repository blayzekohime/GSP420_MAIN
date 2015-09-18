#include "App.h"

#include <Windows.h>

#include "Logger.h"



bool App::IsDeviceLost()
{
	// Get the state of the graphics device.
/*		HRESULT hr = GameGraphics.GetDevice()->TestCooperativeLevel();

	// If the device is lost and cannot be reset yet then
	// sleep for a bit and we'll try again on the next
	// message loop cycle.
	if (hr == D3DERR_DEVICELOST)
	{
		Sleep(20);
		return true;
	}
	// Driver error, exit.
	else if (hr == D3DERR_DRIVERINTERNALERROR)
		Logger::Instance()->Write(L"Internal Driver Error.", true);

	// The device is lost but we can reset and restore it.
	else if (hr == D3DERR_DEVICENOTRESET)
	{
		onLostDevice();
		GameGraphics.onResetDevice();
		onResetDevice();
		return false;
	}*/
	return false;
}
