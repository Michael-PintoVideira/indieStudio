/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-edouard.courty
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "Sound.hpp"
#include "Button.hpp"
#include "Texture.hpp"
#include "raylib.h"
#include <vector>
#include <string>

class Menu {
public:
    Menu();
    ~Menu();

    void drawTexture(const std::string&, const int&, const int&);
    void addSound(const std::string&, const Sound_enc&);
    void addTexture(const std::string&, const Texture_enc&);
    void addButton(const std::string&, const std::pair<float, float>&);
    void drawButtons();
    void playMusic(const std::string&);
    void upMusic(const std::string&);
    void event();
    bool shouldClose() const;
private:
    std::map<std::string, Sound_enc> _sounds;
    std::map<std::string, Texture_enc> _texts;
    std::vector<Button> _buttons;
    bool _quit;
};

#endif /* !MENU_HPP_ */
