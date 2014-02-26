 /* ***************************************************************
 *
 * File : SoundManager.h
 *
 * Author : Tiberiu Popa
 *          J. Alexander Clarke
 * Date   : June 18th, 2002
 *
 * Modified:
 *
 * Purpose: Header file for the sound manager
 *
 * ****************************************************************/
#ifndef _SOUND_MANAGER__H
#define _SOUND_MANAGER__H
#pragma interface

// include SDL header files
#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>

// if you want more than 100 sounds, change the MAX_SOUND
#define MAX_SOUNDS 100
#define MAX_MUSIC 100

// wrapper class around SDL and SDL_mixer libraries
class SoundManager {
public:
    SoundManager();
    ~SoundManager();

    // manipulating sound clips
    // sound clips can be played simultaneously
    int LoadSound(const char* file); // returns sound id
    void PlaySound(int snd);
    void StopSound(int snd);
    void PauseSound(int snd);
    void ResumeSound(int snd);

    // manipulating music clips
    // only one music clip can play at a time
    int LoadMusic(const char* file); // returns music id
    void PlayMusic(int mus);
    void StopMusic();
    void PauseMusic();
    void ResumeMusic();

private:
    // sound clips
    Mix_Chunk* mChunks[MAX_SOUNDS];
    Mix_Music* mMusics[MAX_MUSIC];

    // sound channels for active sounds
    int mChannels[MAX_SOUNDS];

    // number of sound clips loaded
    int mNumSounds;
    int mNumMusics;
    
    bool IsValidSound(int snd);
    bool IsSoundPaused(int snd);
    bool IsValidMusic(int mus);
    bool IsMusicPaused();
};


// the global instance of the sound manager
extern SoundManager SM;


#endif // _SOUND_MANAGER__H
