#define _USE_MATH_DEFINES
#include <math.h>

#include "Camera.h"
#include <iostream>
Camera::Camera(){
	view_matrix = glm::mat4(
             glm::vec4(1.0f, 0.0f, 0.0f, 0.0f),
             glm::vec4(0.0f, 1.0f, 0.0f, 0.0f),
             glm::vec4(0.0f, 0.0f, 1.0f, 0.0f),
             glm::vec4(-2.0f, 0.0f, 0.0f, 1.0f)
           );

	glm::mat4 m = getViewMatrix();
	Vector3 v = Vector3(m[3][0], m[3][1], m[3][2]);
	bbox = std::make_shared<AABoundingBox>(v, 1.0f, 1.0f, 1.0f);
}

Camera::~Camera(){
}

glm::mat4 Camera::getViewMatrix(){
	return view_matrix;
}

void Camera::move_x (float x){
	view_matrix = glm::translate(view_matrix, glm::vec3(x, 0.0, 0.0));
	
	glm::mat4 m = getViewMatrix();
	Vector3 v = Vector3(m[3][0], m[3][1], m[3][2]);
	bbox->SetCentre(v);
	std::cout << m[3][0] << " " << m[3][1] << " " << m[3][2] << std::endl;
	
}

void Camera::move_z (float z){
	/*float hyp = z;
	float adj = hyp * (cos(angle*M_PI/180));
	float opp = sqrt((hyp*hyp) - (adj*adj));
	if(angle < 0) {
		opp = opp *-1;
	}
	if(z < 0) {
		opp = opp * -1;
	}

	view_matrix = glm::translate(view_matrix, glm::vec3(0.0, opp, adj));
*/
	view_matrix = glm::translate(view_matrix, glm::vec3(0.0, 0.0, z));
	
	glm::mat4 m = getViewMatrix();
	Vector3 v = Vector3(m[3][0], m[3][1], m[3][2]);
	bbox->SetCentre(v);
	std::cout << m[3][0] << " " << m[3][1] << " " << m[3][2] << std::endl;
	
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
	/*angle = angle + (theta*60);

	glm::mat4 m = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
		glm::vec4(0.0, cos(theta), -sin(theta), 0.0),
		glm::vec4(0.0, sin(theta), cos(theta), 0.0),
		glm::vec4(0.0, 0.0, 0.0, 1.0)
	);
	view_matrix = m * view_matrix; */
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

void Camera::greet() {
	std::cout << "hello, world" << std::endl;
}
