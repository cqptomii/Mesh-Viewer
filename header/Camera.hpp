//
// Created by tomfr on 21/10/2024.
//

#ifndef MESH_VIEWER_CAMERA_HPP
#define MESH_VIEWER_CAMERA_HPP
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
class Camera {
private:
glm::vec3 cam_origin;
glm::vec3 cam_direction;
glm::vec3 v_up;
glm::vec3 axis_up;
glm::vec3 axis_rigth;
float fov; // For the perspective projection
float cam_yaw,cam_pitch;
float mouse_sensitivity;
float cam_speed;
bool cam_first_move;

float z_near;
float z_far;
float aspect_ratio;

    void load_cam_parameter();
public:
    Camera();
    Camera(glm::vec3 origin,glm::vec3 direction);
    glm::mat4 get_view_matrix();
    glm::mat4 get_projection_matrix() const;
    void process_cam_movement(unsigned int direction,float delta_time);
    void process_mouse_movement(float xOffset, float yOffset);
    void process_mouse_scroll(float xOffset, float yOffset);
};


#endif //MESH_VIEWER_CAMERA_HPP
