#include "Mesh.h"

using namespace glm;

//-------------------------------------------------------------------------

Mesh ::~Mesh(void) 
{
  delete[] vertices;
  delete[] colors;
}
//-------------------------------------------------------------------------

void Mesh::draw() 
{
  if (vertices != nullptr) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_DOUBLE, 0, vertices);  // number of coordinates per vertex, type of each coordinate 
    if (colors != nullptr) {
      glEnableClientState(GL_COLOR_ARRAY);
      glColorPointer(4, GL_DOUBLE, 0, colors);   // number of coordinates per color, type of each coordinate 
    }
	
    glDrawArrays(type, 0, numVertices);   // kind of primitives, first, count

	  glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
  }
}
//-------------------------------------------------------------------------

Mesh * Mesh::generateAxesRGB(GLdouble l)
{
  Mesh* m = new Mesh();
  m->type = GL_LINES;
  m->numVertices = 6;

  m->vertices = new dvec3[m->numVertices];
  m->vertices[0] = dvec3(0.0, 0.0, 0.0);   
  m->vertices[1] = dvec3(l, 0.0, 0);
  m->vertices[2] = dvec3(0, 0.0, 0.0);
  m->vertices[3] = dvec3(0.0, l, 0.0); 
  m->vertices[4] = dvec3(0.0, 0.0, 0.0);
  m->vertices[5] = dvec3(0.0, 0.0, l);

  m->colors = new dvec4[m->numVertices];
  m->colors[0] = dvec4(1.0, 0.0, 0.0, 1.0);
  m->colors[1] = dvec4(1.0, 0.0, 0.0, 1.0);
  m->colors[2] = dvec4(0.0, 1.0, 0.0, 1.0);
  m->colors[3] = dvec4(0.0, 1.0, 0.0, 1.0);
  m->colors[4] = dvec4(0.0, 0.0, 1.0, 1.0);
  m->colors[5] = dvec4(0.0, 0.0, 1.0, 1.0);
 
  return m; 
}
Mesh* Mesh::generateTriangle(GLdouble r){

	
	Mesh* m = new Mesh();
	m->type = GL_TRIANGLES;
	m->numVertices = 3;
	m->vertices = new dvec3[m->numVertices];
	m->vertices[0] = dvec3(r*cos(radians(0.0)), r*sin(radians(0.0)), 0.0);
	m->vertices[1] = dvec3(r*cos(radians(360.0 / 3.0)), r*sin(radians(360.0 / 3.0)), 0.0);
	m->vertices[2] = dvec3(r*cos(radians(2 * (360.0 / 3.0))), r*sin(radians(2 * (360.0 / 3.0))), 0.0);


	return m;
}

//-------------------------------------------------------------------------

Mesh* Mesh::generateTriangleRGB(GLdouble r){
	Mesh* m = new Mesh();
	m->type = GL_TRIANGLES;
	m->numVertices = 3;
	m->vertices = new dvec3[m->numVertices];
	m->vertices[0] = dvec3(r*cos(radians(0.0)), r*sin(radians(0.0)), 0.0);
	m->vertices[1] = dvec3(r*cos(radians(360.0 / 3.0)), r*sin(radians(360.0 / 3.0)), 0.0);
	m->vertices[2] = dvec3(r*cos(radians(2 * (360.0 / 3.0))), r*sin(radians(2 * (360.0 / 3.0))), 0.0);

	m->colors = new dvec4[m->numVertices];
	m->colors[0] = dvec4(1.0, 0.0, 0.0, 1.0);
	m->colors[1] = dvec4(0.0, 1.0, 0.0, 1.0);
	m->colors[2] = dvec4(0.0, 0.0, 1.0, 1.0);

	return m;
}
Mesh* Mesh::generateTriPyramid(GLdouble r, GLdouble h){
	Mesh* m = new Mesh();
	m->type = GL_TRIANGLE_FAN;
	m->numVertices = 5;
	m->vertices = new dvec3[m->numVertices];

	m->vertices[0] = dvec3(0.0, 0.0, h);
	m->vertices[1] = dvec3(r*cos(radians(0.0)), r*sin(radians(0.0)), 0.0);
	m->vertices[2] = dvec3(r*cos(radians(360.0 / 3.0)), r*sin(radians(360.0 / 3.0)), 0.0);
	m->vertices[3] = dvec3(r*cos(radians(2 * (360.0 / 3.0))), r*sin(radians(2 * (360.0 / 3.0))), 0.0);
	m->vertices[4] = dvec3(r*cos(radians(0.0)), r*sin(radians(0.0)), 0.0);

	return m;

	
}
