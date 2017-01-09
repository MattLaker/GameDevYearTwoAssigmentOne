#include "Camera.h"

Camera::Camera(){
	view_matrix = glm::mat4(
             glm::vec4(1.0, 0.0, 0.0, 0.0),
             glm::vec4(0.0, 1.0, 0.0, 0.0),
             glm::vec4(0.0, 0.0, 1.0, 0.0),
             glm::vec4(0.0, 0.0, 0.0, 1.0)
           );
}

Camera::~Camera(){

}

glm::mat4 Camera::getViewMatrix(){
	return view_matrix;
}

void Camera::move_x (float x){
	glm::mat4 m = glm::mat4(
		glm::vec4(0.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 0.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 0.0, 0.0),
		glm::vec4(x, 0.0, 0.0, 0.0)
	);
	view_matrix += m;
}

void Camera::move_z (float z){
	glm::mat4 m = glm::mat4(
		glm::vec4(0.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 0.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, z, 0.0)
	);
	view_matrix += m;
}

void Camera::rotate_y (float theta){
	glm::mat4 m = glm::mat4(
		glm::vec4(cos(theta), 0.0, sin(theta), 0.0),
       		glm::vec4(0.0, 1.0, 0.0, 0.0),
        	glm::vec4(-sin(theta), 0.0, cos(theta), 0.0),
        	glm::vec4(0.0, 0.0, 0.0, 1.0)
	);
	view_matrix *= m;
}

void Camera::rotate_x (float theta){
	glm::mat4 m = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
		glm::vec4(0.0, cos(theta), sin(theta), 0.0),
		glm::vec4(0.0, -sin(theta), cos(theta), 0.0),
		glm::vec4(0.0, 0.0, 0.0, 1.0)
	);
	view_matrix *= m;
}

void Camera::Draw(GLuint) {
}
