//
// Created by tomfr on 22/10/2024.
//

#include "../header/Shader.hpp"

Shader::Shader() : shader_id(0), vertex_shader_source(),fragment_shader_source(){}
Shader::Shader(const char* vertex_path, const char* fragment_path) : shader_id(),vertex_shader_source(),fragment_shader_source()  {
    load_shader(vertex_path,fragment_path);
}
void Shader::load_shader(const char *vertex_path, const char *fragment_path) {
    std::fstream vertex_file, fragment_file;

    vertex_file.exceptions(std::fstream::failbit | std::fstream::badbit);
    fragment_file.exceptions(std::fstream::failbit | std::fstream::badbit);

    try{
        vertex_file.open(vertex_path);
        fragment_file.open(fragment_path);
        std::stringstream vertex_stream_file, fragment_stream_file;

        vertex_stream_file << vertex_file.rdbuf();
        fragment_stream_file << fragment_file.rdbuf();

        this->vertex_shader_source = vertex_stream_file.str();
        this->fragment_shader_source = fragment_stream_file.str();

        vertex_file.close();
        fragment_file.close();
    }catch(std::exception& e){
        std::cerr << "ERROR DURING SHADER FILE PROCESSING :: " << e.what() << std::endl;
        return;
    }
    std::cout << "SHADER SOURCE ARE CORRECTLY LOADED" << std::endl;
}

void Shader::create_shader() {
    GLint succes;
    GLchar info_log[512];
    GLuint vertex_id;

    const char *vertex_source = vertex_shader_source.c_str();
    const char *fragment_source = fragment_shader_source.c_str();

    vertex_id = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_id,1,&vertex_source,nullptr);
    glCompileShader(vertex_id);

    glGetShaderiv(vertex_id,GL_COMPILE_STATUS,&succes);
    if(!succes){
        glGetShaderInfoLog(vertex_id, sizeof(GLchar) * 512, nullptr,info_log);
        std::cerr << "ERROR :: Vertex Shader CANNOT COMPILE :: " << info_log << std::endl;
    }

    GLuint fragment_id;
    fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_id,1,&fragment_source, nullptr);
    glCompileShader(fragment_id);

    glGetShaderiv(fragment_id,GL_COMPILE_STATUS,&succes);
    if(!succes){
        glGetShaderInfoLog(fragment_id, sizeof(GLchar) * 512, nullptr,info_log);
        std::cout << "ERROR :: FRAGMENT SHADER CANNOT COMPILE :: " << info_log << std::endl;
    }

    this->shader_id = glCreateProgram();
    glAttachShader(shader_id,vertex_id);
    glAttachShader(shader_id,fragment_id);
    glLinkProgram(shader_id);

    glGetProgramiv(shader_id,GL_LINK_STATUS,&succes);
    if(!succes){
        glGetProgramInfoLog(shader_id, sizeof(GLchar) * 512, nullptr,info_log);
        std::cout << "ERROR  :: SHADER PROGRAM LINK FAILED :: " << info_log << std::endl;
    }

    glDeleteShader(vertex_id);
    glDeleteShader(fragment_id);
}
void Shader::set_uniform_vec3(const std::string &name, const glm::vec3 &value) const {
    glUniform3fv(glGetUniformLocation(shader_id,name.c_str()),1,glm::value_ptr(value));
}

void Shader::set_uniform_vec2(const std::string &name, const glm::vec2& value) const {
    glUniform2fv(glGetUniformLocation(shader_id,name.c_str()),1,glm::value_ptr(value));
}
void Shader::set_uniform_mat4(const std::string& name,const glm::mat4& value) const {
    glUniformMatrix4fv(glGetUniformLocation(shader_id,name.c_str()),1,false,glm::value_ptr(value));
}

void Shader::enable_program() const {
    glUseProgram(shader_id);
}
Shader::~Shader(){
    glDeleteProgram(shader_id);
}
