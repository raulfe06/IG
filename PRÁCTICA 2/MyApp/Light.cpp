#include "Light.h"

GLuint Light::cont = 0;

Light::Light()
{
	if (cont < GL_MAX_LIGHTS) {
		id = GL_LIGHT0 + cont;
		++cont;
		glEnable(id);
	}
}


Light::~Light()
{
	disable();
}

void Light::disable()
{
	if (id < GL_LIGHT0 + GL_MAX_LIGHTS) {
		glDisable(id);
	}
}

void Light::enable()
{
	if (id < GL_LIGHT0 + GL_MAX_LIGHTS) { 
		glEnable(id);
	}
}

void Light::load()
{
	glLightfv(id, GL_AMBIENT, value_ptr(ambient));
	glLightfv(id, GL_DIFFUSE, value_ptr(diffuse));
	glLightfv(id, GL_SPECULAR, value_ptr(specular));


}

void Light::setAmb(glm::fvec4 amb)
{
}
