//
// Created by tomfr on 22/10/2024.
//

#ifndef MESH_VIEWER_SHADER_HPP
#define MESH_VIEWER_SHADER_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
private:
    GLuint shader_id;
    std::string vertex_shader_source;
    std::string fragment_shader_source;
    void load_shader(const char* vertex_path, const char* fragment_path);
public:
    Shader();
    Shader(const char* vertex_path,const char* fragment_path);
    ~Shader();
    void create_shader();
    void set_uniform_vec3(const std::string& name, const glm::vec3& value )const;
    void set_uniform_vec2(const std::string& name,const glm::vec2& value)const;
    void set_uniform_mat4(const std::string& name, const glm::mat4& value) const;
    void enable_program() const;
};


#endif //MESH_VIEWER_SHADER_HPP
