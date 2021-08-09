/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-edouard.courty
** File description:
** Texture
*/

#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include "raylib.h"
#include <iostream>
#include <string>
#include <map>

class Texture_enc {
    public:
        Texture_enc();
        Texture_enc(const std::string&);
        ~Texture_enc();

        void drawTexture(const int&, const int&);
    private:
        Texture2D _text;
};

#endif /* !TEXTURE_HPP_ */
