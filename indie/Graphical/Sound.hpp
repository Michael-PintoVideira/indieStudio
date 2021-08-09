/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-edouard.courty
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include "raylib.h"
#include <iostream>
#include <string>

class Sound_enc {
    public:
        Sound_enc();
        Sound_enc(const std::string&);
        ~Sound_enc();

        Music getMusic() const;
        // sound effects
        void playSound();
        void unloadSound();
        void initAudio();
        void closeAudio();

        Sound getSounds();

        // Music
        void loadMusic();
        void playMusic();
        void resetMusic();
        void pauseMusic();
    protected:
    private:
    Music _fx;
    Music _song;
    bool _pause;
};

#endif /* !SOUND_HPP_ */
