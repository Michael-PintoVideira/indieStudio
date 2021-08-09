/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-edouard.courty
** File description:
** Sound
*/

#include "Sound.hpp"

Sound_enc::Sound_enc()
{
}

Sound_enc::Sound_enc(const std::string &filepath)
{
    _fx = LoadMusicStream(filepath.c_str());
    _pause = false;
}

Sound_enc::~Sound_enc()
{
}

Music Sound_enc::getMusic() const
{
    return _fx;
}

void Sound_enc::initAudio() 
{
    InitAudioDevice();
}
/*
void Sound_enc::playSound()
{
    PlaySound(_fx);
}
*/
void Sound_enc::closeAudio() 
{
    CloseAudioDevice();
}
/*
void Sound_enc::unloadSound()
{
    UnloadSound(_fx);
}

Sound Sound_enc::getSounds()
{
    return (_fx);
}

void Sound_enc::loadMusic()
{
    LoadMusicStream(_fx);
}
*/
void Sound_enc::playMusic()
{
    PlayMusicStream(_fx);
    UpdateMusicStream(_fx);
}

void Sound_enc::resetMusic()
{
    StopMusicStream(_fx);
    PlayMusicStream(_fx);
}

void Sound_enc::pauseMusic()
{
    _pause = !_pause;
    if (_pause) PauseMusicStream(_fx);
    else ResumeMusicStream(_fx);
}