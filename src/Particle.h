/*
 * Particle.h
 *
 *  Created on: Sep 8, 2013
 *      Author: Jenna
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "Entity.h"
#include "Texture.h"
#include <vector>

class Particle : public Entity {
public:
	Particle();
	Particle( Colour colour, Point3D pos, Vector3D vel,
			  double lifeTime, double size = 1.0 );
	virtual ~Particle();

	virtual void Draw();
	virtual void Update( double delta );

	// getters
	double GetLifeTime() const { return mLifeTime; }
	double GetSize() const { return mSize; }
	Colour GetColour() const { return mColour; }

protected:

private:
	Vector3D mVelocity;
	double mLifeTime;
	double mSize;
	Colour mColour;
};

// manage particles
class ParticleSystem
{
public:
	ParticleSystem();
	ParticleSystem( int num, vector<Colour> colours, Point3D pos,
					Vector3D vel, double size = 1.0 );
	virtual ~ParticleSystem();

	void Draw();
	void Update( double delta );
	Particle CreateParticle();

	// setters
	void SetOrigin( Point3D pos ) { mOrigin = pos; }

protected:

private:
	int mNumParticles;
	vector<Particle> mParticles;
	Point3D mOrigin;
	vector<Colour> mColours;
	Vector3D mBaseVelocity;
	double mBaseSize;
};

#endif /* PARTICLE_H_ */
