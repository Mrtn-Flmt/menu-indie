/*
** EPITECH PROJECT, 2022
** menu_indie
** File description:
** Setting_scene
*/

#ifndef SETTING_SCENE_HPP_
#define SETTING_SCENE_HPP_

#include "raylib.h"
#include "./../UI/UIButton.hpp"
#include "./../UI/UIView.hpp"

class Setting_scene
{
    public:
        Setting_scene();
        ~Setting_scene();

        UIView *_title;
        UIView *_background;
        UIButton *_langages_button[2];
        UIButton *_sound_button;

        int _langage_selector;
        bool _sound;
        int _res[2];

        void set_langage_selector(int x);
        void set_sound(bool select);
        void set_resolution(int x, int y);
};

Setting_scene::Setting_scene()
{

}

void Setting_scene::set_langage_selector(int x)
{
    this->_langage_selector = x;
}

void Setting_scene::set_sound(bool select)
{
    this->_sound = select;
}

void Setting_scene::set_resolution(int x, int y)
{
    this->_res[0] = x;
    this->_res[1] = y;
}

Setting_scene::~Setting_scene()
{
}

#endif /* !SETTING_SCENE_HPP_ */
