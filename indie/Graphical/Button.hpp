/*
** EPITECH PROJECT, 2021
** YEP IndieStudio
** File description:
** Button class
*/

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "raylib.h"
#include <string>
#include <utility>

class Button {
public:
    Button();
    Button(const std::string&, const std::pair<float, float>&);
    ~Button();

    Vector2 getMousePos();
    void drawButton();
    Rectangle getBounds() const;

private:
    Texture2D _text;
    Rectangle _rec;
    Rectangle _bounds;
};

#endif /* BUTTON_HPP */
