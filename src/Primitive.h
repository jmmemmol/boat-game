/*
 * Primitive.h
 *
 *  Created on: Aug 19, 2013
 *      Author: Jenna
 */

#ifndef PRIMITIVE_H_
#define PRIMITIVE_H_

#include <GLUT/glut.h>

class Primitive {
public:
	virtual ~Primitive();
	virtual void Draw() const = 0;
};

class Sphere : public Primitive {
public:
	Sphere();
	virtual ~Sphere();
	virtual void Draw() const;
private:
	GLdouble m_radius;
	GLint m_slices;
	GLint m_stacks;
};

class Cylinder : public Primitive {
public:
	Cylinder();
	Cylinder( GLdouble radtop, GLdouble radbot );
	virtual ~Cylinder();
	virtual void Draw() const;
private:
	GLdouble m_radiusTop;
	GLdouble m_radiusBottom;
	GLdouble m_height;
	GLint m_slices;
	GLint m_stacks;
};

class Cube : public Primitive {
public:
	Cube();
	virtual ~Cube();
	virtual void Draw() const;
};

#endif /* PRIMITIVE_H_ */
