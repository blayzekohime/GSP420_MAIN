#include "App.h"

#include <Windows.h>

#include "Logger.h"
#include "Graphics/GFX.h"



bool App::IsDeviceLost()
{
	// Get the state of the graphics device.
	if (GFXCore::D3DCore::get()->isDeviceLost())
	{
		onLostDevice();
		onResetDevice();
		return true;
	}
	return false;
}
