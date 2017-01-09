#ifndef CAMERA_H
#define CAMERA_H


#include <memory>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "GameAsset.h"

class Camera : public GameAsset {
 public:
	Camera();
	~Camera();
	glm::mat4 getViewMatrix();
	void move_x(float);
	void move_z(float);
	void rotate_y(float);
	void rotate_x(float);
	void Draw(GLuint);
	
 private:
	glm::mat4 view_matrix;
};

#endif // CAMERA_H
