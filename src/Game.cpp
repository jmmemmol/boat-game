/*
 * Game.cpp
 *
 *  Created on: Aug 18, 2013
 *      Author: Jenna
 */

#include "Game.h"
#include "Crate.h"
#include "Buoy.h"
#include "Goal.h"
#include <GLUT/glut.h>

Game::Game() :
	mPlayer( NULL ),
	mTurnLeft( false ),
	mTurnRight( false ),
	mCamera( NULL ),
	mWater( NULL ),
	mStrikeMax( 4 ),
	mStrikes( 0 ),
	mParticleSystem( NULL ),
	mCountDownTime( 3.0 ),
	mCount3( false ),
	mCount2( false ),
	mCount1( false )
{
}

Game::~Game()
{
  // Nothing to do here right now.
}

void Game::Initialize()
{

	mTurnLeft = false;
	mTurnRight = false;
	mStrikeMax = 4;
	mStrikes = 0;
	mCountDownTime = 3.0;
	mCount3 = false;
	mCount2 = false;
	mCount1 = false;

	// initialize textures
	Texture* waterTex = new Texture( "data/textures/waterTexture.jpg" );
	if( !waterTex->Load() )
	{
		cerr << "ERROR: Game - Failed to load water texture" << endl;
		return;
	}
	mTextures["water"] = waterTex;


	// initialize sounds
	mSounds.push_back( SM.LoadSound( "data/sounds/motor.wav" ) );
	mSounds.push_back( SM.LoadSound( "data/sounds/collect.wav" ) );
	mSounds.push_back( SM.LoadSound( "data/sounds/miss.wav" ) );
	mSounds.push_back( SM.LoadSound( "data/sounds/1.wav" ) );
	mSounds.push_back( SM.LoadSound( "data/sounds/2.wav" ) );
	mSounds.push_back( SM.LoadSound( "data/sounds/3.wav" ) );
	mSounds.push_back( SM.LoadSound( "data/sounds/win.wav" ) );
	mSounds.push_back( SM.LoadSound( "data/sounds/lose.wav" ) );
	mSounds.push_back( SM.LoadSound( "data/sounds/background.wav" ) );

	// initialize player
	mPlayer = new Player( Point3D( 0.0, 2.0, -20.0 ) );

	// Set up new camera and attach to player
	mCamera = new Camera();
	mCamera->Attach( mPlayer );

	// initialize obstacles and add to obstacles group
	Crate* crate1 = new Crate( Point3D( -50.0, -2.0, -25.0 ) );
	mObstacles.AddMember( crate1 );
	Crate* crate2 = new Crate( Point3D( -120.0, -2.0, -70.0 ) );
	mObstacles.AddMember( crate2 );
	Crate* crate3 = new Crate( Point3D( -165.0, -2.0, -100.0 ) );
	mObstacles.AddMember( crate3 );
	Crate* crate4 = new Crate( Point3D( -150.0, -2.0, -150.0 ) );
	mObstacles.AddMember( crate4 );
	Crate* crate5 = new Crate( Point3D( -175.0, -2.0, -205.0 ) );
	mObstacles.AddMember( crate5 );
	Crate* crate6 = new Crate( Point3D( -160.0, -2.0, -275.0 ) );
	mObstacles.AddMember( crate6 );
	Crate* crate7 = new Crate( Point3D( -185.0, -2.0, -245.0 ) );
	mObstacles.AddMember( crate7 );
	Crate* crate8 = new Crate( Point3D( -140.0, -2.0, -320.0 ) );
	mObstacles.AddMember( crate8 );
	Crate* crate9 = new Crate( Point3D( -65.0, -2.0, -370.0 ) );
	mObstacles.AddMember( crate9 );
	Crate* crate10 = new Crate( Point3D( -05.0, -2.0, -375.0 ) );
	mObstacles.AddMember( crate10 );
	Crate* crate11 = new Crate( Point3D( 65.0, -2.0, -355.0 ) );
	mObstacles.AddMember( crate11 );
	Crate* crate12 = new Crate( Point3D( 125.0, -2.0, -325.0 ) );
	mObstacles.AddMember( crate12 );
	Crate* crate13 = new Crate( Point3D( 150.0, -2.0, -260.0 ) );
	mObstacles.AddMember( crate13 );
	Crate* crate14 = new Crate( Point3D( 20.0, -2.0, -20.0 ) );
	mObstacles.AddMember( crate14 );
	Crate* crate15 = new Crate( Point3D( -10.0, -2.0, -30.0 ) );
	mObstacles.AddMember( crate15 );

	Buoy* buoy1 = new Buoy( Point3D( -80.0, -0.5, -40.0 ) );
	mObstacles.AddMember( buoy1 );
	Buoy* buoy2 = new Buoy( Point3D( -81.0, -0.5, -55.0 ) );
	mObstacles.AddMember( buoy2 );
	Buoy* buoy3 = new Buoy( Point3D( -150.0, -0.5, -80.0 ) );
	mObstacles.AddMember( buoy3 );
	Buoy* buoy4 = new Buoy( Point3D( -135.0, -0.5, -90.0 ) );
	mObstacles.AddMember( buoy4 );
	Buoy* buoy5 = new Buoy( Point3D( -160.0, -0.5, -120.0 ) );
	mObstacles.AddMember( buoy5 );
	Buoy* buoy6 = new Buoy( Point3D( -145.0, -0.5, -130.0 ) );
	mObstacles.AddMember( buoy6 );
	Buoy* buoy7 = new Buoy( Point3D( -180.0, -0.5, -181.0 ) );
	mObstacles.AddMember( buoy7 );
	Buoy* buoy8 = new Buoy( Point3D( -165.0, -0.5, -180.0 ) );
	mObstacles.AddMember( buoy8 );
	Buoy* buoy9 = new Buoy( Point3D( -180.0, -0.5, -260.0 ) );
	mObstacles.AddMember( buoy9 );
	Buoy* buoy10 = new Buoy( Point3D( -165.0, -0.5, -250.0 ) );
	mObstacles.AddMember( buoy10 );
	Buoy* buoy11 = new Buoy( Point3D( -115.0, -0.5, -300.0 ) );
	mObstacles.AddMember( buoy11 );
	Buoy* buoy12 = new Buoy( Point3D( -125.0, -0.5, -315.0 ) );
	mObstacles.AddMember( buoy12 );
	Buoy* buoy13 = new Buoy( Point3D( -90.0, -0.5, -340.0 ) );
	mObstacles.AddMember( buoy13 );
	Buoy* buoy14 = new Buoy( Point3D( -100.0, -0.5, -355.0 ) );
	mObstacles.AddMember( buoy14 );
	Buoy* buoy15 = new Buoy( Point3D( -31.0, -0.5, -375.0 ) );
	mObstacles.AddMember( buoy15 );
	Buoy* buoy16 = new Buoy( Point3D( -30.0, -0.5, -390.0 ) );
	mObstacles.AddMember( buoy16 );
	Buoy* buoy17 = new Buoy( Point3D(41.0, -0.5, -360.0 ) );
	mObstacles.AddMember( buoy17 );
	Buoy* buoy18 = new Buoy( Point3D( 40.0, -0.5, -345.0 ) );
	mObstacles.AddMember( buoy18 );
	Buoy* buoy19 = new Buoy( Point3D( 110.0, -0.5, -335.0 ) );
	mObstacles.AddMember( buoy19 );
	Buoy* buoy20 = new Buoy( Point3D( 105.0, -0.5, -320.0 ) );
	mObstacles.AddMember( buoy20 );
	Buoy* buoy21 = new Buoy( Point3D( 140.0, -0.5, -286.0 ) );
	mObstacles.AddMember( buoy21 );
	Buoy* buoy22 = new Buoy( Point3D( 161.0, -0.5, -285.0 ) );
	mObstacles.AddMember( buoy22 );
	Buoy* buoy23 = new Buoy( Point3D( 160.0, -0.5, -230.0 ) );
	mObstacles.AddMember( buoy23 );
	Buoy* buoy24 = new Buoy( Point3D( 175.0, -0.5, -225.0 ) );
	mObstacles.AddMember( buoy24 );
	Buoy* buoy25 = new Buoy( Point3D( 165.0, -0.5, -180.0 ) );
	mObstacles.AddMember( buoy25 );
	Buoy* buoy26 = new Buoy( Point3D( 150.0, -0.5, -175.0 ) );
	mObstacles.AddMember( buoy26 );
	Buoy* buoy27 = new Buoy( Point3D( 175.0, -0.5, -146.0 ) );
	mObstacles.AddMember( buoy27 );
	Buoy* buoy28 = new Buoy( Point3D( 160.0, -0.5, -145.0 ) );
	mObstacles.AddMember( buoy28 );
	Buoy* buoy29 = new Buoy( Point3D( 165.0, -0.5, -95.0 ) );
	mObstacles.AddMember( buoy29 );
	Buoy* buoy30 = new Buoy( Point3D( 150.0, -0.5, -100.0 ) );
	mObstacles.AddMember( buoy30 );
	Buoy* buoy31 = new Buoy( Point3D( 111.0, -0.5, -80.0 ) );
	mObstacles.AddMember( buoy31 );
	Buoy* buoy32 = new Buoy( Point3D( 110.0, -0.5, -65.0 ) );
	mObstacles.AddMember( buoy32 );
	Buoy* buoy33 = new Buoy( Point3D( 45.0, -0.5, -30.0 ) );
	mObstacles.AddMember( buoy33 );
	Buoy* buoy34 = new Buoy( Point3D( 30.0, -0.5, -45.0 ) );
	mObstacles.AddMember( buoy34 );

	// initialize goals and add to goals group
	Goal* goal1 = new Goal( buoy1, buoy2 );
	mGoals.AddMember( goal1 );
	goal1->Highlight();
	Goal* goal2 = new Goal( buoy3, buoy4 );
	mGoals.AddMember( goal2 );
	Goal* goal3 = new Goal( buoy5, buoy6 );
	mGoals.AddMember( goal3 );
	Goal* goal4 = new Goal( buoy7, buoy8 );
	mGoals.AddMember( goal4 );
	Goal* goal5 = new Goal( buoy9, buoy10 );
	mGoals.AddMember( goal5 );
	Goal* goal6 = new Goal( buoy11, buoy12 );
	mGoals.AddMember( goal6 );
	Goal* goal7 = new Goal( buoy13, buoy14 );
	mGoals.AddMember( goal7 );
	Goal* goal8 = new Goal( buoy15, buoy16 );
	mGoals.AddMember( goal8 );
	Goal* goal9 = new Goal( buoy17, buoy18 );
	mGoals.AddMember( goal9 );
	Goal* goal10 = new Goal( buoy19, buoy20 );
	mGoals.AddMember( goal10 );
	Goal* goal11 = new Goal( buoy21, buoy22 );
	mGoals.AddMember( goal11 );
	Goal* goal12 = new Goal( buoy23, buoy24 );
	mGoals.AddMember( goal12 );
	Goal* goal13 = new Goal( buoy25, buoy26 );
	mGoals.AddMember( goal13 );
	Goal* goal14 = new Goal( buoy27, buoy28 );
	mGoals.AddMember( goal14 );
	Goal* goal15 = new Goal( buoy29, buoy30 );
	mGoals.AddMember( goal15 );
	Goal* goal16 = new Goal( buoy31, buoy32 );
	mGoals.AddMember( goal16 );
	Goal* goal17 = new Goal( buoy33, buoy34 );
	mGoals.AddMember( goal17 );

	// initialize water
	mWater = new Water( mTextures["water"] );

	// create particles behind boat
	vector<Colour> colours;
	colours.push_back( Colour( 0.78, 0.89, 1.0 ) );
	colours.push_back( Colour( 0.94, 0.97, 1.0 ) );
	colours.push_back( Colour( 0.27, 0.51, 0.71 ) );
	mParticleSystem = new ParticleSystem( 1000, colours,
										  mPlayer->GetPosition() +
										  Vector3D( 0.8, -1.7, 5.5 ),
										  Vector3D( 3.0, 7.0, 2.0 ),
										  10.0 );
}

bool Game::Update( double delta )
{
	mCountDownTime -= delta;
	if( mCountDownTime > 0.0 )
	{
		if( !mCount3 && mCountDownTime < 3.0 )
		{
			//SM.PlaySound(mSounds[5]);
			mCount3 = true;
		}
		if( !mCount2 && mCountDownTime < 2.0 )
		{
			//SM.PlaySound(mSounds[4]);
			mCount2 = true;
		}
		if( !mCount1 && mCountDownTime < 1.0 )
		{
			//SM.PlaySound(mSounds[3]);
			mCount1 = true;
		}
		return true;
	}
	// update water
	mWater->Update( delta );

	// update obstacles
	mObstacles.Update( delta );

	// update player movement
	if( mTurnLeft )
	{
		mPlayer->TurnLeft( delta );
	}
	else if( mTurnRight )
	{
		mPlayer->TurnRight( delta );
	}

	// check for collision with obstacles after turning
	if( mPlayer->CheckCollision( mObstacles ) || mTrack.CheckCollision( mPlayer ) )
	{
		mPlayer->UndoLastMove();
	}

	// check for collision with obstacles after moving forward
	mPlayer->MoveForward( delta );
	if( mPlayer->CheckCollision( mObstacles ) )
	{
		mPlayer->UndoLastMove();
	}

	// update player
	mPlayer->Update( delta );

	// update goals
	mGoals.Update( delta );


	if( mGoals.Size() > 0 )
	{
		Goal* goal = dynamic_cast<Goal*>( mGoals.GetMember( 0 ) );

		// if player has collided with next goal then play the success
		// sound and remove goal
		if( goal->CheckCollision( mPlayer ) )
		{
			cout << "SUCCESS" << endl;
			//SM.PlaySound(mSounds[1]);
			goal->Highlight();
			mGoals.RemoveMember( mGoals.GetMember( 0 ) );

			// highlight next goal
			if( mGoals.Size() > 0 )
			{
				Goal* nextGoal = dynamic_cast<Goal*>( mGoals.GetMember( 0 ) );
				nextGoal->Highlight();
			}
		}

		// if player has passed the next goal then play the missed sound
		// and remove goal
		else if( goal->HasPassed( mPlayer ) )
		{
			//cout << "FAIL" << endl;
			//SM.PlaySound(mSounds[2]);

			// remove highlight and remove goal from group
			goal->Highlight();
			mGoals.RemoveMember( mGoals.GetMember( 0 ) );
			mStrikes++;

			// game over
			if( mStrikes >= mStrikeMax )
			{
				// reset the game
				//SM.PlaySound(mSounds[7]);
				Reset();
			}
			// highlight next goal
			if( mGoals.Size() > 0 )
			{
				Goal* nextGoal = dynamic_cast<Goal*>( mGoals.GetMember( 0 ) );
				nextGoal->Highlight();
			}
		}
	}
	else
	{
		//SM.PlaySound(mSounds[6]);
	}

	// update particle system
	mParticleSystem->SetOrigin( mPlayer->GetPosition() +
								mPlayer->GetTransform() *
							 	Vector3D( 0.8, -1.7, 5.5 ) );
	mParticleSystem->Update( delta );

	return true;
}

void Game::Reset()
{
	free( mPlayer );
	free( mParticleSystem );
	free( mWater );
	free( mCamera );
	mTextures.clear();
	mSounds.clear();
	mGoals = Group();
	mObstacles = Group();
	Initialize();
}

void Game::Draw()
{
	// 1. Draw in stencil buffer for reflection area (ie. water)
	glColorMask( GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE );
	glDepthMask( GL_FALSE );
	glEnable( GL_STENCIL_TEST );
	glStencilFunc( GL_ALWAYS, 1, 0xFFFFFFFF );
	glStencilOp( GL_REPLACE, GL_REPLACE, GL_REPLACE );
	mWater->Draw();
	glColorMask( GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE );
	glDepthMask( GL_TRUE );
	glStencilFunc( GL_EQUAL, 1, 0xFFFFFFFF );
	glStencilOp( GL_KEEP, GL_KEEP, GL_KEEP );

	// 2. Draw reflection of objects
	glDisable( GL_DEPTH_TEST );
	glPushMatrix();
	glScaled( 1.0, -1.0, 1.0 ); // mirror in y
	glEnable( GL_LIGHTING );
	glEnable( GL_LIGHT0 );

	// draw reflections
	mPlayer->Draw();
	mObstacles.Draw();
	mTrack.Draw();
	glDisable( GL_LIGHTING );
	glDisable( GL_LIGHT0 );
	glDisable( GL_STENCIL_TEST );
	glPopMatrix();
	glEnable( GL_DEPTH_TEST );

	// 3. Draw reflection area (ie. water)
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	mWater->Draw();
	glDisable( GL_BLEND );

	// 4. Draw objects
	glEnable( GL_LIGHTING );
	glEnable( GL_LIGHT0 );
	mPlayer->Draw();
	mObstacles.Draw();
	mSkybox.Draw();
	mTrack.Draw();
	glDisable( GL_LIGHTING );
	glDisable( GL_LIGHT0 );
	mParticleSystem->Draw();
	mGoals.Draw();
}

void Game::SetLeftTurn( bool turn )
{
	if( mTurnRight && !mTurnLeft )
	{
		return;
	}
  mTurnLeft = turn;
}

void Game::SetRightTurn( bool turn )
{
	if( mTurnLeft && !mTurnRight )
	{
		return;
	}
  mTurnRight = turn;
}
