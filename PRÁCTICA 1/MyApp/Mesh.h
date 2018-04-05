//#pragma once
#ifndef _H_Mesh_H_
#define _H_Mesh_H_

#include <GL/freeglut.h>
#include <glm.hpp>

//-------------------------------------------------------------------------

class Mesh 
{
public:
  static Mesh* generateAxesRGB(GLdouble l);
 
  Mesh(void) { };
  ~Mesh(void);
  virtual void draw();
  glm::dvec3* getVertices() { return vertices; };
  glm::dvec4* getColours() { return colors; };
  static Mesh* generateTriangle(GLdouble r);
  static Mesh* generateTriangleRGB(GLdouble r);
  static Mesh* generateTriPyramid(GLdouble r, GLdouble h);
  static Mesh* generateContCubo(GLdouble l);
  static Mesh* generaDragon(GLuint numVert);
  static Mesh* generateRectangle(GLdouble w, GLdouble h);
  static Mesh* generaPoliespiral(glm::dvec2 verIni, GLdouble angIni, GLdouble
	  incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert);

  static glm::dvec3 mover(GLdouble x, GLdouble y, GLdouble ang, GLdouble lon);

  static Mesh* generateRectangleTex(GLdouble w, GLdouble h, bool repeating, double repeatingNumber);
  static Mesh* generateCuboTex(GLdouble l);
  static Mesh* generatePyramidTex(GLdouble r,GLdouble h);



 



protected:
   GLuint numVertices = 0;
   GLuint type = GL_POINTS;
   glm::dvec3* vertices = nullptr;
   glm::dvec4* colors = nullptr;
   glm::dvec2 * texCoords = nullptr;
};

//-------------------------------------------------------------------------

#endif //_H_Scene_H_