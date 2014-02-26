/*
 * Collision.cpp
 *
 *  Created on: Oct 12, 2013
 *      Author: Jenna
 */

#include "Collision.h"

OBB3D::OBB3D() {
	// TODO Auto-generated constructor stub

}

OBB3D::OBB3D( Point3D min_pos, Point3D max_pos, Matrix4x4 rot )
{
	mExtent = 0.5 * ( max_pos - min_pos );
	Vector3D center = min_pos + mExtent;

	// translate transform
	Translate(center);

	// rotate transform
	mTransform = mTransform * rot;
}

OBB3D::~OBB3D() {
	// TODO Auto-generated destructor stub
}

bool OBB3D::IsPointInBox( Point3D point )
{
	// transform point into box space
	Point3D new_point = mTransform.invert() * point;

	// use axis-aligned check
	if ( fabs(new_point[0]) < mExtent[0] &&
		 fabs(new_point[1]) < mExtent[1] &&
		 fabs(new_point[2]) < mExtent[2] )
	{
		return true;
	}

	return false;
}

bool OBB3D::IsSphereInBox( Point3D center, double radius )
{
	double dist = 0;
	double dist_sq = 0;

	// transform sphere center point into box space
	Point3D new_center = mTransform.invert() * center;

	// add distance squared from sphere center point to box for each axis
	for (int i = 0; i < 3; i++)
	{
		if (fabs(new_center[i]) > mExtent[i])
		{
			dist = fabs(new_center[i]) - mExtent[i];
			dist_sq += dist * dist;
		}
	}
	return ( dist_sq <= radius * radius );
}

bool OBB3D::IsBoxOutsidePlane( Vector3D normal, Point3D point )
{
	// transform plane normal into box space
	Vector3D new_normal = GetRotation().invert() * normal;
	new_normal = Vector3D( fabs(new_normal[0]),
						   fabs(new_normal[1]),
						   fabs(new_normal[2]));

	double extent = new_normal.dot(mExtent); // box extent along plane normal
	double dist = normal.dot( GetCenter() - point ); // distance from center of box to plane

	// If Box Centerpoint is behind the plane further than its extent, the Box is outside the plane
	return (dist < -extent);
	return false;
}

bool OBB3D::IsLineInBox( Point3D point1, Point3D point2 )
{
	// transform line into box space
	Matrix4x4 rot_inv = GetRotation().invert();
	Point3D new_point1 = rot_inv * point1;
	Point3D new_point2 = rot_inv * point2;

	// Get line midpoint and extent
	Point3D mid = (point1 + point2) * 0.5f;
	Vector3D L = (point1 - mid);
	Vector3D LExt = Vector3D( fabs(L[0]), fabs(L[1]), fabs(L[2]) );

	// Use Separating Axis Test
	// Separation vector from box center to line center is LMid, since the line is in box space
	if ( fabs( mid[0] ) > mExtent[0] + LExt[0] ) return false;
	if ( fabs( mid[1] ) > mExtent[1] + LExt[1] ) return false;
	if ( fabs( mid[2] ) > mExtent[2] + LExt[2] ) return false;

	// Cross products of line and each axis
	if ( fabs( mid[1] * L[2] - mid[2] * L[1])  >  (mExtent[1] * LExt[2] + mExtent[2] * LExt[1]) ) return false;
	if ( fabs( mid[0] * L[2] - mid[2] * L[0])  >  (mExtent[0] * LExt[2] + mExtent[2] * LExt[0]) ) return false;
	if ( fabs( mid[0] * L[1] - mid[1] * L[0])  >  (mExtent[0] * LExt[1] + mExtent[1] * LExt[0]) ) return false;

	// No separating axis, the line intersects
	return true;
}

bool OBB3D::IsBoxInBox( const OBB3D &box )
{
	// uses Separating Axis Theorem

	// get center point, rotation, and extend for 2 boxes
	Vector3D extentA = mExtent;
	Point3D centerA = GetCenter();
	Matrix4x4 rotA = GetRotation();

	Vector3D extentB = box.GetExtent();
	Point3D centerB = box.GetCenter();
	Matrix4x4 rotB = box.GetRotation();

	// difference between center points
	Vector3D diff = centerB - centerA;

	// rotation from B to A
	Matrix4x4 R;
	for( int i = 0; i < 3; i++ )
	{
		for( int j = 0; j < 3; j++ )
		{
			Vector3D unit_vectorA( rotA[i][0], rotA[i][1], rotA[i][3] );
			unit_vectorA.normalize();

			Vector3D unit_vectorB( rotB[j][0], rotB[j][1], rotB[j][2] );
			unit_vectorB.normalize();

			R[i][j] = unit_vectorA.dot( unit_vectorB );
		}
	}

	// Search for possible separating axis (15 cases)
	for(int i = 0; i < 3; i++)
	{
		// check for separating axes parallel to A's basis vectors
		Vector3D unit_vectorA( rotA[i][0], rotA[i][1], rotA[i][2] );
		unit_vectorA.normalize();
		if( fabs( diff.dot( unit_vectorA ) ) > extentA[i] +
			fabs( extentB[0] * R[i][0] ) +
			fabs( extentB[1] * R[i][1] ) +
			fabs( extentB[2] * R[i][2] ) )
		{
			return false;
		}

		// check for separating axes parallel to B's basis vectors
		Vector3D unit_vectorB( rotB[i][0], rotB[i][1], rotB[i][2] );
		unit_vectorB.normalize();
		if( fabs( diff.dot( unit_vectorB ) ) > extentB[i] +
			fabs( extentA[0] * R[i][0] ) +
			fabs( extentA[1] * R[i][1] ) +
			fabs( extentA[2] * R[i][2] ) )
		{
			return false;
		}

		// check for separating axis perpendicular to separating plane
		// spanned by the cross product of each basis vector combination
		// of A and B
		int i1 = ( i + 1 ) % 3;
		int i2 = ( i + 2 ) % 3;
		for( int j = 0; j < 3; j++ )
		{
			int j1 = ( j + 1 ) % 3;
			int j2 = ( j + 2 ) % 3;
			Vector3D unit_vectorA1( rotA[i1][0], rotA[i1][1], rotA[i1][2] );
			Vector3D unit_vectorA2( rotA[i2][0], rotA[i2][1], rotA[i2][2] );

			if( fabs( diff.dot( unit_vectorA2 ) * R[i1][j] +
					  diff.dot( unit_vectorA1 ) * R[i2][j] ) >
				fabs( extentA[i1] * R[i2][j] ) +
				fabs( extentA[i2] * R[i1][j] ) +
				fabs( extentB[j1] * R[i][j2] ) +
				fabs( extentB[j2] * R[i][j1] ) )
			{
				return false;
			}
		}
	}
	// since no separating axis could be found the boxes must overlap
	return true;
}

Point3D OBB3D::GetCenter() const
{
	return Point3D(mTransform[0][3], mTransform[1][3], mTransform[2][3]);
}

Matrix4x4 OBB3D::GetRotation() const
{
	Matrix4x4 rot = mTransform;

	// set translation part of matrix to 0
	rot[0][3] = 0;
	rot[1][3] = 0;
	rot[2][3] = 0;

	return rot;
}

void OBB3D::Rotate( const Matrix4x4& rot )
{
	mTransform =  mTransform * rot;
}

void OBB3D::Translate( const Vector3D& trans )
{
	Matrix4x4 transMatrix;
	transMatrix[0][3] += trans[0];
	transMatrix[1][3] += trans[1];
	transMatrix[2][3] += trans[2];

	mTransform = mTransform * transMatrix;
}
