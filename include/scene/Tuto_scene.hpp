/*
** EPITECH PROJECT, 2022
** menu-indie
** File description:
** Tuto_scene
*/

#ifndef TUTO_SCENE_HPP_
#define TUTO_SCENE_HPP_

#include "raylib.h"
#include "./../UI/UIView.hpp"
#include "./../UI/UIButton.hpp"

class Tuto_scene {
    public:

        Tuto_scene();
        ~Tuto_scene();

        UIView *_background;
        UIView *_tuto_page;
        UIButton *_back_button;

        int _scene_selector;

        void check_back_button();
        
        void draw_buttons();
        void draw_textures();
        void draw();

    protected:
    private:
};

Tuto_scene::Tuto_scene()
{
    this->_background = new UIView("assets/bg.png",
                        (Vector2){0, 0});
    this->_tuto_page = new UIView("assets/tuto_page.png",
                        (Vector2){1920/2-725/2, 1080/2-485/2});
    this->_back_button = new UIButton("assets/back_button.png",
                        (Vector2){80, 80});
}

Tuto_scene::~Tuto_scene()
{
}

void Tuto_scene::check_back_button()
{
    Vector2 mouse_pos = GetMousePosition();
    this->_back_button->_action = false;
    if (CheckCollisionPointRec(mouse_pos, this->_back_button->_bounds)) {
        this->_back_button->change_texture("assets/back_button.png");
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            this->_back_button->_state = 2;
        else
            this->_back_button->_state = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            this->_back_button->_action = true;
    } else {
        this->_back_button->change_texture("assets/back_button.png");
        this->_back_button->_state = 0;
    }
    if (this->_back_button->_action) {
        printf("Back button has been pressed. ✅\n");
        this->_scene_selector = 0;
        PlaySound(this->_back_button->_fx);
    }
}

void Tuto_scene::draw_buttons()
{
    DrawTextureRec(this->_back_button->_texture, this->_back_button->_source,
        (Vector2){this->_back_button->_bounds.x, this->_back_button->_bounds.y}, WHITE);
}

void Tuto_scene::draw_textures()
{
    DrawTexture(this->_background->_texture, this->_background->_pos.x, this->_background->_pos.y, WHITE);
    DrawTexture(this->_tuto_page->_texture, this->_tuto_page->_pos.x, this->_tuto_page->_pos.y, WHITE);
}

void Tuto_scene::draw()
{
    this->_scene_selector = 2;
    BeginDrawing();
        ClearBackground(RAYWHITE);
        draw_textures();
        draw_buttons();
    EndDrawing();
}

#endif /* !TUTO_SCENE_HPP_ */
