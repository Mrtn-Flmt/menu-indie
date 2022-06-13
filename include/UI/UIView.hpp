/*
** EPITECH PROJECT, 2022
** menu_indie
** File description:
** UIView
*/

#ifndef UIVIEW_HPP_
#define UIVIEW_HPP_

#include "raylib.h"

class UIView {
    public:
        UIView(const char* texture_file, Vector2 pos);
        ~UIView();

        Image _image;
        Texture2D _texture;
        Vector2 _pos;
};

UIView::UIView(const char* texture_file, Vector2 pos)
{
    this->_image = LoadImage(texture_file);
    this->_texture = LoadTextureFromImage(this->_image);
    this->_pos = pos;
}

#endif /* !UIVIEW_HPP_ */
