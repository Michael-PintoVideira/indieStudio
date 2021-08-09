/*
** EPITECH PROJECT, 2021
** YEP IndieStudio
** File description:
** Button class
*/


#ifndef BOMB_HPP_
#define BOMB_HPP_
#include <utility>
#include <chrono>

class Bomb {
public:
    Bomb(const std::pair<int, int>&);
    ~Bomb();
    std::pair<int, int> getPos() const;
    std::chrono::time_point<std::chrono::system_clock> getStart() const;
private:
    std::pair<int, int> _pos;
    std::chrono::time_point<std::chrono::system_clock> _start;
};
#endif
