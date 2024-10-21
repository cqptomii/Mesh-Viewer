//
// Created by tomfr on 21/10/2024.
//

#ifndef MESH_VIEWER_WINDOW_HPP
#define MESH_VIEWER_WINDOW_HPP
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
private:
    GLFWwindow* window_ptr;
    int window_heigth;
    int window_width;
    std::string window_name;
    bool use_depth;

    double x_cursor_pos;
    double y_cursor_pos;

    void init_window();
public:
    Window();
    Window(std::string title,bool use_depth);
    Window(std::string title,int heigth,bool use_depth);
    ~Window();
    void main_loop();
    static void window_size_callback(GLFWwindow* window,GLint width, GLint heigth);
    static void window_pos_callback(GLFWwindow* window,double xpos, double ypos);
    static void window_scroll_callback(GLFWwindow* window,double xOffset, double yOffset);
    void process_input();
};


#endif //MESH_VIEWER_WINDOW_HPP
