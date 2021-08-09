/*
** EPITECH PROJECT, 2021
** YEP IndieStudio
** File description:
** Button class
*/

#include "Bomb.hpp"

Bomb::Bomb(const std::pair<int, int>& pos)
{
    _pos = pos;
    _start = std::chrono::system_clock::now();
}

Bomb::~Bomb()
{
}

std::pair<int, int> Bomb::getPos() const
{
    return _pos;
}

std::chrono::time_point<std::chrono::system_clock> Bomb::getStart() const
{
    return _start;
}
