/*
 * Crate.h
 *
 *  Created on: Sep 7, 2013
 *      Author: Jenna
 */

#ifndef CRATE_H_
#define CRATE_H_

#include "Entity.h"
#include "Scene.h"

class Crate : public Entity {
public:
	Crate( Point3D pos = Point3D() );
	virtual ~Crate();

	virtual void Update( double delta );
	virtual void Draw();

protected:

private:
	SceneNode* mRoot;
	string mFileName;
	double mBobHeight;
	double mBobAmount;
};

#endif /* CRATE_H_ */
