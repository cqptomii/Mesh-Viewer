//
// Created by tomfr on 22/10/2024.
//

#include "../header/Texture.hpp"
Texture::Texture() : t_id(),t_path(),wrap_param_s(GL_LINEAR),wrap_param_t(GL_LINEAR),min_filter(GL_LINEAR),mag_filter(GL_LINEAR) {}

Texture::Texture(const char *texture_path) :t_id(), t_path(texture_path),wrap_param_s(GL_LINEAR),wrap_param_t(GL_LINEAR),min_filter(GL_LINEAR),mag_filter(GL_LINEAR) {
    create_texture();
}
void Texture::create_texture() {
    int width,heigth,nb_channel;
    unsigned char* data = stbi_load(this->t_path.c_str(),&width,&heigth,&nb_channel, 0);
    if(!data){
        std::cerr << "ERROR :: TEXTURE LOADING FAILED " << std::endl;
        return;
    }
    GLenum format;
    if(nb_channel == 1){
        format = GL_RED;
    }else if(nb_channel == 3){
        format = GL_RGB;
    }else if(nb_channel == 4){
        format = GL_RGBA;
    }else{
        std::cerr << "ERROR :: WRONG TEXTURE FORMAT " << nb_channel << std::endl;
        return;
    }

    GLuint temp_id;
    glGenTextures(1, &temp_id);

    glTexParameteri(temp_id,GL_TEXTURE_WRAP_S,wrap_param_s);
    glTexParameteri(temp_id,GL_TEXTURE_WRAP_T,wrap_param_t);
    glTexParameteri(temp_id,GL_TEXTURE_MAG_FILTER,mag_filter);
    glTexParameteri(temp_id,GL_TEXTURE_MIN_FILTER,min_filter);


    glTexImage2D(GL_TEXTURE_2D,0,format,width,heigth,0,format,GL_UNSIGNED_BYTE,data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
    this->t_id = temp_id;
}

Texture::~Texture() {
    glDeleteTextures(1,&t_id);
}
