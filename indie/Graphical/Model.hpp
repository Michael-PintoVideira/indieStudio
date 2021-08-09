/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-edouard.courty
** File description:
** Model
*/

#ifndef MODEL_HPP_
#define MODEL_HPP_

#include "raylib.h"
#include <iostream>
#include <fstream>
#include <vector>

class Model_enc {
    public:
        Model_enc();
        Model_enc(std::string, std::string);
        ~Model_enc();

    //draw functions
        void drawModel_ext(Model, Vector3, Vector3, float, Vector3, Color);
        void drawModel_cubew();

    //loaders
        void loadTextures(Model, std::string) const;

    //unloader
        void unloadTextures(Texture2D) const;

    //getters
        Model getModel() const;
    private:
        Model _model;
};

#endif /* !MODEL_HPP_ */
