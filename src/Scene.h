/*
 * Scene.h
 *
 *  Created on: Aug 19, 2013
 *      Author: Jenna
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <list>
#include "Algebra.h"
#include "Primitive.h"
#include "Material.h"
#include "Texture.h"

class SceneNode {
public:
	SceneNode( const std::string& name );
	virtual ~SceneNode();

	virtual void WalkGl( bool picking = false ) const;
	virtual void Highlight();

	virtual SceneNode* SelectNode( unsigned int* stackptr );

	const Matrix4x4& GetTransform() const { return mTrans; }
	const Matrix4x4& GetInverse() const { return mInvTrans; }

	void SetTransform( const Matrix4x4& m )
	{
		mTrans = m;
		mInvTrans = m.invert();
	}

	void SetTransform( const Matrix4x4& m, const Matrix4x4& i )
	{
		mTrans = m;
		mInvTrans = i;
	}

	void AddChild( SceneNode* child )
	{
		mChildren.push_back( child );
	}

	void RemoveChild( SceneNode* child )
	{
		mChildren.remove( child );
	}

	// Callbacks to be implemented.
	// These will be called from Lua.
	void Rotate( char axis, double angle );
	void Scale( const Vector3D& amount );
	void Translate( const Vector3D& amount );

	// Returns true if and only if this node is a JointNode
	virtual bool IsJoint() const;
	virtual bool IsGeometry() const;

	virtual double RestrictRotateAngle( char axis, double angle ) const { return 0; }

	int GetId() const { return mId; }
	std::string GetName() const { return mName; }
	Matrix4x4 GetScale() const { return mScale; }

	virtual void ResetJoints();

protected:

	// Useful for picking
	int mId;
	std::string mName;

	// Transformations
	Matrix4x4 mTrans;
	Matrix4x4 mInvTrans;
	Matrix4x4 mScale;

	// Hierarchy
	typedef std::list<SceneNode*> ChildList;
	ChildList mChildren;
};

class JointNode : public SceneNode {
public:
	JointNode( const std::string& name );
	virtual ~JointNode();

	virtual void WalkGl( bool picking = false ) const;
	virtual SceneNode* SelectNode( unsigned int* stackptr );

	virtual bool IsJoint() const;

	virtual double RestrictRotateAngle( char axis, double angle ) const;

	void SetJointX( double min, double init, double max );
	void SetJointY( double min, double init, double max );

	struct JointRange {
		double min, init, max, cur;
	};

	void SetCurX( double value ) { mJointX.cur = value; }
	void SetCurY( double value ) { mJointY.cur = value; }

	JointRange GetJointX() { return mJointX; }
	JointRange GetJointY() { return mJointY; }
	virtual void ResetJoints();

protected:

	JointRange mJointX, mJointY;
	bool mSelected;
};

class GeometryNode : public SceneNode {
public:
	GeometryNode( const std::string& name, Primitive* primitive );
	virtual ~GeometryNode();

	virtual void WalkGl( bool picking = false ) const;
	virtual SceneNode* SelectNode( unsigned int* stackptr );

	virtual bool IsGeometry() const;
	virtual void Highlight();

	const Material* GetMaterial() const;
	Material* GetMaterial();

	Texture* GetTexture() const { return mTexture; }

	void SetTexture( Texture* texture )
	{
		mTexture = texture;
	}

	void SetMaterial( Material* material )
	{
		mMaterial = material;
	}
	void SetInitMaterial( Material* material )
	{
		mInitMaterial = material;
	}
	virtual void ResetJoints();

protected:
	Texture* mTexture;
	Material* mMaterial;
	Material* mInitMaterial;
	Primitive* mPrimitive;
};

#endif /* SCENE_H_ */
