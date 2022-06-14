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

void init_window()
{
    InitWindow(1920, 1080, "Menu Indie Studio");
    SetTargetFPS(30);
}

void destroy_window(Scene *game)
{
    UnloadSound(game->_home_scene->_play_button->_fx);
    UnloadSound(game->_home_scene->_setting_button->_fx);
    UnloadSound(game->_home_scene->_quit_button->_fx);
    UnloadMusicStream(game->_music);
    CloseAudioDevice();
    CloseWindow();
}

void check_buttons(Scene *game)
{
    game->_home_scene->check_buttons();
    game->_setting_scene->check_buttons();
    game->_tuto_scene->check_back_button();
}

void check_sound(Scene *game)
{
    game->_sound = game->_setting_scene->_sound;
    if (game->_sound)
        PlayMusicStream(game->_music);
    else
        PauseMusicStream(game->_music);
}

void select_scene(Scene *game)
{
    game->select_scene();
    if (game->_selector_scene == 0)
        game->_home_scene->draw();
    else if (game->_selector_scene == 1)
        game->_setting_scene->draw();
    else if (game->_selector_scene == 2)
        game->_tuto_scene->draw();
}

void run(Scene *game)
{
    UpdateMusicStream(game->_music);
    check_buttons(game);
    check_sound(game);
    select_scene(game);
}

int main(void)
{
    InitAudioDevice();
    init_window();
    Scene *game = new Scene();
    PlayMusicStream(game->_music);
    while (!WindowShouldClose())
        run(game);
    destroy_window(game);
    return (0);
}
