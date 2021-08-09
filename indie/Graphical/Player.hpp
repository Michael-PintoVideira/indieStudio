/*
** EPITECH PROJECT, 2021
** YEP Indie Studio
** File description:
** Player header
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Bomb.hpp"
#include "raylib.h"
#include <vector>
#include <string>
#include <utility>

class Player {
public:
    Player();
    Player(const std::vector<std::string>&, const std::string&, const char&);
    ~Player();

    void findPos(const std::vector<std::string>&, const char&);
    std::pair<int, int> findBombPos(const std::vector<std::string>&);
    bool canMove(const float&, const float&, const std::vector<std::string>&);
    void move(const std::string&);
    void rotate(const std::string&);
    void display(const Model&);
    std::string getType() const;
    std::vector<Bomb> getBombs() const;
    void addBomb(const std::vector<std::string>&, const std::pair<int, int>&);
    void delBomb(const int&);
    void placeBomb(const std::vector<std::string>&);
    void set_bonus(int);
    int return_had_bonus();
    int return_cant_moove();
    void set_cant_moove(int);
    float return_x();
    float return_y();
    int return_life_player();
    void set_life_player(int);
    void is_it_in_fire(const std::vector<std::string>& map);
    int return_bomber_len();
    void boing_collision_x(int i);
    void boing_collision_y(int i);
    void lossing();
private:
    std::pair<float, float> _pos;
    float _dir;
    std::string _type;
    std::vector<Bomb> _bombs;
    int _maxbomb;
    int had_a_bonus;
    int cant_moove;
    int life_player_1;
    std::chrono::time_point<std::chrono::system_clock> invincible_beg_p1;
    std::chrono::time_point<std::chrono::system_clock> invincible_end_p1;
    int invincible;
    std::chrono::duration<double> elapsed_seconds;
    int _bomber_len;
};

#endif /* PLAYER_HPP */
