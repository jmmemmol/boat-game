/* ***************************************************************
 *
 * File : SoundManager.cpp
 *
 * Author : Tiberiu Popa
 * 	    J. Alexander Clarke

 * Date   : June 18th, 2002
 *
 * Modified:
 *
 * Purpose: Implementation of the sound manager
 *
 * ****************************************************************/
#pragma implementation
#include "SoundManager.h"
#include <iostream>

using namespace std;


SoundManager SM;

//--------------------------------------------------------------
SoundManager::SoundManager() :
		mNumSounds(0),
		mNumMusics(0)
{
    // initialize the sound library
    SDL_Init(SDL_INIT_AUDIO);

    // sound setup
    int audio_rate = 22050;
    Uint16 audio_format = AUDIO_S16; 
    int audio_channels = 2;
    int audio_buffers = 4096;

    // open the audio stream 
    if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers))
    {
    	cerr << "ERROR: SoundManager - Unable to open audio!" << endl;
        exit(1);
    }
}

//--------------------------------------------------------------
SoundManager::~SoundManager()
{
	Mix_CloseAudio();
}


/* *************** Manipulate Sound Chunks *******************/
int SoundManager::LoadSound(const char* file)
{
	mChunks[mNumSounds] = Mix_LoadWAV(file);
    mChannels[mNumSounds] = -1;

    return mNumSounds++;
}

//--------------------------------------------------------------
void SoundManager::PlaySound(int snd)
{
    if(IsValidSound(snd))
    {
    	mChannels[snd] = Mix_PlayChannel(-1, mChunks[snd], 0);
    }
}

//--------------------------------------------------------------
void SoundManager::StopSound(int snd)
{
    if(IsValidSound(snd))
    {
		Mix_HaltChannel(mChannels[snd]);
		mChannels[snd] = -1;
	}
}

//--------------------------------------------------------------
void SoundManager::PauseSound(int snd)
{
    if(IsValidSound(snd))
    {
    	Mix_Pause(mChannels[snd]);
    }
}

//--------------------------------------------------------------
void SoundManager::ResumeSound(int snd)
{
    if(IsSoundPaused(snd))
    {
    	Mix_Resume(mChannels[snd]);
    }
}

//--------------------------------------------------------------
bool SoundManager::IsValidSound(int snd)
{
	if(snd < 0 || snd >= mNumSounds)
	{
		cout << "ERROR: SoundManager - No sound with id: " << snd << endl;
		return false;
	}
	return true;
}

//--------------------------------------------------------------
bool SoundManager::IsSoundPaused(int snd)
{
	if(IsValidSound(snd))
	{
		return Mix_Paused(mChannels[snd]);
	}

	return false;
}

/* *************** Manipulate Music *******************/
int SoundManager::LoadMusic(const char* file)
{
    mMusics[mNumMusics] = Mix_LoadMUS(file);
    return mNumMusics++;
}

//--------------------------------------------------------------
void SoundManager::PlayMusic(int mus)
{
    if(IsValidMusic(mus))
    {
    	Mix_PlayMusic(mMusics[mus], 1);
    }
}

//--------------------------------------------------------------
void SoundManager::StopMusic()
{
	Mix_HaltMusic();
}

//--------------------------------------------------------------
void SoundManager::PauseMusic()
{
    Mix_PauseMusic();
}

//--------------------------------------------------------------
void SoundManager::ResumeMusic()
{
	if(IsMusicPaused())
	{
		Mix_ResumeMusic();
	}
}

//--------------------------------------------------------------
bool SoundManager::IsValidMusic(int mus)
{
	if(mus < 0 || mus > mNumMusics)
	{
		return false;
	}
	return true;
}

//--------------------------------------------------------------
bool SoundManager::IsMusicPaused()
{
	return Mix_PausedMusic();
}
