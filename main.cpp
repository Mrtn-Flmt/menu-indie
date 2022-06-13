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
}

void destroy_window(Scene *game)
{   
}

int main(void)
{
    Home_scene *home_scene = new Home_scene();
    // Scene *game = new Scene();
    // InitWindow(1920, 1080, "Menu Indie Studio");
    // SetTargetFPS(60);

    // while (!WindowShouldClose())
    // {
    //     game->_home_scene->check_buttons();
    //     BeginDrawing();
    //         game->_home_scene->draw();
    //         ClearBackground(RAYWHITE);
    //     EndDrawing();
    // }
    // UnloadSound(game->_home_scene->_play_button->_fx);
    // UnloadSound(game->_home_scene->_setting_button->_fx);
    // UnloadSound(game->_home_scene->_quit_button->_fx);
    // CloseAudioDevice();
    // CloseWindow();
    return (0);
}
