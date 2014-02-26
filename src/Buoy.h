/*
 * Buoy.h
 *
 *  Created on: Aug 19, 2013
 *      Author: Jenna
 */

#ifndef BUOY_H_
#define BUOY_H_

#include "Entity.h"
#include "Scene.h"

class Buoy : public Entity {
public:
	Buoy( Point3D pos = Point3D() );
	virtual ~Buoy();

	virtual void Update( double delta );
	virtual void Draw();

	void Highlight();

protected:

private:
	SceneNode* mRoot;
	string mFileName;
	double mBobHeight;
	double mBobAmount;
};

#endif /* BUOY_H_ */
