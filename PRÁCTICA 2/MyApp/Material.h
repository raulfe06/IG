#pragma once
#include <GL/freeglut.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>

class Material
{

public:
	virtual void load();
	void setGold();
	void setSilver();
	void setBronze();
	Material();
	Material(glm::fvec4 ambient_, glm::fvec4 diffuse_, glm::fvec4 specular_, GLfloat expF_);

	~Material();
protected:
	/*...*/
	glm::fvec4 ambient, diffuse, specular; // coeficientes de reflexi�n
	GLfloat expF; // exponente especular
	GLuint face = GL_FRONT_AND_BACK; // ambos lados
	GLuint sh = GL_SMOOTH; // smooth shading
};

