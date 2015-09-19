#include "GFX.h"

using namespace GFXCore;

Graphics* Graphics::pInstance = NULL;
Text Graphics::words;

void GFXCore::Graphics::shutdown()
{
	d3d()->shutdown();
	modls.shutdown();
	words.shutdown();
	del();
}

void GFXCore::Graphics::initLists(const int numStartTexs /*= 20*/, const int numStartModels /*= 10*/, const int numStartFonts /*= 5*/)
{
	texs.init(numStartTexs);
	modls.init(numStartModels);
	words.init(numStartFonts);
}

int GFXCore::Graphics::loadFont(const FontData& fontData)
{
	return words.createFont(d3d()->getDevice(), fontData);
}
