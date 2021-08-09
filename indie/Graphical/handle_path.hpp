/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-edouard.courty
** File description:
** handle_path
*/

#ifndef HANDLE_PATH_HPP_
#define HANDLE_PATH_HPP_

#include <iostream>

class Path {
    public:
        Path();
        ~Path();
        bool isRoot();
        std::string getRoot();
    private:
        std::string _returnToRoot = "";
};

#endif /* !HANDLE_PATH_HPP_ */
