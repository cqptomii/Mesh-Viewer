//
// Created by tomfr on 21/10/2024.
//

#include "../header/Camera.hpp"

Camera::Camera() : cam_origin(glm::vec3(0.0f,0.0f,0.0f)), cam_direction(glm::vec3(0.0f,0.0f,-1.0f)),v_up(glm::vec3(0.0f,1.0f,0.0f)), axis_up(),axis_rigth(),fov(45.0f),cam_yaw(-90.0f),cam_pitch(0.0f),mouse_sensitivity(0.5f),cam_speed(2.5f),cam_first_move(true),z_near(0.1f),z_far(100.0f),aspect_ratio(16/9) {
    load_cam_parameter();
}

Camera::Camera(glm::vec3 origin, glm::vec3 direction) : cam_origin(origin),cam_direction(direction), v_up(glm::vec3(0.0f,1.0f,0.0f)), axis_up(),axis_rigth(),fov(45.0f),cam_yaw(-90.0f),cam_pitch(0.0f),mouse_sensitivity(0.5f),cam_speed(2.5f), cam_first_move(true),z_near(0.1f),z_far(100.0f),aspect_ratio(16/9){
    load_cam_parameter();
}

void Camera::load_cam_parameter() {
    glm::vec3 direction = glm::vec3(1.0f);
    direction.x = glm::cos(glm::radians(cam_pitch)) * glm::cos(glm::radians(cam_yaw));
    direction.y = glm::sin(glm::radians(cam_yaw));
    direction.y = glm::cos(glm::radians(cam_pitch)) * glm::sin(glm::radians(cam_yaw));
    cam_direction = glm::normalize(direction);

    axis_up = glm::cross(v_up,cam_direction);
    axis_rigth = glm::cross(cam_direction,axis_up);
}

glm::mat4 Camera::get_view_matrix() {
    return glm::lookAt(cam_origin,cam_origin + cam_direction ,v_up);
}
glm::mat4 Camera::get_projection_matrix() const {
    return glm::perspective(this->fov,this->aspect_ratio,this->z_near,this->z_far);
}

void Camera::process_cam_movement(unsigned int direction, float delta_time) {
    float velocity = delta_time * cam_speed;
    if(direction == GL_BACK){
        cam_origin -= cam_direction*velocity;
    }else if(direction == GL_FRONT){
        cam_origin += cam_direction*velocity;
    }else if(direction == GL_LEFT){
        cam_origin -= axis_rigth*velocity;
    }else if(direction == GL_RIGHT){
        cam_direction += axis_rigth*velocity;
    }
}

void Camera::process_mouse_movement(float xOffset, float yOffset) {
    // yOffset -> Pitch / xOffset -> yaw

    cam_pitch += yOffset*mouse_sensitivity;
    cam_yaw += xOffset*mouse_sensitivity;
    if(cam_pitch > 90.0f)
        cam_pitch = 90.0f;
    if(cam_pitch < -90.0f)
        cam_pitch = 90.0f;

    // Update cam parameter
    load_cam_parameter();
}

void Camera::process_mouse_scroll(float xOffset, float yOffset) {
    fov -= yOffset;
    if(fov < 1.0f)
        fov = 1.0f;
    if(fov > 55.0f)
        fov = 55.0f;
}