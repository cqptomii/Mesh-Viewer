//
// Created by tomfr on 22/10/2024.
//

#ifndef MESH_VIEWER_TEXTURE_HPP
#define MESH_VIEWER_TEXTURE_HPP
#define STB_IMAGE_IMPLEMENTATION

#include <glad/glad.h>
#include "stb_image.h"
#include <iostream>

class Texture {
private:
    std::string t_path;
    GLuint t_id;
    GLint wrap_param_s;
    GLint wrap_param_t;
    GLint mag_filter;
    GLint min_filter;
    void create_texture();
public:
    Texture();
    Texture(const char* texture_path);
    ~Texture();

};


#endif //MESH_VIEWER_TEXTURE_HPP
