#include <iostream>
#include "../header/Window.hpp"
int main() {
    if(!glfwInit()){
        std::cerr << "ERROR DURING GLFW INITIALISATION \n" << std::endl;
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    try{
        Window myWindow = Window("test",false);

        myWindow.main_loop();
    }catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwTerminate();
    return 0;
}
