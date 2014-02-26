/*
 * Entity.h
 *
 *  Created on: Aug 19, 2013
 *      Author: Jenna
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "Algebra.h"
#include "Group.h"
#include "Collision.h"

using namespace std;

class Entity {
public:
	Entity();
	virtual ~Entity();

	// basic functions
	virtual void Update( double delta );
	virtual void Draw();

	// collision checks
	Entity* CheckCollision( Group group );
	bool CheckCollision( Entity* entity );

	// getters
	Point3D GetPosition() const { return(mPosition); }
	Vector3D GetNormal() const { return(mNormal); }
	Matrix4x4 GetTransform() const { return(mTrans); }
	const OBB3D& GetBoudingBox() const { return(mBoundingBox); }

protected:
	Point3D mPosition;
	Vector3D mNormal;
	Matrix4x4 mTrans;
	OBB3D mBoundingBox;

private:
};

#endif /* ENTITY_H_ */
