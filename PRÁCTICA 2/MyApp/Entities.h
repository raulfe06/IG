//#pragma once
#ifndef _H_Entities_H_
#define _H_Entities_H_

#include <GL/freeglut.h>
#include <glm.hpp>
#include "Mesh.h"
#include "Texture.h"
#include "Material.h"

//-------------------------------------------------------------------------

class Entity 
{
public:
  Entity() : modelMat(1.0) { };
  virtual ~Entity() { delete mesh; };

  virtual void render(glm::dmat4 const& modelViewMat);
  void setModelMat(glm::dmat4 const& mMat) { modelMat = mMat; }
  void setMaterial(Material const& mt) { material = mt; }
  void setTexture(Texture const& tex) { texture = tex; };
  Material* getMaterial() { return &material; };

  
protected:
  Mesh* mesh = nullptr;
  Mesh* mesh2 = nullptr;
  glm::dmat4 modelMat;
  Texture texture;
  Material material;
  virtual void draw();	
  virtual void setMvM(glm::dmat4 const& modelViewMat);

 
};

//-------------------------------------------------------------------------

class EjesRGB : public Entity 
{
public:
  EjesRGB(GLdouble l);
  ~EjesRGB() { };
  virtual void draw();
};

//-------------------------------------------------------------------------
class Triangulo : public Entity
{
public:
	Triangulo(GLdouble r);
	virtual void draw();
};

class TrianguloRGB : public Entity
{
public:
	TrianguloRGB(GLdouble r);
	virtual void draw();
};
class TriPyramid : public Entity
{
public:
	TriPyramid(GLdouble r, GLdouble h);
	virtual void draw();
};
class ContCubo : public Entity
{
public:
	ContCubo(GLdouble l);
	virtual void draw();
};

class Dragon : public Entity
{
public:
	Dragon(GLuint numVert);
	virtual void draw();
};
class Diabolo : public Entity
{
public:
	Diabolo();
	virtual void draw();
	void render(glm::dmat4 const& modelViewMat);
	void setAngle(int a) { angle_ = a; };
private:
	double angle_ = 0;
};
class Cubo : public Entity
{
public:
	Cubo(GLdouble w, GLdouble h);
	void render(glm::dmat4 const& modelViewMat);
};
class Poliespiral : public Entity
{
public:
	Poliespiral(glm::dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert);
	virtual void draw();
};
class RectangleTex : public Entity
{
public:
	RectangleTex(GLdouble w, GLdouble h);
	virtual void draw();
};
class CuboTex : public Entity
{
public:
	CuboTex(GLdouble w,GLdouble h);
	void render(glm::dmat4 const& modelViewMat);
	Texture texture2;
};
class PyramideTex : public Entity
{
public:
	PyramideTex(GLdouble r,GLdouble h);
	virtual void draw();
};
class DiaboloTex : public Entity
{
public:
	DiaboloTex();
	void render(glm::dmat4 const& modelViewMat);
	virtual void draw();
	//void setAngle(int a) { angle_ = a; };
	void rotateDiabolo(double angle);
private:
	double angle_;
};
class Suelo : public Entity
{
public:
	Suelo();
	//void render(glm::dmat4 const& modelViewMat);
	virtual void draw();
};
class GlassPot : public Entity
{
public:
	GlassPot(GLdouble l);
	//void render(glm::dmat4 const& modelViewMat);
	virtual void draw();
};
class Grass : public Entity
{
public:
	Grass(GLdouble l);
	void render(glm::dmat4 const& modelViewMat);
	virtual void draw();
};
class Foto : public Entity
{
public:
	Foto(GLdouble w, GLdouble h);
	virtual void draw();
};
class Esfera : public Entity
{
public:
	Esfera(GLdouble radius, GLint slices, GLint stacks,int i );
	~Esfera();
	GLUquadricObj* esfera;
	virtual void draw();
};
#endif //_H_Entities_H_