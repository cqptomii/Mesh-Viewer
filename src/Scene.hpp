//
// Created by tomfr on 22/10/2024.
//

#ifndef MESH_VIEWER_SCENE_HPP
#define MESH_VIEWER_SCENE_HPP
#include "Mesh.hpp"
#include <iostream>
#include <vector>

class Scene {
private:
    std::vector<Mesh*> mesh_object;
public:
    Scene();
    void onDraw();
};

#endif //MESH_VIEWER_SCENE_HPP
