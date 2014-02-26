/*
 * GameWindow.cpp
 *
 *  Created on: Aug 16, 2013
 *      Author: Jenna
 */

#include "GameWindow.h"
#include <GLUT/glut.h>
#include "Game.h"

GameWindow gGameWindow;

GameWindow::GameWindow() :
    mWidth( 640 ),
    mHeight( 640 ),
    mTitle( "" ),
    mFOV( 45.0f ),
	mNear( 1.0f ),
	mFar( 10.0f ),
	mLeftButton( false ),
	mRightButton( false ),
	mMiddleButton( false ),
	mMousePosX( 0.0f ),
	mZoom( 1.0f ),
	mPaused( false ),
	mLastTick( clock() ),
	mGame( NULL )
{}

GameWindow::GameWindow( int width, int height, const char* title ) :
    mWidth( width ),
    mHeight( height ),
    mTitle( title ),
    mFOV( 45.0f ),
    mNear( 1.0f ),
    mFar( 10.0f ),
    mLeftButton( false ),
    mRightButton( false ),
    mMiddleButton( false ),
    mMousePosX( 0.0f ),
    mZoom( 1.0f ),
    mPaused( false) ,
    mLastTick( clock() ),
    mGame( NULL )
{}

GameWindow::~GameWindow()
{}

void GameWindow::Initialize()
{
	// set timer
	mLastTick = clock();

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
    glViewport( 0, 0, mWidth, mHeight );
	GLfloat aspect = (GLfloat) mWidth / mHeight;
	gluPerspective( 40.0, aspect, 0.1, 1000.0 );
	glMatrixMode( GL_MODELVIEW );
	glShadeModel( GL_SMOOTH );
	glClearDepth( 1.0f );
	glEnable( GL_DEPTH_TEST );
	glDepthFunc( GL_LEQUAL );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
	glClearColor( 0.0, 0.0, 0.0, 1.0 );

	// initialize game
	mGame = new Game();
	mGame->Initialize();
}

bool GameWindow::Update()
{
	// get time since last update
	double delta = ( (double) ( clock() - mLastTick ) ) / CLOCKS_PER_SEC;
	mLastTick = clock();

	// update game
	if( !mPaused )
	{
		return mGame->Update( delta );
	}
	return true;
}

void GameWindow::OnKeyPressEvent( unsigned char key, int x, int y )
{
	switch( key )
	{
        default:
            break;
	}
}

void GameWindow::OnKeyPressEvent( int key, int x, int y )
{
	switch( key )
	{
		case GLUT_KEY_LEFT:
			mGame->SetLeftTurn( true );
			break;
		case GLUT_KEY_RIGHT:
			mGame->SetRightTurn( true );
			break;
        default:
            break;
	}
}

void GameWindow::OnKeyReleaseEvent( unsigned char key, int x, int y )
{
	switch( key )
	{
        default:
            break;
	}
}

void GameWindow::OnKeyReleaseEvent( int key, int x, int y )
{
	switch( key )
	{
		case GLUT_KEY_LEFT:
			mGame->SetLeftTurn( false );
			break;
		case GLUT_KEY_RIGHT:
			mGame->SetRightTurn( false );
			break;
        default:
            break;
	}
}

void GameWindow::OnMouseButtonPressEvent( int button, int x, int y )
{
	switch( button )
	{
		case GLUT_LEFT_BUTTON:
			break;
		case GLUT_RIGHT_BUTTON:
			break;
		case GLUT_MIDDLE_BUTTON:
			break;
		default:
			break;
	}
}

void GameWindow::OnMouseButtonReleaseEvent( int button, int x, int y )
{
	switch( button )
	{
		case GLUT_LEFT_BUTTON:
			break;
		case GLUT_RIGHT_BUTTON:
			break;
		case GLUT_MIDDLE_BUTTON:
			break;
		default:
			break;
	}
}


void GameWindow::OnMouseMoveEvent( int x, int y )
{}

void GameWindow::Display()
{
    glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glViewport( 0, 0, mWidth, mHeight );
    gluPerspective( 40.0, (GLfloat)mWidth / (GLfloat)mHeight, 0.1, 1000.0 );

	mGame->getCamera()->Update();

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

	// adjust scene according to window size
	glScaled( (double)mWidth / 750.0, (double)mHeight / 600.0, 1.0 );

    // Clear the screen
	glClearStencil( 0 );
	glClearColor( 0.51, 0.51, 0.6, 0.0 );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );

	// Set up lighting
    GLfloat light_position[] = { 0.0, 10.0, -195.0, 1.0 };
    GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv( GL_LIGHT0, GL_POSITION, light_position );
    glLightfv( GL_LIGHT0, GL_DIFFUSE, white_light );

    // draw game
	glPushMatrix();
	mGame->Draw();
	glPopMatrix();

    // Swap the contents of the front and back buffers so we see what we
    // just drew.
    glutSwapBuffers();
}

