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
// #include "./Setting_scene.hpp"

class Scene
{
    public:
        Scene();
        ~Scene();

        Home_scene *_home_scene;
        // int _selector;

        // void set_scene_selector(int x);
};

Scene::Scene()
{
    this->_home_scene = new Home_scene();
    // set_scene_selector(0);
}

Scene::~Scene()
{
}

// void Scene::set_scene_selector(int x)
// {
//     this->_selector = x;
// }

#endif /* !SCENE_HPP_ */
