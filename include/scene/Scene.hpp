/*
** EPITECH PROJECT, 2022
** menu_indie
** File description:
** scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <iostream>
#include "./Home_scene.hpp"
#include "./Setting_scene.hpp"
#include "./Tuto_scene.hpp"

class Scene
{
    public:
        Scene();
        ~Scene();

        Home_scene *_home_scene;
        Setting_scene *_setting_scene;
        Tuto_scene *_tuto_scene;

        int _selector_scene;
        bool _sound;
        Music _music;

        void select_scene();
        void set_scene_selector(int x);
};

Scene::Scene()
{
    this->_home_scene = new Home_scene();
    this->_setting_scene = new Setting_scene();
    this->_tuto_scene = new Tuto_scene();
    set_scene_selector(0);
    this->_sound = true;
    this->_music = LoadMusicStream("assets/Harry_firework.mp3");
}

Scene::~Scene()
{
}

void Scene::select_scene()
{
    if (this->_selector_scene == 0) {
        this->_selector_scene = this->_home_scene->_selector_scene;
    } else if (this->_selector_scene == 1) {
        this->_selector_scene = this->_setting_scene->_scene_selector;
    } else if (this->_selector_scene == 2) {
        this->_selector_scene = this->_tuto_scene->_scene_selector;
    }
}

void Scene::set_scene_selector(int x)
{
    this->_selector_scene = x;
}

#endif /* !SCENE_HPP_ */
