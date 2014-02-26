/*
 * Material.cpp
 *
 *  Created on: Aug 19, 2013
 *      Author: Jenna
 */

#include "Material.h"
#include <GLUT/glut.h>

Material::~Material()
{}

PhongMaterial::PhongMaterial( const Colour& kd, const Colour& ks, double shininess ) :
		m_kd( kd ),
		m_ks( ks ),
		m_shininess( shininess )
{}

PhongMaterial::~PhongMaterial()
{}

void PhongMaterial::apply_gl() const
{
	//GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { m_shininess };
	GLfloat colour[] = { m_kd.R(), m_kd.G(), m_kd.B(), 1.0 };

	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess );
	glMaterialfv( GL_FRONT, GL_DIFFUSE, colour );
}
