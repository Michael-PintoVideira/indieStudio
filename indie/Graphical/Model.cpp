/*
65;5604;1c** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-edouard.courty
** File description:
** Model
*/

#include "Model.hpp"

Model_enc::Model_enc()
{
}

Model_enc::Model_enc(std::string modelpath, std::string textpath)
{
    _model = LoadModel(modelpath.c_str());
    this->loadTextures(_model, textpath);
}

Model_enc::~Model_enc()
{
}

void Model_enc::drawModel_ext(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint)
{
    DrawModelEx(model, position, rotationAxis, rotationAngle, scale, tint);
}

void Model_enc::loadTextures(Model model, std::string filepath) const
{
    Texture2D texture = LoadTexture(filepath.c_str());
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}

void Model_enc::unloadTextures(Texture2D Text) const
{
    UnloadTexture(Text);
}

Model Model_enc::getModel() const
{
    return _model;
}
