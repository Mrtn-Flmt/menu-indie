/*
** EPITECH PROJECT, 2022
** menu_indie
** File description:
** Home_scene
*/

#ifndef HOME_SCENE_HPP_
#define HOME_SCENE_HPP_

#define screenwidth 1920
#define screenheight 1080

#include "raylib.h"
#include "./../UI/UIButton.hpp"
#include "./../UI/UIView.hpp"

class Home_scene
{
    public:
        Home_scene();
        ~Home_scene();

        UIView *_background;
        UIButton *_play_button;
        UIButton *_setting_button;
        UIButton *_quit_button;
        UIView *_title;

        void check_play_button();
        void check_setting_button();
        void check_quit_button();
        void check_buttons();

        void draw_textures();
        void draw_buttons();

        void draw();
};

Home_scene::Home_scene()
{
    this->_background = new UIView("assets/bg.png",
                        (Vector2){0, 0});
    this->_title = new UIView("assets/title.png",
                        (Vector2){screenwidth/2 - 245, 100});
    this->_play_button = new UIButton("assets/button.png",
                        (Vector2){screenwidth/2 - 111, 400 });
    this->_setting_button = new UIButton("assets/button.png",
                        (Vector2){ screenwidth/2 - 111, 600 });
    this->_quit_button = new UIButton("assets/button.png",
                        (Vector2){ screenwidth/2 - 111, 800 });
}

Home_scene::~Home_scene()
{
}

void Home_scene::check_buttons()
{
    check_play_button();
    check_setting_button();
    check_quit_button();
}

void Home_scene::check_play_button()
{
    Vector2 mouse_pos = GetMousePosition();
    this->_play_button->_action = false;
    if (CheckCollisionPointRec(mouse_pos, this->_play_button->_bounds)) {
        this->_play_button->change_texture("assets/button_over.png");
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            this->_play_button->_state = 2;
        } else {
            this->_play_button->_state = 1;
        }
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            this->_play_button->_action = true;
    } else {
        this->_play_button->change_texture("assets/button.png");
        this->_play_button->_state = 0;
    }
    if (this->_play_button->_action) {
        printf("Play button has pressed. ✅\n");
        PlaySound(this->_play_button->_fx);
    }
}

void Home_scene::check_setting_button()
{
    Vector2 mouse_pos = GetMousePosition();
    this->_setting_button->_action = false;
    if (CheckCollisionPointRec(mouse_pos, this->_setting_button->_bounds)) {
        this->_setting_button->change_texture("assets/button_over.png");
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            this->_setting_button->_state = 2;
        else 
            this->_setting_button->_state = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            this->_setting_button->_action = true;
    } else {
        this->_setting_button->change_texture("assets/button.png");
        this->_setting_button->_state = 0;
    }
    if (this->_setting_button->_action) {
        printf("setting button has pressed. 🛠\n");
        PlaySound(this->_setting_button->_fx);
    }
}

void Home_scene::check_quit_button()
{
    Vector2 mouse_pos = GetMousePosition();
    this->_quit_button->_action = false;
    if (CheckCollisionPointRec(mouse_pos, this->_quit_button->_bounds)) {
        this->_quit_button->change_texture("assets/button_over.png");
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            this->_quit_button->_state = 2;
        else 
            this->_quit_button->_state = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            this->_quit_button->_action = true;
    } else {
        this->_quit_button->change_texture("assets/button.png");
        this->_quit_button->_state = 0;
    }
    if (this->_quit_button->_action) {
        printf("quit button has pressed. ❌\n");
        PlaySound(this->_quit_button->_fx);
    }
}

void Home_scene::draw_buttons()
{
    DrawTextureRec(this->_play_button->_texture, this->_play_button->_source,
    (Vector2){ this->_play_button->_bounds.x, this->_play_button->_bounds.y }, WHITE);
    DrawText("Jouer", 921,
            this->_play_button->_bounds.y + this->_play_button->_texture.height/2 - 15,
            30, WHITE);

    DrawTextureRec(this->_setting_button->_texture, this->_setting_button->_source,
    (Vector2){ this->_setting_button->_bounds.x, this->_setting_button->_bounds.y }, WHITE);
    DrawText("Options", 905,
            this->_setting_button->_bounds.y + this->_setting_button->_texture.height/2 - 15,
            30, WHITE);

    DrawTextureRec(this->_quit_button->_texture, this->_quit_button->_source,
    (Vector2){ this->_quit_button->_bounds.x, this->_quit_button->_bounds.y }, WHITE);
    DrawText("Quitter", 910,
            this->_quit_button->_bounds.y + this->_quit_button->_texture.height/2 - 13,
            30, WHITE);
}

void Home_scene::draw_textures()
{
    DrawTexture(this->_background->_texture, this->_background->_pos.x, this->_background->_pos.y, WHITE);
    DrawTexture(this->_title->_texture, this->_title->_pos.x, this->_title->_pos.y, WHITE);
}

void Home_scene::draw()
{
    draw_textures();
    draw_buttons();
}

#endif /* !HOME_SCENE_HPP_ */
