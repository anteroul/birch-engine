#pragma once

#include <glm/glm.hpp>

// Default camera values
#define YAW (-90.0f)
#define PITCH 10.0f
#define SPEED 0.01f
#define SENSITIVITY 0.18f

class Camera {
public:
    // constructor with vectors
    explicit Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
    void translate(const glm::vec3 &position, const glm::vec3 &frontVector);
    const glm::mat4 &getView() const { return view; }
    const glm::mat4 &getProjection() const { return projection; }
    const glm::vec3 &getFront() const { return front; }
    const glm::vec3 &getUp() const { return up; }
    float getSpeed() const { return movementSpeed; }
    const glm::vec3 &getPosition() const { return position; }

    // calculate new front vector
    glm::vec3 getNewFrontVector();

    // processes input received from a mouse input system. Expects the offset value in both the x and y direction.
    void processMouseMovement(float x_offset, float y_offset, bool constrainPitch = true);

    // euler Angles
    float yaw;
    float pitch;
private:
    void updateCameraVectors(const glm::vec3 &frontVector);

    // camera Attributes
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;

    // camera options
    float movementSpeed;
    float mouseSensitivity;

    glm::mat4 view;
    glm::mat4 projection;
    glm::vec3 position;
};
