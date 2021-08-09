/*
** EPITECH PROJECT, 2021
** YEP
** File description:
** Button cpp
*/

#include "Button.hpp"

Button::Button()
{
}

Button::Button(const std::string& path, const std::pair<float, float>& pos)
{
    _text = LoadTexture(path.c_str());
    float width = _text.width;
    float height = _text.height;
    _rec = {0, 0, width, height};
    _bounds = {pos.first, pos.second, width, height};
}

Button::~Button()
{
}

Vector2 Button::getMousePos()
{
    return GetMousePosition();
}

void Button::drawButton()
{
    DrawTextureRec(_text, _rec, {_bounds.x, _bounds.y}, WHITE);
}

Rectangle Button::getBounds() const
{
    return _bounds;
}
