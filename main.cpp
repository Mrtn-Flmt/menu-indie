/*
** EPITECH PROJECT, 2022
** menu_indie
** File description:
** main
*/

#include <iostream>
#include "raylib.h"
#include <stdlib.h>

#include "./include/scene/Scene.hpp"
#include "./include/scene/Home_scene.hpp"

void init_window()
{
    InitWindow(1920, 1080, "Menu Indie Studio");
    SetTargetFPS(60);
}

void destroy_window(Scene *game)
{
    UnloadSound(game->_home_scene->_play_button->_fx);
    UnloadSound(game->_home_scene->_setting_button->_fx);
    UnloadSound(game->_home_scene->_quit_button->_fx);
    CloseAudioDevice();
    CloseWindow();
}

void check_buttons(Scene *game)
{
    game->_home_scene->check_buttons();
    game->_setting_scene->check_buttons();
}

void check_sound(Scene *game)
{
    game->_sound = game->_setting_scene->_sound;
}

void select_scene(Scene *game)
{
    game->select_scene();
    if (game->_selector == 0) {
        game->_home_scene->draw();
    } else if (game->_selector == 1) {
        game->_setting_scene->draw();
    }
}

int main(void)
{
    init_window();
    Scene *game = new Scene();

    while (!WindowShouldClose())
    {
        check_buttons(game);
        check_sound(game);
        select_scene(game);
    }
    destroy_window(game);
    return (0);
}
