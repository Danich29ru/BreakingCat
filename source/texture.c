#include"texture.h"

Texture CreateTexture()
{
	GLuint texture = 0;
	glGenTextures(1, &texture);
	return texture;
}


void DeleteTexture(Texture* _texture)
{
	glDeleteTextures(1, _texture);
	(*_texture) = 0;
}


void SetTextureData(Texture _texture, unsigned char _width, unsigned char _height, unsigned char* _data)
{
	if(_texture == 0)
		return;

	glBindTexture(GL_TEXTURE_2D, _texture);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _data);
}


void DrawTexture(Texture _texture, unsigned int _x, unsigned int _y, unsigned char _width, unsigned char _height, unsigned char _pixelsize)
{
	double x, y, w, h;

	glBindTexture(GL_TEXTURE_2D, _texture);

	x = (double)_x / (double)WINDOW_WIDTH;
	y = (double)_y / (double)WINDOW_HEIGHT;
	w = ((double)_width * (double)_pixelsize) / (double)WINDOW_WIDTH;
	h = ((double)_height * (double)_pixelsize) / (double)WINDOW_HEIGHT;

	glBegin(GL_QUADS);
	glTexCoord2d(1.0, 0.0);
	glVertex2d(x, y);
	glTexCoord2d(1.0, 1.0);
	glVertex2d(x, y + h);
	glTexCoord2d(0.0, 1.0);
	glVertex2d(x + w, y + h);
	glTexCoord2d(0.0, 0.0);
	glVertex2d(x + w, y);
	glEnd();
}