/*
** EPITECH PROJECT, 2022
** menu_indie
** File description:
** UIButton
*/

#ifndef UIBUTTON_HPP_
#define UIBUTTON_HPP_

#include "raylib.h"

class UIButton {
    public:
        UIButton(const char* texture_file, Vector2 pos);
        ~UIButton();

        Texture2D _texture;
        Rectangle _bounds;
        Rectangle _source;
        Vector2 _pos;
        Sound _fx;
        int _state;
        bool _action;

        void change_texture(const char* texture_file);
};

UIButton::UIButton(const char* texture_file, Vector2 pos)
{
    this->_texture = LoadTexture(texture_file);
    this->_bounds = { pos.x, pos.y,
                    (float)this->_texture.width,
                    (float)this->_texture.height };
    this->_source = { 0, 0, (float)this->_texture.width,
                (float)this->_texture.height };
    this->_fx = LoadSound("assets/buttonfx.wav");
    this->_state = 0;
    this->_action = false;
}

UIButton::~UIButton()
{
}

void UIButton::change_texture(const char* texture_file)
{
    this->_texture = LoadTexture(texture_file);
}

#endif /* !UIBUTTON_HPP_ */
