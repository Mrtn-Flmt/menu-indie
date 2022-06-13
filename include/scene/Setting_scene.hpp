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

Vector2 pos_targeter_fr = (Vector2){500, 200};
Vector2 pos_targeter_en = (Vector2){500, 400};

class Setting_scene
{
    public:
        Setting_scene();
        ~Setting_scene();

        UIView *_background;
        UIView *_targeter;
        UIButton *_back_button;
        UIButton *_langage_fr_button;
        UIButton *_langage_en_button;
        UIButton *_sound_button;

        int _langage_selector;
        bool _sound;
        int _scene_selector;

        void check_langage_fr_button();
        void check_langage_en_button();
        void check_back_button();
        void check_sound_button();
        void check_buttons();

        void check_langage_text();

        void draw_buttons();
        void draw_textures();
        void draw();

        void set_langage_selector(int x);
        void set_sound(bool select);
};

Setting_scene::Setting_scene()
{
    this->_background = new UIView("assets/bg.png",
                    (Vector2){0, 0});
    this->_targeter = new UIView("assets/baguette.png",
                    (Vector2){screenwidth/2 - 200, 200});
    this->_langage_fr_button = new UIButton("assets/button.png",
                    (Vector2){screenwidth/2 - 111, 200});
    this->_langage_en_button = new UIButton("assets/button.png",
                    (Vector2){screenwidth/2 - 111, 400});
    this->_sound_button = new UIButton("assets/button.png",
                    (Vector2){screenwidth/2 - 111, 600});
    this->_back_button = new UIButton("assets/back_button.png",
                    (Vector2){80, 80});
}

Setting_scene::~Setting_scene()
{
}

void Setting_scene::check_buttons()
{
    check_langage_fr_button();
    check_langage_en_button();
    check_sound_button();
    check_back_button();
}

void Setting_scene::check_langage_fr_button()
{
    Vector2 mouse_pos = GetMousePosition();
    this->_langage_fr_button->_action = false;
    if (CheckCollisionPointRec(mouse_pos, this->_langage_fr_button->_bounds)) {
        this->_langage_fr_button->change_texture("assets/button_over.png");
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            this->_langage_fr_button->_state = 2;
        else
            this->_langage_fr_button->_state = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            this->_langage_fr_button->_action = true;
    } else {
        this->_langage_fr_button->change_texture("assets/button.png");
        this->_langage_fr_button->_state = 0;
    }
    if (this->_langage_fr_button->_action) {
        printf("langage fr button has been pressed. ✅\n");
        if (this->_langage_selector == 1)
            this->_langage_selector = 0;
        PlaySound(this->_langage_fr_button->_fx);
    }
}

void Setting_scene::check_langage_en_button()
{
    Vector2 mouse_pos = GetMousePosition();
    this->_langage_en_button->_action = false;
    if (CheckCollisionPointRec(mouse_pos, this->_langage_en_button->_bounds)) {
        this->_langage_en_button->change_texture("assets/button_over.png");
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            this->_langage_en_button->_state = 2;
        else
            this->_langage_en_button->_state = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            this->_langage_en_button->_action = true;
    } else {
        this->_langage_en_button->change_texture("assets/button.png");
        this->_langage_en_button->_state = 0;
    }
    if (this->_langage_en_button->_action) {
        printf("langage en button has been pressed. ✅\n");
        if (this->_langage_selector == 0)
            this->_langage_selector = 1;
        PlaySound(this->_langage_en_button->_fx);
    }
}

void Setting_scene::check_sound_button()
{
    Vector2 mouse_pos = GetMousePosition();
    this->_sound_button->_action = false;
    if (CheckCollisionPointRec(mouse_pos, this->_sound_button->_bounds)) {
        this->_sound_button->change_texture("assets/button_over.png");
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            this->_sound_button->_state = 2;
        else
            this->_sound_button->_state = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            this->_sound_button->_action = true;
    } else {
        this->_sound_button->change_texture("assets/button.png");
        this->_sound_button->_state = 0;
    }
    if (this->_sound_button->_action) {
        printf("Sound button has been pressed. ✅\n");
        if (!this->_sound) {
            this->_sound = true;
            printf("_sound = true ✅\n");
        } else {
            this->_sound = false;
            printf("_sound = false ❌\n");
        }
        PlaySound(this->_sound_button->_fx);
    }
}

void Setting_scene::check_back_button()
{
    Vector2 mouse_pos = GetMousePosition();
    this->_back_button->_action = false;
    if (CheckCollisionPointRec(mouse_pos, this->_back_button->_bounds)) {
        this->_back_button->change_texture("assets/back_button.png");
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            this->_back_button->_state = 2;
        } else {
            this->_back_button->_state = 1;
        }
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

void Setting_scene::check_langage_text()
{
    if (this->_langage_selector == 0) {
        DrawText("Français", 921,
                this->_langage_fr_button->_bounds.y + this->_langage_fr_button->_texture.height/2 - 15,
                30, WHITE);
        DrawText("Anglais", 921,
                this->_langage_en_button->_bounds.y + this->_langage_en_button->_texture.height/2 - 15,
                30, WHITE);
        
        if (this->_sound)
            DrawText("Son activé", 921,
                    this->_sound_button->_bounds.y + this->_sound_button->_texture.height/2 - 15,
                    30, WHITE);
        else
            DrawText("Son désactivé", 921,
                    this->_sound_button->_bounds.y + this->_sound_button->_texture.height/2 - 15,
                    30, WHITE);
    } else if (this->_langage_selector == 1) {
        DrawText("French", 921,
                this->_langage_fr_button->_bounds.y + this->_langage_fr_button->_texture.height/2 - 15,
                30, WHITE);
        DrawText("English", 921,
                this->_langage_en_button->_bounds.y + this->_langage_en_button->_texture.height/2 - 15,
                30, WHITE);
        if (this->_sound)
            DrawText("Sound ON", 921,
                    this->_sound_button->_bounds.y + this->_sound_button->_texture.height/2 - 15,
                    30, WHITE);
        else
            DrawText("Sound OFF", 921,
                    this->_sound_button->_bounds.y + this->_sound_button->_texture.height/2 - 15,
                    30, WHITE);
    }
}

void Setting_scene::draw_buttons()
{
    DrawTextureRec(this->_langage_en_button->_texture, this->_langage_en_button->_source,
                    (Vector2){this->_langage_en_button->_bounds.x, this->_langage_en_button->_bounds.y}, WHITE);
    DrawTextureRec(this->_langage_fr_button->_texture, this->_langage_fr_button->_source,
                    (Vector2){this->_langage_fr_button->_bounds.x, this->_langage_fr_button->_bounds.y}, WHITE);
    DrawTextureRec(this->_sound_button->_texture, this->_sound_button->_source,
                    (Vector2){this->_sound_button->_bounds.x, this->_sound_button->_bounds.y}, WHITE);
    DrawTextureRec(this->_back_button->_texture, this->_back_button->_source,
                    (Vector2){this->_back_button->_bounds.x, this->_back_button->_bounds.y}, WHITE);
    check_langage_text();
    
}

void Setting_scene::draw_textures()
{
    DrawTexture(this->_background->_texture, this->_background->_pos.x, this->_background->_pos.y, WHITE);
}

void Setting_scene::draw()
{
    this->_scene_selector = 1;
    BeginDrawing();
        ClearBackground(RAYWHITE);
        draw_textures();
        draw_buttons();
        if (this->_langage_selector == 0)
            DrawTexture(this->_targeter->_texture, pos_targeter_fr.x,
                        pos_targeter_fr.y, WHITE);
        else if (this->_langage_selector == 1)
            DrawTexture(this->_targeter->_texture, pos_targeter_en.x,
                        pos_targeter_en.y, WHITE);
    EndDrawing();
}

void Setting_scene::set_langage_selector(int x)
{
    this->_langage_selector = x;
}

void Setting_scene::set_sound(bool select)
{
    this->_sound = select;
}

#endif /* !SETTING_SCENE_HPP_ */
