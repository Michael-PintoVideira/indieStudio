/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-edouard.courty
** File description:
** Raylib
*/

#ifndef RAYLIB_HPP_
#define RAYLIB_HPP_

#include "Model.hpp"
#include "Player.hpp"
#include "raylib.h"
#include <string>
#include <vector>
#include <map>
class Raylib {
public:
    Raylib();
    Raylib(int, bool);
    ~Raylib();
    void setMoves();
    void update();
    void upCam();
    void upMap();
    void setMap(const std::string&);
    void changeMap(int x, int y, char to_change);
    void disMap();
    void disPlayers();
    void addModel(const std::string&, const Model_enc&);
    void addTexture(const std::string&, const Texture2D&);
    void fillPlayers(const int&);
    void addPlayer(const std::string&, const char&);
    Camera3D getCam() const;
    std::vector<std::string> getMap() const;
    Model getModel(const std::string&);
    void drawModel(const Model&, const Vector3&, float);
    void drawCube(const std::string&, const Vector3&);
    void move();
    void placeBomb();
    void disBoom(const std::pair<int, int>& pos, int range);
    void delBoom(const std::pair<int, int>& pos, int range);
    void explode();
    void put_random_1();
    void put_random_2();
    void put_random_3();
    void bonus_gestion();
    void start_timer_bonus1();
    void start_timer_bonus2();
    void start_timer_bonus3();
    void print_backgroud(int);
    void setMapBackground(const std::string&);
    void explosion_gestion();
    void print_the_heart();
    int getLooserWinner();
    void loosing();
protected:
private:
    Camera3D _cam;
    bool _pow;
    std::vector<std::string> _map;
    std::map<std::string, Texture2D> _texts;
    std::map<std::string, Model_enc> _models;
    std::vector<Player> _players;
    std::vector<std::map<std::string, int>> _moves;
    std::vector<std::string> _backgroundMap;
    std::chrono::time_point<std::chrono::system_clock> _timer_bonus1_beg;
    std::chrono::time_point<std::chrono::system_clock> _timer_bonus1_end;
    std::chrono::time_point<std::chrono::system_clock> _timer_bonus2_beg;
    std::chrono::time_point<std::chrono::system_clock> _timer_bonus2_end;
    std::chrono::time_point<std::chrono::system_clock> _timer_bonus3_beg;
    std::chrono::time_point<std::chrono::system_clock> _timer_bonus3_end;
    int looser_winner;
};

#endif /* !RAYLIB_HPP_ */
