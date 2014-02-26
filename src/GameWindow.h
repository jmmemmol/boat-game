/*
 * GameWindow.h
 *
 *  Created on: Aug 16, 2013
 *      Author: Jenna
 */

#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

#include <iostream>
#include <time.h>

using namespace std;

class Game;

class GameWindow {
public:
    // constructors
    GameWindow();
    GameWindow( int width, int height, const char* title );

    ~GameWindow();

    void Initialize();
    bool Update();

    // user input
    void OnKeyPressEvent( unsigned char key, int x, int y );
    void OnKeyPressEvent ( int key, int x, int y );
    void OnKeyReleaseEvent( unsigned char key, int x, int y );
    void OnKeyReleaseEvent( int key, int x, int y );
    void OnMouseButtonPressEvent( int button, int x, int y );
    void OnMouseButtonReleaseEvent( int button, int x, int y );
    void OnMouseMoveEvent( int x, int y );
    void Display();

    // getters
    int GetWidth() const { return mWidth; }
    int GetHeight() const { return mHeight; }
    const char* GetTitle() const { return mTitle; }

private:
    int mWidth;
	int mHeight;
	const char* mTitle;

	float mFOV;
	float mNear;
	float mFar;

	bool mLeftButton;
	bool mRightButton;
	bool mMiddleButton;
	float mMousePosX;

	float mZoom;
	float mRotation[3];
	float mTranslation[3];

	bool mPaused;

	// last update time
	clock_t mLastTick;

    Game* mGame;
};

extern GameWindow gGameWindow;

#endif /* GAMEWINDOW_H_ */
