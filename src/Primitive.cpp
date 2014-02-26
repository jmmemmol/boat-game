/*
 * Primitive.cpp
 *
 *  Created on: Aug 19, 2013
 *      Author: Jenna
 */

#include "Primitive.h"

// display list stuff
static bool gSphereListCreated = false;
static bool gCubeListCreated = false;
static GLuint gSphereDisplayList;
static GLuint gCubeDisplayList;


Primitive::~Primitive()
{
}

Sphere::Sphere() :
	m_radius( 1.0 ),
	m_slices( 32 ),
	m_stacks( 32 )
{
	if( !gSphereListCreated )
	{
		// set up display list
		gSphereDisplayList = glGenLists( 1 );
		glNewList( gSphereDisplayList, GL_COMPILE );
		glEnable( GL_NORMALIZE );
		GLUquadric *quad = gluNewQuadric();
		gluQuadricDrawStyle( quad, GLU_FILL );
		gluQuadricNormals( quad, GL_SMOOTH );
		gluQuadricTexture( quad, GL_TRUE );
		gluSphere( quad, m_radius, m_slices, m_stacks );
		glDisable( GL_NORMALIZE );
		glEndList();
		gSphereListCreated = true;
	}
}

Sphere::~Sphere()
{}

void Sphere::Draw() const
{
	// draw sphere
	glCallList( gSphereDisplayList );
}

Cylinder::Cylinder() :
	m_radiusTop( 1.0 ),
	m_radiusBottom( 1.0 ),
	m_height( 1.0 ),
	m_slices( 32 ),
	m_stacks( 32 )
{}

Cylinder::Cylinder( GLdouble radtop, GLdouble radbot ) :
	m_radiusTop( radtop ),
	m_radiusBottom( radbot ),
	m_height( 1.0 ),
	m_slices( 32 ),
	m_stacks( 32 )
{}

Cylinder::~Cylinder()
{}

void Cylinder::Draw() const
{
	// draw cylinder
	glEnable( GL_NORMALIZE );
	GLUquadric *quad = gluNewQuadric();
	gluQuadricDrawStyle( quad, GLU_FILL );
	gluQuadricNormals( quad, GL_SMOOTH );
	gluQuadricTexture( quad, GL_TRUE );
	gluCylinder( quad, m_radiusBottom, m_radiusTop, m_height,
				 m_slices, m_stacks );
	glDisable( GL_NORMALIZE );
}

Cube::Cube()
{
	if( !gCubeListCreated )
	{
		// set up display list
		gCubeDisplayList = glGenLists( 1 );
		glNewList( gCubeDisplayList, GL_COMPILE );

		glEnable( GL_NORMALIZE );
		glBegin( GL_QUADS );

		// 1. front face
		glTexCoord2d( 0.0, 0.0 ); glVertex3d( 0.0, 0.0, 0.0 );
		glTexCoord2d( 0.0, 1.0 ); glVertex3d( 1.0, 0.0, 0.0 );
		glTexCoord2d( 1.0, 1.0 ); glVertex3d( 1.0, 1.0, 0.0 );
		glTexCoord2d( 1.0, 0.0 ); glVertex3d( 0.0, 1.0, 0.0 );


		// 2. bottom face
		glTexCoord2d( 0.0, 0.0 ); glVertex3d( 0.0, 0.0, 0.0 );
		glTexCoord2d( 0.0, 1.0 ); glVertex3d( 1.0, 0.0, 0.0 );
		glTexCoord2d( 1.0, 1.0 ); glVertex3d( 1.0, 0.0, 1.0 );
		glTexCoord2d( 1.0, 0.0 ); glVertex3d( 0.0, 0.0, 1.0 );

		// 3. left side face
		glTexCoord2d( 0.0, 0.0 ); glVertex3d( 0.0, 0.0, 0.0 );
		glTexCoord2d( 0.0, 1.0 ); glVertex3d( 0.0, 0.0, 1.0 );
		glTexCoord2d( 1.0, 1.0 ); glVertex3d( 0.0, 1.0, 1.0 );
		glTexCoord2d( 1.0, 0.0 ); glVertex3d( 0.0, 1.0, 0.0 );

		// 4. back face
		glTexCoord2d( 0.0, 0.0 ); glVertex3d( 0.0, 0.0, 1.0 );
		glTexCoord2d( 0.0, 1.0 ); glVertex3d( 1.0, 0.0, 1.0 );
		glTexCoord2d( 1.0, 1.0 ); glVertex3d( 1.0, 1.0, 1.0 );
		glTexCoord2d( 1.0, 0.0 ); glVertex3d( 0.0, 1.0, 1.0 );

		// 5. top face
		glTexCoord2d( 0.0, 0.0 ); glVertex3d( 0.0, 1.0, 0.0 );
		glTexCoord2d( 0.0, 1.0 ); glVertex3d( 0.0, 1.0, 1.0 );
		glTexCoord2d( 1.0, 1.0 ); glVertex3d( 1.0, 1.0, 1.0 );
		glTexCoord2d( 1.0, 0.0 ); glVertex3d( 1.0, 1.0, 0.0 );

		// 6. right side face
		glTexCoord2d( 0.0, 0.0 ); glVertex3d( 1.0, 0.0, 0.0 );
		glTexCoord2d( 0.0, 1.0 ); glVertex3d( 1.0, 1.0, 0.0 );
		glTexCoord2d( 1.0, 1.0 ); glVertex3d( 1.0, 1.0, 1.0 );
		glTexCoord2d( 1.0, 0.0 ); glVertex3d( 1.0, 0.0, 1.0 );
		glEnd();
		glDisable( GL_NORMALIZE );

		glEndList();
		gCubeListCreated = true;
	}
}

Cube::~Cube()
{}

void Cube::Draw() const
{
	// draw cylinder
	glCallList( gCubeDisplayList );
}
