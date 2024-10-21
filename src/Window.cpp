//
// Created by tomfr on 21/10/2024.
//

#include <utility>

#include "../header/Window.hpp"

Window::Window() : window_ptr(nullptr),window_heigth(800),window_width((16/9) * 800),window_name("untitled"),use_depth(false) {
    init_window();
}

Window::Window(std::string title,bool use_depth) : window_ptr(nullptr),window_heigth(800), window_width((16/9) * 800),window_name(std::move(title)), use_depth(use_depth){
    init_window();
}

Window::Window(std::string title, int heigth, bool use_depth) : window_ptr(nullptr),window_heigth(heigth),window_width(window_heigth*(16/9)),window_name(std::move(title)),use_depth(use_depth) {
    init_window();
}

Window::~Window() {
    glfwDestroyWindow(this->window_ptr);
}
void Window::init_window(){
    this->window_ptr = glfwCreateWindow(window_width,window_heigth,this->window_name.c_str(),nullptr,nullptr);
    if(!window_ptr){
        std::cerr << "ERROR DURING GLFW WINDOW CREATION " << std::endl;
    }

    glfwMakeContextCurrent(window_ptr);

    // Pointeur utilisateur vers la fenetre actuel
    glfwSetWindowUserPointer(window_ptr,this);

    glfwSetWindowSizeCallback(window_ptr,window_size_callback);
    glfwSetCursorPosCallback(window_ptr,window_pos_callback);
    glfwSetScrollCallback(window_ptr,window_scroll_callback);

    //Ensure that glad is correctly set up
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
        throw std::runtime_error("ERROR :: GLAD IS NOT CORRECTLY LOADED");
    }
    if(use_depth)
        glEnable(GL_DEPTH_TEST);
}

void Window::main_loop() {

    while(!glfwWindowShouldClose(window_ptr)){

        glClearColor(0.2f,0.2f,0.2f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Draw our objects

        glfwSwapBuffers(window_ptr);
        glfwPollEvents();
    }
}

void Window::window_size_callback(GLFWwindow *window,GLint width, GLint heigth) {
    glViewport(0,0,width,heigth);
}

void Window::window_pos_callback(GLFWwindow *window, double xpos, double ypos) {
    auto* current_window = static_cast<Window*>(glfwGetWindowUserPointer(window));
    double xOffset = xpos;
    double yOffset = ypos;
}

void Window::window_scroll_callback(GLFWwindow *window, double xOffset, double yOffset) {

}

void Window::process_input() {
    if(glfwGetKey(window_ptr,GLFW_KEY_D)== GLFW_TRUE){

    }else if(glfwGetKey(window_ptr,GLFW_KEY_Q) == GLFW_TRUE){

    }else if(glfwGetKey(window_ptr,GLFW_KEY_S) == GLFW_TRUE){

    }else if(glfwGetKey(window_ptr,GLFW_KEY_W) == GLFW_TRUE){

    }
}

