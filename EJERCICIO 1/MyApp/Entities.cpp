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
	/*modelMat = translate(modelMat, dvec3(200, 200, 0));
	modelMat = rotate(modelMat,radians(45.0),dvec3(0.0,0.0,1.0));
	modelMat = scale(modelMat, dvec3(1.5, 1.5, 1));*/
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

Diabolo::Diabolo() : Entity()
{
	mesh = Mesh::generateTriPyramid(200.0, 500.0);
}

void Diabolo::draw()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(2);
	mesh->draw();
	glLineWidth(1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Diabolo::render(glm::dmat4 const & modelViewMat)
{
	modelMat = rotate(modelMat, radians(angle_), dvec3(0.0, 0.0, 1.0));
	glMatrixMode(GL_MODELVIEW);
	
	dmat4 aMat = modelViewMat * modelMat;
	
	aMat = translate(aMat, dvec3(0, 0, -500.0));

	glLoadMatrixd(value_ptr(aMat));
	
	glColor3f(0, 0.0, 1);
	draw();

	aMat = rotate(aMat, radians(180.0), dvec3(0, 0, 1));
	glLoadMatrixd(value_ptr(aMat));

	glColor3f(0, 1, 0);
	draw();

	
	aMat = rotate(aMat, radians(180.0), dvec3(1, 0, 0));
	aMat = translate(aMat, dvec3(0.0, 0.0, -1000.0));
	glLoadMatrixd(value_ptr(aMat));
	glColor3f(1, 0, 0);
	draw();
	
	aMat = rotate(aMat, radians(180.0), dvec3(0, 0, 1));
	glLoadMatrixd(value_ptr(aMat));
	glColor3f(0,0,0);
	draw();
	//aMat = modelViewMat * modelMat;


	
	
	
}
