#include"common.h"
#include"map.h"

#define TILE_SIZE ((WINDOW_HEIGHT - UIBAR_SIZE) / 10)

#define X_OFFSET (WINDOW_WIDTH / 2 - (TILE_SIZE * 5))
#define Y_OFFSET 0

void bcInitMap()
{
	unsigned char textureBackgroudData[] = 
	{ 
		0x00, 0x55, 0x00, 0x00
	};

	unsigned char textureLab1[] = 
	{
		0xFF, 0xFF, 0x01, 0x80, 0xE1, 0x87,
		0xC1, 0x83, 0xC1, 0x83, 0xC1, 0x83,
		0xC1, 0x83, 0xC1, 0x83, 0xE1, 0x87,
		0xF1, 0x8F, 0xF9, 0x9F, 0xFD, 0xBF,
		0xFD, 0xBF, 0xF9, 0x9F, 0x01, 0x80,
		0xFF, 0xFF,
	};

	unsigned char textureGreenQuad[] = 
	{
		0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7E,
	};

	bcMapObject greenQuad;

	int i = 0;

	g_MapTextures[BC_MAP_TEXTURE_BACKGROUND] = bcCreateTexture();
	bcSetTextureData(g_MapTextures[BC_MAP_TEXTURE_BACKGROUND], 1, 1, textureBackgroudData);

	g_MapTextures[BC_MAP_TEXTURE_LAB1] = bcCreateTexture();
	bcTCBMConvertToTexture(textureLab1, g_MapTextures[BC_MAP_TEXTURE_LAB1], 16, 16, 0x44FF4400, 0x000000FF);

	g_MapTextures[BC_MAP_TEXTURE_GREEN_QUAD] = bcCreateTexture();
	bcTCBMConvertToTexture(textureGreenQuad, g_MapTextures[BC_MAP_TEXTURE_GREEN_QUAD], 8, 8, 0x00770000, 0x00660000);

	greenQuad._type = BC_MAP_TEXTURE_GREEN_QUAD;
	
	for (i = 0; i < 10; i++)
	{
		int j = 0;
		greenQuad._x = i;
		
		for (j = 0; j < 10; j++)
		{
			greenQuad._y = j;
			bcAddObjectMap(greenQuad);
		}
	}
}


void bcDrawMap()
{
	int i = 0;
	bcDrawTexture(g_MapTextures[BC_MAP_TEXTURE_BACKGROUND], 0, 0, 800, 600);

	while (g_MapObjects[i]._type != 0 && i < MAP_MAX_OBJECTS)
	{
		unsigned int x, y;

		x = g_MapObjects[i]._x * TILE_SIZE + X_OFFSET;
		y = g_MapObjects[i]._y * TILE_SIZE + Y_OFFSET;

		bcDrawTexture(g_MapTextures[g_MapObjects[i]._type], x + 1, y + 1, TILE_SIZE - 1, TILE_SIZE - 1);
		i++;
	}
}


void bcFreeMap()
{
	bcDeleteTexture(&(g_MapTextures[BC_MAP_TEXTURE_BACKGROUND]));
	bcDeleteTexture(&(g_MapTextures[BC_MAP_TEXTURE_GREEN_QUAD]));
	bcDeleteTexture(&(g_MapTextures[BC_MAP_TEXTURE_LAB1]));
}


void bcAddObjectMap(bcMapObject _object)
{
	int i = 0;

	while (i < MAP_MAX_OBJECTS)
	{
		if (g_MapObjects[i]._type == 0)
		{
			g_MapObjects[i]._type = _object._type;
			g_MapObjects[i]._x = _object._x;
			g_MapObjects[i]._y = _object._y;
			break;
		}
		i++;
	}
}