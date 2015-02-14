﻿#include"font.h"
#include"symbols.h"
#include"common.h"

#define COUNT_OF_SYMBOLS 57

typedef struct tagBCFONT
{
	Texture _textures[COUNT_OF_SYMBOLS];
}bcFontRU;

static bcFontRU g_Fonts[32];
static unsigned char g_CountOfFonts = 0;

Font bcCreateFont(const unsigned int _color)
{
	int i = 0;

	if (g_CountOfFonts >= 31)
		return 0;

	for (i = 0; i < COUNT_OF_SYMBOLS; i++)
	{
		g_Fonts[g_CountOfFonts]._textures[i] = CreateTexture();
		tcbmConvertToTexture(GetSymbol(i), g_Fonts[g_CountOfFonts]._textures[i], SYMBOL_WIDTH, SYMBOL_HEIGHT);
	}

	return (g_CountOfFonts);
}


void bcDeleteFont(Font* _font)
{
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		DeleteTexture(&(g_Fonts[(*_font)]._textures[i]));
	}

	(*_font) = 0;
}


void bcDrawText(Font _font, wchar_t* _text, const unsigned char _pixelScale, Rect _rc)
{
	unsigned int lenght = lstrlenW(_text);
	unsigned int charSize = (_pixelScale * 8) + 1;
	unsigned int freeSpaceX = _rc._left - _rc._right;
	unsigned int freeSpaceY = _rc._top - _rc._bottom;
	unsigned int row = 0;
	unsigned char charID = 0;
	unsigned int i = 0;

	CharLowerW(_text);

	for (i = 0; i < lenght; i++)
	{
		unsigned int x;
		unsigned int y;

		if (freeSpaceX >= charSize)
		{
			x = (_rc._left + ((_rc._left - _rc._right) - freeSpaceX));
			freeSpaceX -= charSize;
		}
		else
		{
			freeSpaceX = (_rc._left - _rc._right);
			freeSpaceY -= charSize;
			row++;
		}

		if (freeSpaceY >= charSize)
		{
			y = (_rc._top + ((_rc._top - _rc._bottom) - freeSpaceY)) + (row * charSize);
		}
		else
		{
			break;
		}

		
		if (_text[i] > 1071)
			charID = _text[i] - 1072;

		if (_text[i] == L' ')
			charID = 32;

		if (_text[i] == L'!')
			charID = 33;

		if (_text[i] == L',')
			charID = 34;

		if (_text[i] == L'?')
			charID = 35;

		if (_text[i] == L'#')
			charID = 36;

		if (_text[i] == L'\'')
			charID = 37;

		if (_text[i] == L'(')
			charID = 38;

		if (_text[i] == L')')
			charID = 39;

		if (_text[i] == L'[')
			charID = 40;

		if (_text[i] == L']')
			charID = 41;

		if (_text[i] == L'+')
			charID = 42;

		if (_text[i] == L'-')
			charID = 43;

		if (_text[i] == L'=')
			charID = 44;

		if (_text[i] == L'_')
			charID = 45;

		if (_text[i] == L'.')
			charID = 46;

		if (_text[i] >= L'0' && _text[i] <= L'9')
		{
			charID = (_text[i] - L'0') + 47;
		}

		DrawTexture(g_Fonts[_font]._textures[charID], x, y, SYMBOL_WIDTH, SYMBOL_HEIGHT, _pixelScale);

	}
}