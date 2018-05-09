#include "Material.h"



Material::Material()
{
}

Material::Material(glm::fvec4 ambient_, glm::fvec4 diffuse_, glm::fvec4 specular_, GLfloat expF_) : ambient(ambient_),
diffuse(diffuse_),specular(specular_),expF(expF_)
{
}


Material::~Material()
{
}

void Material::load()
{
	glMaterialfv(face, GL_AMBIENT, value_ptr(ambient));
	glMaterialfv(face, GL_SPECULAR, value_ptr(specular));
	glMaterialfv(face, GL_DIFFUSE, value_ptr(diffuse));
	glMaterialf(face, GL_SHININESS, expF);
	//glMaterialfv(face, GL_EMISSION, GLUT_RGBA);
	
	glShadeModel(sh);
}

void Material::setGold()
{
	ambient = { 0.24725,0.1995,0.0745,1.0 };
	diffuse = { 0.75164,0.60648,0.22648,1.0 };
	specular = { 0.628281,0.555802,0.366065,1.0 };
	expF = 51.2;
}

void Material::setSilver()
{
	ambient = { 0.199225,0.199225,0.199225,1.0 };
	diffuse = { 0.50754,0.50754,0.50754,1.0 };
	specular = { 0.508273,0.508273,0.508273,1.0 };
	expF = 51.2;
}

