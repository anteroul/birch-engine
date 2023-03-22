#include "Camera.h"
#include <SDL2/SDL.h>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
        : front(glm::vec3(0.0f, 0.0f, -1.0f)),
          movementSpeed(SPEED),
          mouseSensitivity(SENSITIVITY),
          position(position),
          worldUp(up),
          pitch(PITCH),
          yaw(YAW),
          view(glm::lookAt(position, position + front, up)),
          projection(glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f)) {
    updateCameraVectors(getNewFrontVector());
}

void Camera::translate(const glm::vec3 &position, const glm::vec3 &frontVector) {
    this->position += position;
    updateCameraVectors(frontVector);
    view = glm::translate(view, position);
}

void Camera::processMouseMovement(float x_offset, float y_offset, bool constrainPitch) {
    x_offset *= mouseSensitivity;
    y_offset *= mouseSensitivity;

    yaw += x_offset;
    pitch -= y_offset;

    // update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors(getNewFrontVector());
}

void Camera::updateCameraVectors(const glm::vec3 &frontVector) {
    // re-calculate the Right and Up vector
    right = glm::normalize(glm::cross(frontVector, worldUp));
    up = glm::normalize(glm::cross(right, frontVector));

    // update view matrix
    view = glm::lookAt(position, position + frontVector, up);
}

glm::vec3 Camera::getNewFrontVector() const {
    // calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(front);
    return front;
}

