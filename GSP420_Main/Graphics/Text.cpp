#include "Text.h"

using namespace GFXCore;

int Text::nInternalFontId = -1;

Text::Text()
{
}


Text::~Text()
{
}

int Text::createFont(IDirect3DDevice9* device, const FontData& textInfo)
{
	FontData newFont;
	memset(&newFont, NULL, sizeof(FontData));
	newFont = textInfo;

	if (FAILED(D3DXCreateFont(device, newFont.nFontHeight, newFont.nFontWidth, FW_NORMAL, 0, newFont.bItalics, DEFAULT_CHARSET,
												OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
												newFont.strFontName, &(newFont.pFont))))
		return -1;

	fontList.push_back(newFont);

	return ++nInternalFontId;
}

void Text::render(const int fontId, const wchar_t* displayText)
{
	HR(fontList[fontId].pFont->DrawTextW(NULL, displayText, -1, &(fontList[fontId].textBoxDimens),
											DT_CENTER, fontList[fontId].textColor));
}

void Text::shutdown()
{
	for (unsigned int i = 0; i < fontList.size(); ++i) {
		if (fontList[i].pFont)
			ReleaseCom(fontList[i].pFont);
	}

	fontList.clear();
	fontList.resize(0);
}

void Text::init(const int startNumFonts /*= 5*/)
{
	fontList.resize(startNumFonts);
}
