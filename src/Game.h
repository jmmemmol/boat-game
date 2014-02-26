/*
 * Game.h
 *
 *  Created on: Aug 18, 2013
 *      Author: Jenna
 */

#ifndef GAME_H_
#define GAME_H_

#include <map>
#include <vector>
#include <time.h>
#include "SoundManager.h"
#include "Texture.h"
#include "Group.h"
#include "Skybox.h"
#include "Camera.h"
#include "Water.h"
#include "Player.h"
#include "Particle.h"
#include "Track.h"

using namespace std;

class Game {
public:
	Game();
	virtual ~Game();

	// basic functions
	void Initialize();
	bool Update( double delta );
	void Reset();
	void Draw();

	// movement functions
	void SetLeftTurn( bool turn );
	void SetRightTurn( bool turn );

	// getters
	Camera* getCamera() const { return mCamera; }

protected:

private:
	// textures
	map<string, Texture*> mTextures;

	// player
	Player* mPlayer;

	// groups
	Group mGoals;
	Group mObstacles;

	// skybox
	Skybox mSkybox;

	// movement
	bool mTurnLeft;
	bool mTurnRight;

	// camera
	Camera* mCamera;

	// water
	Water* mWater;

	// sounds
	vector<int> mSounds;

	// strikes
	int mStrikeMax;
	int mStrikes;

	// Particle System
	ParticleSystem* mParticleSystem;

	// track
	Track mTrack;

	// countdown stuff
	double mCountDownTime;
	bool mCount3;
	bool mCount2;
	bool mCount1;
};

#endif /* GAME_H_ */
