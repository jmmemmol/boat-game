/*
 * Camera.h
 *
 *  Created on: Sep 7, 2013
 *      Author: Jenna
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "Algebra.h"
#include "Entity.h"

class Camera {
public:
	Camera();
	virtual ~Camera();

	// basic functions
	void Attach( Entity* ent );
	void Update();

protected:

private:
	Point3D mOffset;
	Entity* mAttachEntity;
};

#endif /* CAMERA_H_ */
