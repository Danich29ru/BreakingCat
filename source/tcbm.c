#include"tcbm.h"
#include"texture.h"

void tcbmConvertToTexture(char* _tcbmSource, Texture _texture, const unsigned char _tcbmWidth, const unsigned char _tcbmHeight)
{
	unsigned int size = _tcbmWidth * _tcbmHeight;
	char* textureData = (char*)LocalAlloc(LPTR, size * 4);
	unsigned int i = 0;
	unsigned char j = 0;
	unsigned int k = 0;
	

	for (i = 0; i < size; i++)
	{
		char byte = ((*_tcbmSource) >> j) & 0x01;

		if (byte == 0x01)
		{
			textureData[k] = 0xFF;
			textureData[k + 1] = 0xFF;
			textureData[k + 2] = 0xFF;
			textureData[k + 3] = 0xFF;
		}
		else
		{
			textureData[k] = 0x00;
			textureData[k + 1] = 0x00;
			textureData[k + 2] = 0x00;
			textureData[k + 3] = 0x00;
		}

		k += 4;
		j++;
		if (j == 8)
		{
			_tcbmSource++;
			j = 0;
		}
	}

	SetTextureData(_texture, _tcbmWidth, _tcbmHeight, textureData);

	LocalFree(textureData);
}

extern void tcbmConvertToTextureEx(char* _tcbmSource, unsigned int _texture, const unsigned char _tcbmWidth, const unsigned char _tcbmHeight, const unsigned int _color)
{
	unsigned int size = _tcbmWidth * _tcbmHeight;
	char* textureData = (char*)LocalAlloc(LPTR, size * 4);
	unsigned int i = 0;
	unsigned char j = 0;
	unsigned int k = 0;


	for (i = 0; i < size; i++)
	{
		char byte = ((*_tcbmSource) >> j) & 0x01;

		if (byte == 0x01)
		{
			textureData[k] = (_color >> 24) & 0x000000FF;
			textureData[k + 1] = (_color >> 16) & 0x000000FF;
			textureData[k + 2] = (_color >> 8) & 0x000000FF;
			textureData[k + 3] = _color & 0x000000FF;
		}
		else
		{
			textureData[k] = 0x00;
			textureData[k + 1] = 0x00;
			textureData[k + 2] = 0x00;
			textureData[k + 3] = 0x00;
		}

		k += 4;
		j++;
		if (j == 8)
		{
			_tcbmSource++;
			j = 0;
		}
	}

	SetTextureData(_texture, _tcbmWidth, _tcbmHeight, textureData);

	LocalFree(textureData);
}