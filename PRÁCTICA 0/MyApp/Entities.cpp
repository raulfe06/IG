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
	modelMat = translate(modelMat, dvec3(-40.0, -170.0, 0));
	modelMat = scale(modelMat, dvec3(40.0, 40.0, 0.0));
}

void Dragon::draw()
{
	glColor3f(0.0, 0.0, 1.0);
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
	aMat = modelViewMat * modelMat;


	
	
	
}

Cubo::Cubo(GLdouble w, GLdouble h)
{
	mesh = Mesh::generateRectangle(w, h);
	mesh2 = Mesh::generateContCubo(300.0);
}

void Cubo::render(glm::dmat4 const & modelViewMat)
{
	glColor3f(0, 0, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	dmat4 aMat = modelViewMat * modelMat;
	aMat = rotate(aMat, radians(-90.0), dvec3(1, 0, 0)); //Base
	aMat = translate(aMat, dvec3(0.0, 0.0, -150));
	glLoadMatrixd(value_ptr(aMat));
	mesh->draw(); // Base

	aMat = modelViewMat * modelMat;
	aMat = translate(aMat, dvec3(0.0, 255.0, -42.0)); //Tapa
	aMat = rotate(aMat, radians(45.0), dvec3(1, 0, 0));
	glLoadMatrixd(value_ptr(aMat));
	mesh->draw(); // Tapa

	aMat = modelViewMat * modelMat;
	glLoadMatrixd(value_ptr(aMat)); 
	mesh2->draw(); //Contorno del cubo
	aMat = modelViewMat * modelMat;
}

Poliespiral::Poliespiral(glm::dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert)
{
	mesh = Mesh::generaPoliespiral(verIni, angIni, incrAng, ladoIni, incrLado, numVert);
	modelMat = scale(modelMat, dvec3(10.0, 10.0, 0.0));
}

void Poliespiral::draw()
{
	glColor3f(0.95,0.65,0.25);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(2);
	mesh->draw();
	glLineWidth(1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
