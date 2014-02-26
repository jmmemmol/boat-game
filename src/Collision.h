/*
 * Collision.h
 *
 *  Created on: Oct 12, 2013
 *      Author: Jenna
 */

#ifndef COLLISION_H_
#define COLLISION_H_

#include "Algebra.h"

// 3D Oriented Bounding Box
class OBB3D {
public:
	OBB3D();
	OBB3D( Point3D min_pos, Point3D max_pos, Matrix4x4 rot = Matrix4x4() );
	virtual ~OBB3D();

	bool IsPointInBox( Point3D point );
	bool IsSphereInBox( Point3D center, double radius );
	bool IsBoxInBox( const OBB3D& box );
	bool IsLineInBox( Point3D point1, Point3D point2 );
	bool IsBoxOutsidePlane( Vector3D normal, Point3D point );

	// getters
	Vector3D GetExtent() const { return mExtent; }
	Point3D GetCenter() const;
	Matrix4x4 GetRotation() const;

	// rotate and translate functions
	void Rotate( const Matrix4x4& rot );
	void Translate(const Vector3D& trans );

private:
	Vector3D mExtent;
	Matrix4x4 mTransform; // only contains rotation & translation
};

#endif /* COLLISION_H_ */
