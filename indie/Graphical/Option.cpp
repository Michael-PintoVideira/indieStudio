/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-edouard.courty
** File description:
** Option
*/

#include "handle_path.hpp"
#include "Option.hpp"

Option::Option()
{
    Path path;
    std::string repoBuildExec = "B-YEP-400-PAR-4-1-indiestudio-edouard.courty/build";
    std::string soundMenu = "Ressources/Sounds/amogus_theme.ogg";
    std::string background = "Ressources/background.png";
    std::string rsc1 = "Ressources/1.png";
    std::string rsc2 = "Ressources/2.png";
    std::string rsc3 = "Ressources/3.png";
    std::string rsc4 = "Ressources/4.png";
    std::string rsc5 = "Ressources/5.png";
    std::string rsc6 = "Ressources/6.png";
    SetTargetFPS(60);
    _players = 4;
    _ia = 0;
    _quit = false;
    _power = false;
    if (path.isRoot() == false) {
        std::string backOne = path.getRoot();
        soundMenu.insert(0, backOne);
        background.insert(0, backOne);
        rsc1.insert(0, backOne);
        rsc2.insert(0, backOne);
        rsc3.insert(0, backOne);
        rsc4.insert(0, backOne);
        rsc5.insert(0, backOne);
        rsc6.insert(0, backOne);
    }
    this->addSound("SettingsMenu", Sound_enc(soundMenu));
    this->addTexture("Background", Texture_enc(background));
    this->addButton(rsc1, std::make_pair(900, 100));
    this->addButton(rsc2, std::make_pair(900, 200));
    this->addButton(rsc3, std::make_pair(900, 300));
    this->addButton(rsc4, std::make_pair(900, 400));
    this->addButton(rsc5, std::make_pair(900, 500));
    this->addButton(rsc6, std::make_pair(900, 600));
}

Option::~Option()
{
}

void Option::playMusic(const std::string& sound)
{
    _sounds[sound].playMusic();
}

void Option::upMusic(const std::string& music)
{
    if (IsKeyPressed(KEY_SPACE)) _sounds[music].resetMusic();
    else if (IsKeyPressed(KEY_P)) _sounds[music].pauseMusic();
    UpdateMusicStream(_sounds[music].getMusic());
}

void Option::drawTexture(const std::string& text, const int& x, const int& y)
{
    _texts[text].drawTexture(x, y);
}

void Option::addSound(const std::string& type, const Sound_enc& sound)
{
    _sounds.insert({type, sound});
}

void Option::addTexture(const std::string& type, const Texture_enc& texture)
{
    _texts.insert({type, texture});
}

void Option::addButton(const std::string& path, const std::pair<float, float>& pos)
{
    _buttons.push_back(Button(path, pos));
}

void Option::drawButtons()
{
    for (auto & it : _buttons)
        it.drawButton();
}

#include <iostream>

void Option::event()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (CheckCollisionPointRec(_buttons[0].getMousePos(), _buttons[0].getBounds())) {
            _players = 1;
            _ia = 3;
            _quit = true;
        }
        if (CheckCollisionPointRec(_buttons[1].getMousePos(), _buttons[1].getBounds())) {
            _players = 2;
            _ia = 2;
            _quit = true;
        }
        if (CheckCollisionPointRec(_buttons[2].getMousePos(), _buttons[2].getBounds())) {
            _players = 3;
            _ia = 1;
            _quit = true;
        }
        if (CheckCollisionPointRec(_buttons[3].getMousePos(), _buttons[3].getBounds())) {
            _players = 4;
            _ia = 0;
            _quit = true;
        }
        if (CheckCollisionPointRec(_buttons[4].getMousePos(), _buttons[4].getBounds())) {
            _power = true;
        }
        if (CheckCollisionPointRec(_buttons[5].getMousePos(), _buttons[5].getBounds())) {
            CloseWindow();
            exit(0);
        }
    }
}

int Option::getNbPlayers() const
{
    return _players;
}

bool Option::arePowersUp() const
{
    return _power;
}

bool Option::shouldClose() const
{
    return _quit;
}
