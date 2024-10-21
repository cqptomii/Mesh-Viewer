//
// Created by tomfr on 21/10/2024.
//

#ifndef MESH_VIEWER_CAMERA_HPP
#define MESH_VIEWER_CAMERA_HPP
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
enum mov_type{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGTH
};
class Camera {
private:
glm::vec3 cam_origin;
glm::vec3 cam_direction;
glm::vec3 v_up;
glm::vec3 axis_up;
glm::vec3 axis_rigth;
double fov;
double cam_yaw,cam_pitch;
double mouse_sensitivity;
double cam_speed;
bool cam_first_move = false;
public:
    Camera();
    Camera(glm::vec3 origin,glm::vec3 direction);
    glm::mat4 get_view_matrix();
    void process_cam_movement(mov_type direction,float delta_time);
    void process_mouse_movement(float xOffset, float yOffset);
    void process_mouse_scroll(float xOffset, float yOffset);
};


#endif //MESH_VIEWER_CAMERA_HPP
