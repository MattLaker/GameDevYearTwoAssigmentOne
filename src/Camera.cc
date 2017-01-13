#define _USE_MATH_DEFINES
#include <math.h>

#include "Camera.h"

Camera::Camera(){
	view_matrix = glm::mat4(
             glm::vec4(1.0, 0.0, 0.0, 0.0),
             glm::vec4(0.0, 1.0, 0.0, 0.0),
             glm::vec4(0.0, 0.0, 1.0, 0.0),
             glm::vec4(-2.0, 0.0, 0.0, 1.0)
           );
}

Camera::~Camera(){
}

glm::mat4 Camera::getViewMatrix(){
	return view_matrix;
}

void Camera::move_x (float x){
	glm::mat4 m = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    	glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(x, 0.0, 0.0, 1.0)
	);
	view_matrix = m * view_matrix;
}

void Camera::move_z (float z){
	float hyp = z;
	float adj = hyp * (cos(angle*M_PI/180));
	float opp = sqrt((hyp*hyp) - (adj*adj));
	if(angle < 0) {
		opp = opp *-1;
	}
	if(z < 0) {
		opp = opp * -1;
	}

	glm::mat4 m = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(0.0, opp, adj, 1.0)
	);
	view_matrix = m * view_matrix;
}

void Camera::rotate_y (float theta){
	glm::mat4 m = glm::mat4(
		glm::vec4(cos(theta), 0.0, sin(theta), 0.0),
       		glm::vec4(0.0, 1.0, 0.0, 0.0),
       		glm::vec4(-sin(theta), 0.0, cos(theta), 0.0),
        	glm::vec4(0.0, 0.0, 0.0, 1.0)
	);			
	view_matrix = m * view_matrix ;
}

void Camera::rotate_x (float theta){
	angle = angle + (theta*60);

	glm::mat4 m = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
		glm::vec4(0.0, cos(theta), -sin(theta), 0.0),
		glm::vec4(0.0, sin(theta), cos(theta), 0.0),
		glm::vec4(0.0, 0.0, 0.0, 1.0)
	);
	view_matrix = m * view_matrix ;
}

void Camera::reset() {
	glm::mat4 identity = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(0.0, 0.0, 0.0, 1.0)
	);
	view_matrix = identity;
}

void Camera::Draw(GLuint) {
}

float Camera::getAngle() {
	return angle;
}
