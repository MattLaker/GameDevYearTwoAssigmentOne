#include "GameAsset.h"

GameAsset::GameAsset(){
	glm::mat4 m = glm::mat4(
			glm::vec4(1.0, 0.0, 0.0, 0.0),
             		glm::vec4(0.0, 1.0, 0.0, 0.0),
			glm::vec4(0.0, 0.0, 1.0, 0.0),
			glm::vec4(0.0, 0.0, 0.0, 1.0)
	);
	model_matrix = m;

	Vector3 v = Vector3(0.0, 0.0, 0.0);
	float width = 1;
	float length = 1;
	float depth = 1;
	bbox = std::make_shared<AABoundingBox>(v, width, length, depth);
}

glm::mat4 GameAsset::getModelMatrix(){
return model_matrix;
}

std::shared_ptr<AABoundingBox> GameAsset::getBBox(){
  return bbox;
}
