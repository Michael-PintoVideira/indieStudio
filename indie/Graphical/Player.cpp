/*
** EPITECH PROJECT, 2021
** YEP Indie Studio
** File description:
** Player cpp
*/

#include "Player.hpp"

#include <iostream>
#include <math.h> 
Player::Player()
{
}

Player::Player(const std::vector<std::string>& map, const std::string& type, const char& mark)
{
    this->findPos(map, mark);
    _dir = 0.0f;
    _type = type;
    _maxbomb = 1;
    cant_moove = 0;
    invincible = 0;
    life_player_1 = 3;
    _bomber_len = 1;
}

Player::~Player()
{
}

void Player::findPos(const std::vector<std::string>& map, const char& mark)
{
    float x = 0.0f;
    float y = 0.0f;
    for (auto & it : map) {
        for (int it2 = 0; it[it2]; it2++) {
            if (it[it2] == mark) {
                _pos.first = x;
                _pos.second = y;
                return;
            }
            y += 2;
        }
        x += 2;
        y = 0;
    }
}


int Player::return_life_player(){
    return life_player_1;
}

void Player::set_life_player(int to_set){
    life_player_1 = to_set;
}

void  Player::is_it_in_fire(const std::vector<std::string>& map){
    float player_y_permission = _pos.second;
    float player_x_permission = _pos.first;
    float deplacement_x = 0;
    float deplacement_y = 0;

    for(int parcour_1 = 0; parcour_1 < map.size(); parcour_1++){
        for(int parcour_2 = 0; map[parcour_1][parcour_2] != '\0'; parcour_2++){
            if(map[parcour_1][parcour_2] == 'E' && invincible == 0)
                if(deplacement_x - 2 <= player_x_permission && deplacement_x + 2 >= player_x_permission){ 
                    if (deplacement_y - 2 < player_y_permission && deplacement_y + 2 >= player_y_permission){
                        life_player_1 -= 1;
                        invincible = 1;
                        invincible_beg_p1 = std::chrono::system_clock::now();
                    }
                }
                deplacement_y += 2;
        }
        deplacement_x += 2;
        deplacement_y = 0;
    }
    if(invincible == 1){
        invincible_end_p1 = std::chrono::system_clock::now();
        elapsed_seconds = invincible_end_p1 - invincible_beg_p1;
        if(elapsed_seconds.count() > 3)
            invincible = 0;
    }
}

bool Player::canMove(const float& x, const float& y, const std::vector<std::string>& map)
{
    

    float player_y_permission = _pos.second;
    float player_x_permission = _pos.first;
    float deplacement_x = 0;
    float deplacement_y = -2;

    for(int parcour_1 = 0; parcour_1 < map.size(); parcour_1++){
        for(int parcour_2 = 0; map[parcour_1][parcour_2] != '\0'; parcour_2++){
            deplacement_y += 2;
            if(map[parcour_1][parcour_2] == 'X' || map[parcour_1][parcour_2] == 'G' || map[parcour_1][parcour_2] == 'J' || map[parcour_1][parcour_2] == 'd'){
                if(sqrt(pow(deplacement_x - player_x_permission, 2) + pow(deplacement_y - player_y_permission, 2)) < 1.5)
                    return false;
            }

            if (map[parcour_1][parcour_2] == '1'){
                if(deplacement_x - x <= player_x_permission && deplacement_x + x >= player_x_permission) 
                    if (deplacement_y - y <= player_y_permission && deplacement_y + y >= player_y_permission){
                        if(had_a_bonus != 4)
                            _maxbomb++;
                        had_a_bonus = 1;
                        return true;
                    }
            }
            if (map[parcour_1][parcour_2] == '2'){
                 if(deplacement_x - x <= player_x_permission && deplacement_x + x >= player_x_permission) 
                    if (deplacement_y - y <= player_y_permission && deplacement_y + y >= player_y_permission){
                        if(had_a_bonus != 5)
                            life_player_1++; 
                        had_a_bonus = 2;
                        return true;
                    }
            }
            if (map[parcour_1][parcour_2] == '3'){
                 if(deplacement_x - x <= player_x_permission && deplacement_x + x >= player_x_permission) 
                    if (deplacement_y - y <= player_y_permission && deplacement_y + y >= player_y_permission){
                        if(had_a_bonus != 6)
                            _bomber_len++;
                        had_a_bonus = 3;
                        return true;
                    }
            }
        }
        deplacement_x += 2;
        deplacement_y = -2;
    }
    return true;
}

void Player::move(const std::string& dir)
{
    if (dir == "LEFT")
        _pos.second -= 0.25f;
    if (dir == "RIGHT")
        _pos.second += 0.25f;
    if (dir == "DOWN")
        _pos.first -= 0.25f;
    if (dir == "UP")
        _pos.first += 0.25f;
}

void Player::rotate(const std::string& dir)
{
    if (dir == "LEFT")
        _dir = 180;
    if (dir == "RIGHT")
        _dir = 0;
    if (dir == "DOWN")
        _dir = 270;
    if (dir == "UP")
        _dir = 90;
}

void Player::display(const Model& model)
{
    DrawModelEx(model, {_pos.first, 0.0f, _pos.second}, {0.0f, 1.0f, 0.0f}, _dir, {1.0f, 1.0f, 1.0f}, WHITE);
}

std::string Player::getType() const
{
    return _type;
}

std::vector<Bomb> Player::getBombs() const
{
    return _bombs;
}

void Player::addBomb(const std::vector<std::string>& map, const std::pair<int, int>& pos)
{
    std::pair<int, int> bpos {pos.first, pos.second};
    if (_dir == 0) bpos.second++;
    if (_dir == 90) bpos.first++;
    if (_dir == 180) bpos.second--;
    if (_dir == 270) bpos.first--;
    if (map[bpos.first][bpos.second] == '*')
        _bombs.push_back(Bomb(bpos));
}

std::pair<int, int> Player::findBombPos(const std::vector<std::string>& map)
{
    std::pair<int, int> pos {0, 0};
    std::pair<int, int> bpos {0, 0};
    for (; bpos.first < map.size(); bpos.first++, pos.first += 2) {
        pos.second = 0;
        for (bpos.second = 0; bpos.second < map[bpos.first].size(); bpos.second++, pos.second += 2) {
            if ((pos.first <= _pos.first && pos.first + 2 > _pos.first) &&
                (pos.second >= _pos.second && pos.second - 2 < _pos.second)) {
                return bpos;
            }
        }
    }
    return std::make_pair(map.size(), map[0].size());
}

int Player::return_bomber_len(){
    return _bomber_len;
}
void  Player::set_bonus(int to_maj){
    had_a_bonus = to_maj;
}

float Player::return_x()
{
    return _pos.first;
}

float Player::return_y()
{
    return _pos.second;
}

int  Player::return_had_bonus(){
    return had_a_bonus;
}

void Player::delBomb(const int& count)
{
    _bombs.erase(_bombs.begin() + count);
}

void Player::placeBomb(const std::vector<std::string>& map) {
    std::pair<int, int> bpos = this->findBombPos(map);
    if (_bombs.size() != _maxbomb &&
        (bpos.first != map.size() && bpos.second != map[0].size())) {
        this->addBomb(map, bpos);
    }
}

int Player::return_cant_moove(){
    return cant_moove;
}

void Player::set_cant_moove(int to_set){
    cant_moove = to_set;
}

void Player::boing_collision_x(int i){
    if(i == 1)
        _pos.first += 0.6;
    if(i == -1)
        _pos.first -= 0.6;
}

void Player::boing_collision_y(int i){
    if(i == 1)
        _pos.second += 0.6;
    if(i == -1)
         _pos.second -= 0.6;
}