#include"map.h"
#include"maptextures.h"



bcMapCell g_Cells[100];

void bcMapLoadTextures()
{
	g_MapTextures[BC_MAP_CELL_BACKGROUND] = bcCreateTexture();
	bcTCBMConvertToTexture(BC_MAP_CELL_BACKGROUND_Data, g_MapTextures[BC_MAP_CELL_BACKGROUND], 1, 1, 0x00770000, 0x00660000);
	g_MapTextures[BC_MAP_LAB] = bcCreateTexture();
	bcTCBMConvertToTexture(BC_MAP_LAB_Data, g_MapTextures[BC_MAP_LAB], 16, 16, 0x44FF4400, 0x000000FF);
}


void bcMapFreeTextures()
{
	bcDeleteTexture(&(g_MapTextures[BC_MAP_LAB]));
	bcDeleteTexture(&(g_MapTextures[BC_MAP_CELL_BACKGROUND]));
}


void bcMapInitialize()
{
	bcMapLoadTextures();
}


void bcMapShutdown()
{
	bcMapFreeTextures();
}


void bcMapDraw()
{
	int i = 0;

	

	for (i = 0; i < 10; i++)
	{
		int j = 0;

		for (j = 0; j < 10; j++)
		{
			unsigned int x, y;

			if (g_Cells[j*i + j]._type == 0)
			{
				continue;
			}

			x = j * TILE_SIZE + X_OFFSET;
			y = i * TILE_SIZE + Y_OFFSET;

			bcDrawTexture(g_MapTextures[g_Cells[j*i + j]._type], x + 1, y + 1, TILE_SIZE - 1, TILE_SIZE - 1);
		}
	}
}


void bcMapGetCell(const unsigned char _x, const unsigned char _y, bcMapCell* _object)
{
	(*_object) = g_Cells[_y * _x + _x];
}


void bcMapSetCell(const unsigned char _x, const unsigned char _y, bcMapCell _object)
{
	g_Cells[_y * _x + _x] = _object;
}