/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-edouard.courty
** File description:
** Texture
*/

#include "Texture.hpp"

Texture_enc::Texture_enc()
{
}

Texture_enc::Texture_enc(const std::string &filepath)
{
    _text = LoadTexture(filepath.c_str());
}

Texture_enc::~Texture_enc()
{
}

void Texture_enc::drawTexture(const int& posX, const int& posY)
{
    DrawTexture(_text, posX, posY, WHITE);
}