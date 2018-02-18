#include "Entities.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;

//-------------------------------------------------------------------------

void Entity::render(dmat4 const& modelViewMat) 
{ 
	setMvM(modelViewMat); 
	draw(); 
}
//-------------------------------------------------------------------------

void Entity::draw() 
{ 
  if (mesh != nullptr) 
    mesh -> draw(); 
}
//-------------------------------------------------------------------------

void Entity::setMvM(dmat4 const& modelViewMat)
{
	glMatrixMode(GL_MODELVIEW);
	dmat4 aMat = modelViewMat * modelMat;
	glLoadMatrixd(value_ptr(aMat));
}
//-------------------------------------------------------------------------

EjesRGB::EjesRGB(GLdouble l): Entity() 
{
  mesh = Mesh::generateAxesRGB(l);
}
//-------------------------------------------------------------------------
Triangulo::Triangulo(GLdouble r) : Entity()
{
	mesh = Mesh::generateTriangle(r);
}
TrianguloRGB::TrianguloRGB(GLdouble r) : Entity(){
	mesh = Mesh::generateTriangleRGB(r);
}
TriPyramid::TriPyramid(GLdouble r,GLdouble h) : Entity(){
	mesh = Mesh::generateTriPyramid(r, h);
}

//-------------------------------------------------------------------------
void Triangulo::draw()
{
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(2);
	mesh->draw();
	glLineWidth(1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void TrianguloRGB::draw(){

	mesh->draw();
}
//-------------------------------------------------------------------------
 
void TriPyramid::draw(){

	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(2);
	mesh->draw();
	glLineWidth(1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
//-------------------------------------------------------------------------


void EjesRGB::draw()
{
  glLineWidth(2);
  mesh->draw();
  glLineWidth(1);
}
//-------------------------------------------------------------------------

ContCubo::ContCubo(GLdouble l) : Entity()
{
	mesh = Mesh::generateContCubo(l);
}

void ContCubo::draw()
{
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(2);
	mesh->draw();
	glLineWidth(1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

Dragon::Dragon(GLuint numVert)
{
	mesh = Mesh::generaDragon(numVert);
}

void Dragon::draw()
{
	glColor3f(0.0, 0.0, 0.0);

	glPointSize(2);
	mesh->draw();
	glPointSize(1);

}
