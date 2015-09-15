#include "App.h"

#include <Windows.h>

#include "Logger.h"


void App::Run()
{
	//initialize timing
	__int64 cntsPerSec = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*)& cntsPerSec);
	float secsPerCnt = 1.f / (float)cntsPerSec;
	__int64 prevTimeStamp = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)& prevTimeStamp);
	//loop until it's time to quit
	init();
	while (!QuitNow)
	{
		if (!IsDeviceLost())
		{
			__int64 currTimeStamp = 0;
			QueryPerformanceCounter((LARGE_INTEGER*)&currTimeStamp);
			float dt = (currTimeStamp - prevTimeStamp)*secsPerCnt;

			update(dt);
			render();
			//current time stamp becomes the previous time stamp for the next iteration.
			prevTimeStamp = currTimeStamp;
		}
	}
	shutdown();
}

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
