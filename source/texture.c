#include"texture.h"

Texture bcCreateTexture()
{
	GLuint texture = 0;
	glGenTextures(1, &texture);
	return texture;
}


void bcDeleteTexture(Texture* _texture)
{
	glDeleteTextures(1, _texture);
	(*_texture) = 0;
}


void bcSetTextureData(Texture _texture, unsigned int _width, unsigned int _height, unsigned char* _data)
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


void bcDrawTexture(Texture _texture, unsigned int _x, unsigned int _y, unsigned int _width, unsigned int _height)
{
	double x, y, w, h;

	glBindTexture(GL_TEXTURE_2D, _texture);

	x = _x;
	y = _y;
	w = _width;
	h = _height;

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