#include "GameAsset.h"

GameAsset::GameAsset(){
	glm::mat4 m = glm::mat4(
			glm::vec4(1.0, 0.0, 0.0, 0.0),
             		glm::vec4(0.0, 1.0, 0.0, 0.0),
			glm::vec4(0.0, 0.0, 1.0, 0.0),
			glm::vec4(0.0, 0.0, 0.0, 1.0)
	);
	model_matrix = m;

	glm::vec3 v = glm::vec3(0.0, 0.0, 0.0);
	glm::vec3 x = glm::vec3(0.5, 0.0, 0.0);
	glm::vec3 y = glm::vec3(0.0, 0.5, 0.0);
	glm::vec3 z = glm::vec3(0.0, 0.0, 0.5);
	//bbox = std::make_shared<AABoundingBox>(v, x, y, z);
}

glm::mat4 GameAsset::getModelMatrix(){
return model_matrix;
}

std::shared_ptr<AABoundingBox> GameAsset::getBBox(){
  return bbox;
}
