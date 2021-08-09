/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-edouard.courty
** File description:
** Menu
*/

#include "handle_path.hpp"
#include "Menu.hpp"

Menu::Menu()
{
    Path path;
    std::string repoBuildExec = "B-YEP-400-PAR-4-1-indiestudio-edouard.courty/build";
    std::string soundMenu = "Ressources/Sounds/amogus_theme.ogg";
    std::string background = "Ressources/background.png";
    std::string button1 = "Ressources/button1.png";
    std::string exitButton = "Ressources/exit.png";

    InitWindow(1920, 1080, "Raylib Test 1");
    InitAudioDevice();
    SetTargetFPS(60);
    _quit = false;
    if (path.isRoot() == false) {
        std::string backOne = path.getRoot();
        soundMenu.insert(0, backOne);
        background.insert(0, backOne);
        button1.insert(0, backOne);
        exitButton.insert(0, backOne);
    }
    this->addSound("ThemeMenu", Sound_enc(soundMenu));
    this->addTexture("Background", Texture_enc(background));
    this->addButton(button1, std::make_pair(670, 200));
    this->addButton(exitButton, std::make_pair(670, 500));
}

Menu::~Menu()
{
}

void Menu::playMusic(const std::string& sound)
{
    _sounds[sound].playMusic();
}

void Menu::upMusic(const std::string& music)
{
    if (IsKeyPressed(KEY_SPACE)) _sounds[music].resetMusic();
    else if (IsKeyPressed(KEY_P)) _sounds[music].pauseMusic();
    UpdateMusicStream(_sounds[music].getMusic());
}

void Menu::drawTexture(const std::string& text, const int& x, const int& y)
{
    _texts[text].drawTexture(x, y);
}

void Menu::addSound(const std::string& type, const Sound_enc& sound)
{
    _sounds.insert({type, sound});
}

void Menu::addTexture(const std::string& type, const Texture_enc& texture)
{
    _texts.insert({type, texture});
}

void Menu::addButton(const std::string& path, const std::pair<float, float>& pos)
{
    _buttons.push_back(Button(path, pos));
}

void Menu::drawButtons()
{
    for (auto & it : _buttons)
        it.drawButton();
}

void Menu::event()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (CheckCollisionPointRec(_buttons[0].getMousePos(), _buttons[0].getBounds()))
            _quit = true;
        if (CheckCollisionPointRec(_buttons[1].getMousePos(), _buttons[1].getBounds())) {
            CloseWindow();
            exit(0);
        }
    }
}

bool Menu::shouldClose() const
{
    return _quit;
}
