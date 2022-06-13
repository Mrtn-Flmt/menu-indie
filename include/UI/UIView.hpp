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
        ~UIView() = default;

        Texture2D _texture;
        Vector2 _pos;
};

UIView::UIView(const char* texture_file, Vector2 pos)
{
    printf("UIView start done.\n");
    this->_texture = LoadTexture(texture_file);
    printf("UIView LoadTexture done.\n");
    this->_pos = pos;
    printf("UIView pos done.\n");
}

#endif /* !UIVIEW_HPP_ */
