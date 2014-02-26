/*
 * Particle.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: Jenna
 */

#include "Particle.h"

#include <stdlib.h>
#include <time.h>
#include <GLUT/glut.h>

Particle::Particle() :
	mVelocity( Vector3D() ),
	mLifeTime( 0.0),
	mSize( 1.0),
	mColour( 0.0, 0.0, 0.0 )
{
}

Particle::Particle( Colour colour, Point3D pos, Vector3D vel,
					double lifeTime, double size ) :
	mVelocity( vel ),
	mLifeTime( lifeTime ),
	mSize( size ),
	mColour( colour )
{
	// set position
	mPosition = pos;

	// set colour
	mColour = colour;
}

Particle::~Particle()
{
  // Nothing to do here right now.
}

void Particle::Draw()
{
	// enable point
	glPushMatrix();
	glDepthMask( false );
	glEnable( GL_POINT_SMOOTH );
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	// set up size of point
	double maxSize = 0.0;
	glGetDoublev( GL_POINT_SIZE_MAX, &maxSize );
	glPointSize( mSize );
	glPointParameterf( GL_POINT_FADE_THRESHOLD_SIZE, 100.0 ); // ???
	glPointParameterf( GL_POINT_SIZE_MIN, 1.0 );
	glPointParameterf( GL_POINT_SIZE_MAX, maxSize );

	// size of points decreases
	//GLfloat constant[1] = {1.0};
	//GLfloat quadratic[3] = {1.0, 0.0, 0.1};
	//glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, constant);

	// draw particle
	glBegin( GL_POINTS );
	glColor4d( mColour.R(), mColour.G(), mColour.B(), 0.5 );
	glVertex3d( mPosition[0], mPosition[1], mPosition[2] );
	glEnd();

	// disable stuff
	glDisable( GL_POINT_SMOOTH );
	glDisable( GL_BLEND );
	glDepthMask( true );
	glPopMatrix();
}

void Particle::Update( double delta )
{
	mLifeTime -= delta;
	mVelocity[1] -= 9.8 * delta;
	mPosition = mPosition + delta * mVelocity;
}

ParticleSystem::ParticleSystem() :
	mNumParticles( 0.0 ),
	mOrigin( Point3D() ),
	mBaseVelocity( Vector3D() ),
	mBaseSize( 1.0 )
{}

ParticleSystem::ParticleSystem( int num, vector<Colour> colours, Point3D pos,
								Vector3D vel, double size) :
	mNumParticles( num ),
	mOrigin( pos ),
	mColours( colours ),
	mBaseVelocity( vel ),
	mBaseSize( size )
{
	// for random numbers
	srand( time( NULL ) );

	// create num particles in system
	for( int i = 0; i < mNumParticles; i++ )
	{
		mParticles.push_back( CreateParticle() );
	}
}

ParticleSystem::~ParticleSystem()
{
	// Nothing to do here right now.
}

void ParticleSystem::Draw()
{
	for( unsigned int i = 0; i < mParticles.size(); i++ )
	{
		mParticles[i].Draw();
	}
}

void ParticleSystem::Update( double delta )
{
	for( unsigned int i = 0; i < mParticles.size(); i++ )
	{
		mParticles[i].Update( delta );

		// if particle's life time has been depleated replace with a new particle
		if( mParticles[i].GetLifeTime() <= 0.0 )
		{
			mParticles[i] = CreateParticle();
		}
	}
}

Particle ParticleSystem::CreateParticle()
{
	// set random lifetime
	double lifeTime = (double)( rand() % 100 + 1 ) / 10;

	// adjust velocity be random factor
	Vector3D newVel;
	newVel[0] = mBaseVelocity[0]*(double)( rand() % 100 + 1 ) / 100.0;

	// should particles go left or right
	double xDir = rand() % 2;
	if( xDir <= 0.5 )
	{
		newVel[0] = -newVel[0];
	}
	newVel[1] = mBaseVelocity[1]*(double)( rand() % 100 + 1 ) / 100.0;
	newVel[2] = mBaseVelocity[2]*(double)( rand() % 100 + 1 ) / 100.0;

	// adjust colour
	double colourNum = rand() % mColours.size();

	return Particle( mColours[colourNum], mOrigin, newVel, lifeTime, mBaseSize );
}


