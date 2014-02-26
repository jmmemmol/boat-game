//============================================================================
// Name        : main.cpp
// Author      : Jenga
// Version     : 1
// Copyright   : Your copyright notice
// Description : Main
//============================================================================

#include <iostream>
#include <GLUI/glui.h>
#include <GLUT/glut.h>
#include "GameWindow.h"

using namespace std;

void display()
{
	gGameWindow.Display();
}

void onKeyPressEvent( unsigned char key, int x, int y )
{
    gGameWindow.OnKeyPressEvent( key, x, y );
}

void onKeyReleaseEvent( unsigned char key, int x, int y )
{
	gGameWindow.OnKeyReleaseEvent( key, x, y );
}

void onSpecialKeyPressEvent( int key, int x, int y )
{
	gGameWindow.OnKeyPressEvent( key, x, y );
}

void onSpecialKeyReleaseEvent( int key, int x, int y )
{
	gGameWindow.OnKeyReleaseEvent( key, x, y );
}

void onMouseButtonEvent( int button, int state, int x, int y )
{
	if( state == GLUT_DOWN )
	{
		gGameWindow.OnMouseButtonPressEvent( button, x, y );
	}
	else
	{
		gGameWindow.OnMouseButtonReleaseEvent( button, x, y );
	}
}

void onMouseMoveEvent( int x, int y )
{
    gGameWindow.OnMouseMoveEvent( x, y );
}

void update()
{
	if( !gGameWindow.Update() )
	{
		cout << "ERROR: GameWindow - Failed to update game!" << endl;
		return;
	}
	glutPostRedisplay();
}

int main( int argc, char* argv[] )
{
    gGameWindow = GameWindow( 640, 640, "Jungle Game" );

	// initialize and run program
	glutInit( &argc, argv );                                                // GLUT initialization
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );				// Display Mode
	glutInitWindowSize( gGameWindow.GetWidth(), gGameWindow.GetHeight() );  // set window size
	glutCreateWindow( gGameWindow.GetTitle() );								// create Window
	glutDisplayFunc( display );									// register Display Function
	glutIdleFunc( update );										// register Idle Function
	glutKeyboardFunc( onKeyPressEvent );						// register Keyboard Handler
	glutKeyboardUpFunc( onKeyReleaseEvent );					// register Keyboard Up Handler
	glutSpecialFunc( onSpecialKeyPressEvent );					// register Special Key Handler
	glutSpecialUpFunc( onSpecialKeyReleaseEvent );				// register Special Key Up Handler
	glutMouseFunc( onMouseButtonEvent );						// register Mouse Button Handler
	glutMotionFunc( onMouseMoveEvent );							// register Mouse Motion Handler
	gGameWindow.Initialize();
	glutMainLoop();												// run GLUT mainloop

	return 0;
}
