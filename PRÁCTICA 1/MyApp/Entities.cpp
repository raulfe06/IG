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

RectangleTex::RectangleTex(GLdouble w, GLdouble h)
{
	mesh = Mesh::generateRectangleTex(w, h,false,0);
	texture.load("..//Bmps//Zelda.bmp", 255);

}

void RectangleTex::draw()
{
	texture.bind();
	Entity::draw();
	texture.unbind();
}

CuboTex::CuboTex(GLdouble w, GLdouble h )
{
	texture.load("..//Bmps//container.bmp", 255);
	mesh2 = Mesh::generateCuboTex(300.0);
	mesh = Mesh::generateRectangleTex(w, h,false,1);
	texture2.load("..//Bmps//chuches.bmp", 255);
	modelMat = translate(modelMat, dvec3(-250, 150, 0));

}
void CuboTex::render(glm::dmat4 const & modelViewMat)
{
	glEnable(GL_CULL_FACE);

	dmat4 aMat = modelViewMat * modelMat;
	aMat = rotate(aMat, radians(-90.0), dvec3(1, 0, 0)); //Base
	aMat = translate(aMat, dvec3(0.0, 0.0, -150));
	glLoadMatrixd(value_ptr(aMat));

	glCullFace(GL_FRONT);
	//"Método draw de cada malla"
	texture.bind(); 
	mesh->draw(); // Base
	texture.unbind();

	glCullFace(GL_BACK);
	//"Método draw de cada malla"
	texture2.bind();
	mesh->draw(); // Base
	texture2.unbind();

	aMat = modelViewMat * modelMat;
	aMat = translate(aMat, dvec3(0.0, 255.0, -42.0)); //Tapa
	aMat = rotate(aMat, radians(45.0), dvec3(1, 0, 0));
	glLoadMatrixd(value_ptr(aMat));

	glCullFace(GL_FRONT);
	//"Método draw de cada malla"
	texture.bind();
	mesh->draw(); // Tapa
	texture.unbind();

	glCullFace(GL_BACK);
	//"Método draw de cada malla"
	texture2.bind();
	mesh->draw(); // Tapa
	texture2.unbind();


	aMat = modelViewMat * modelMat;
	glLoadMatrixd(value_ptr(aMat));

	glCullFace(GL_FRONT);
	//"Método draw de cada malla"
	texture.bind();
	mesh2->draw(); // Base
	texture.unbind();

	glCullFace(GL_BACK);
	//"Método draw de cada malla"
	texture2.bind();
	mesh2->draw(); // Base
	texture2.unbind();

	aMat = modelViewMat * modelMat;

	glDisable(GL_CULL_FACE);
}

PyramideTex::PyramideTex(GLdouble r, GLdouble h)
{
	mesh = Mesh::generatePyramidTex(r,h);
	texture.load("..//Bmps//container.bmp", 255);texture.bind();
	Entity::draw();
	texture.unbind();
}

void PyramideTex::draw()
{
	
}

DiaboloTex::DiaboloTex()
{
	mesh = Mesh::generatePyramidTex(100.0, 300.0);
	texture.load("..//Bmps//floris.bmp", 255);
	modelMat = translate(modelMat, dvec3(400, 200, 0));
}

void DiaboloTex::render(glm::dmat4 const & modelViewMat)
{
	

	glMatrixMode(GL_MODELVIEW);

	dmat4 aMat = modelViewMat * modelMat;

	aMat = translate(aMat, dvec3(0, 0, -300.0));

	glLoadMatrixd(value_ptr(aMat));

	draw();

	aMat = rotate(aMat, radians(180.0), dvec3(0, 0, 1));
	glLoadMatrixd(value_ptr(aMat));

	draw();


	aMat = rotate(aMat, radians(180.0), dvec3(1, 0, 0));
	aMat = translate(aMat, dvec3(0.0, 0.0, -600.0));
	glLoadMatrixd(value_ptr(aMat));
	draw();

	aMat = rotate(aMat, radians(180.0), dvec3(0, 0, 1));
	glLoadMatrixd(value_ptr(aMat));
	draw();
	aMat = modelViewMat * modelMat;
}

void DiaboloTex::draw()
{
	texture.bind();
	Entity::draw();
	texture.unbind();
}

void DiaboloTex::rotateDiabolo(double angle)
{
	
	modelMat = rotate(modelMat, radians(angle_+angle), dvec3(0.0, 0.0, 1.0));
}

Suelo::Suelo()
{
	mesh = Mesh::generateRectangleTex(1500.0, 1500.0,true,1500.0/225.0);
	texture.load("..//Bmps//baldosaC.bmp");
	modelMat = rotate(modelMat, radians(90.0), dvec3(1, 0, 0));
	modelMat = translate(modelMat, dvec3(0, -100, 0));
}

void Suelo::draw()
{
	texture.bind();
	Entity::draw();
	texture.unbind();
}

GlassPot::GlassPot(GLdouble l)
{
	texture.load("..//Bmps//window.bmp", 150);
	mesh = Mesh::generateCuboTex(l);
	modelMat = translate(modelMat, dvec3(0, 150, +305));
	
}

void GlassPot::draw()
{
	glDepthMask(GL_FALSE);
	texture.bind();
	Entity::draw();
	texture.unbind();
	glDepthMask(GL_TRUE);

}

Grass::Grass(GLdouble l)
{
	glm::ivec3 color = { 0.0,0.0,0.0 };
	texture.load("..//Bmps//grass.bmp",color,0);
	mesh = Mesh::generateRectangleTex(l,l,false,0);
	mesh2 = Mesh::generateRectangleTex(l, l, false, 0);


}

void Grass::render(glm::dmat4 const & modelViewMat)
{
	dmat4 aMat = modelViewMat * modelMat;
	aMat = translate(aMat, dvec3(0, 150, +305));
	aMat = rotate(aMat, radians(-45.0), dvec3(0.0, 1.0, 0.0));
	glLoadMatrixd(value_ptr(aMat));
	texture.bind();
	mesh->draw();
	texture.unbind();

	aMat = modelViewMat * modelMat;
	aMat = translate(aMat, dvec3(0, 150, +305));
	aMat = rotate(aMat, radians(45.0), dvec3(0.0, 1.0, 0.0));
	glLoadMatrixd(value_ptr(aMat));
	texture.bind();
	mesh2->draw();
	texture.unbind();

	aMat = modelViewMat * modelMat;

}

void Grass::draw()
{
	texture.bind();
	Entity::draw();
	texture.unbind();
}

Foto::Foto(GLdouble w, GLdouble h)
{
	mesh = Mesh::generateRectangleTex(w, h, false, 0);
	modelMat = translate(modelMat, dvec3(0.0, 1.0, 0.0));

	modelMat = rotate(modelMat, radians(90.0), dvec3(1.0, 0.0, 0.0));
	modelMat = rotate(modelMat, radians(90.0), dvec3(0.0, 0.0, 1.0));
	modelMat = rotate(modelMat, radians(180.0), dvec3(0.0, 1.0, 0.0));

	/*modelMat = rotate(modelMat, radians(180.0), dvec3(0.0, 0.0, 1.0));
	modelMat = rotate(modelMat, radians(180.0), dvec3(0.0, 1.0, 0.0));
	modelMat = rotate(modelMat, radians(90.0), dvec3(0.0, 0.0, 1.0));*/


	//modelMat = translate(modelMat, dvec3(0.0, 0.0, 1.0));

}

void Foto::draw()
{
	glReadBuffer(GL_FRONT);
	glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0);
	texture.updateImage(255);
	Entity::draw();

}
