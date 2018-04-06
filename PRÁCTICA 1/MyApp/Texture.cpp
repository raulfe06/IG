#include "Texture.h"
#include "Pixmap32RGBA.h"


void Texture::init() {
	glGenTextures(1, &id); // genera un identificador para una nueva textura
	glBindTexture(GL_TEXTURE_2D, id); // Filters and clamping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}
void Texture::bind() { // argumento para el modo de mezclar los colores
	glBindTexture(GL_TEXTURE_2D, id); // activa la textura
									  // la función de mezcla de colores no queda guardada en el objeto
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	// GL_MODULATE / GL_ADD …
}
void Texture::loadColorBuffer(GLsizei width, GLsizei height)
{
	glReadBuffer(GL_FRONT);

	//glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
	//	0, 0, width, height, 0);
	glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, width, height, 0);


}
void Texture::save(const std::string & BMP_Name)
{
	
	PixMap32RGBA data;
	data.create_pixmap(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, data.data()); //Es unsigned byte porque el rgba del pixmap es unsignedbyte
	data.save_bmp24BGR(BMP_Name);
}
bool Texture::load(const std::string & BMP_Name, glm::ivec3 color, GLubyte alpha)
{
	PixMap32RGBA::rgba_color auxColor = { color.r,color.g,color.b,0 };
	if (id == 0) init();
	PixMap32RGBA pixMap; // var. local para cargar la imagen del archivo
	pixMap.load_bmp24BGR(BMP_Name); // carga y añade alpha=255
									// carga correcta?
	if (alpha != 255) pixMap.set_colorkey_alpha(auxColor,alpha);
	w = pixMap.width();
	h = pixMap.height();
	glBindTexture(GL_TEXTURE_2D, id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, pixMap.data());
	// transferir a openGL
	return true;
}
bool Texture::load(const std::string & BMP_Name, GLubyte alpha) {
	if (id == 0) init();
	PixMap32RGBA pixMap; // var. local para cargar la imagen del archivo
	pixMap.load_bmp24BGR(BMP_Name); // carga y añade alpha=255
									// carga correcta?
	if (alpha != 255) pixMap.set_alpha(alpha);
	w = pixMap.width();
	h = pixMap.height();
	glBindTexture(GL_TEXTURE_2D, id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, pixMap.data());
	// transferir a openGL
	return true;
}
