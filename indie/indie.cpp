#include "Raylib.hpp"
#include "Menu.hpp"
#include "Option.hpp"

//g++ indie.cpp Graphical/*.cpp -o bomberman -lraylib -IGraphical

void game(int nbPlayers, bool powers)
{
    Raylib ray(nbPlayers, powers);
    while (!WindowShouldClose()) {
        ray.update();
        ray.upCam();
        BeginDrawing();
        BeginMode3D(ray.getCam());
        ray.disMap();
        ray.disPlayers();
        ray.move();
        ray.placeBomb();
        ray.explode();
        ray.bonus_gestion();
        ray.upMap();
        ray.print_backgroud(1);
        ray.explosion_gestion();
        ray.print_the_heart();
        ray.loosing();
        EndMode3D();
        EndDrawing();
    }
}

void settings()
{
    Option opt;
    opt.playMusic("SettingsMenu");
    while (!WindowShouldClose() && !opt.shouldClose()) {
        opt.upMusic("SettingsMenu");
        BeginDrawing();
        opt.drawTexture("Background", 0, 0);
        opt.drawButtons();
        EndDrawing();
        opt.event();
    }
    game(opt.getNbPlayers(), opt.arePowersUp());
}

void menu()
{
    Menu men;
    men.playMusic("ThemeMenu");
    while (!WindowShouldClose() && !men.shouldClose()) {
        men.upMusic("ThemeMenu");
        BeginDrawing();
        men.drawTexture("Background", 0, 0);
        men.drawButtons();
        EndDrawing();
        men.event();
    }
    settings();
}

int main()
{
    menu();
}
