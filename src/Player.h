/*
 * Player.h
 *
 *  Created on: Sep 8, 2013
 *      Author: Jenna
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <GLUT/glut.h>
#include "Entity.h"
#include "Scene.h"

class Player : public Entity {
public:
	Player( Point3D pos = Point3D() );
	virtual ~Player();

	virtual void Update( double delta );
	virtual void Draw();

	void TurnLeft( double delta );
	void TurnRight( double delta );
	void MoveForward( double delta );
	void UpdatePosition();

	virtual void UndoLastMove();

protected:

private:
	SceneNode* mRoot;
	string mFileName;
	GLuint mDisplayList;

	Point3D mLastPosition;
	Vector3D mLastNormal;
	Matrix4x4 mLastTrans;

	Vector3D mVelocity;

	double mWidth;
	double mLength;
	double mHeight;
};

#endif /* PLAYER_H_ */
