/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-edouard.courty
** File description:
** handle_path
*/

#include <algorithm>
#include "handle_path.hpp"

#ifdef __unix__
    #include <unistd.h>
    Path::Path()
    {
        std::string tempPosition = get_current_dir_name();
        std::string repoName = "B-YEP-400-PAR-4-1-indiestudio-edouard.courty";
        std::size_t pos = tempPosition.find(repoName);
        std::string position = tempPosition.substr(pos);
        std::size_t nb = std::count(position.begin(), position.end(), '/');

        for (int i = 0; i < nb; i++)
            _returnToRoot.append("../");
    }
#else
    #include <windows.h>
    Path::Path()
    {
        char buffer[MAX_PATH];
        GetModuleFileName(NULL, buffer, MAX_PATH);
        std::string tempPosition = buffer;
        std::string repoName = "B-YEP-400-PAR-4-1-indiestudio-edouard.courty";
        std::size_t pos = tempPosition.find(repoName);
        std::string position = tempPosition.substr(pos);
        std::size_t nb = std::count(position.begin(), position.end(), '\\');
        for (int i = 1; i < nb; i++)
            _returnToRoot.append("../");
    }
#endif

Path::~Path()
{
}

bool Path::isRoot()
{
    if (_returnToRoot != "")
        return (false);
    return (true);
}

std::string Path::getRoot()
{
    return (_returnToRoot);
}