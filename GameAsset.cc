#include "GameAsset.h"

GameAsset::GameAsset(){
	glm::mat4 m = glm::mat4(
			glm::vec4(1.0, 0.0, 0.0, 0.0),
             		glm::vec4(0.0, 1.0, 0.0, 0.0),
			glm::vec4(0.0, 0.0, 1.0, 0.0),
			glm::vec4(0.0, 0.0, 0.0, 1.0)
	);
	model_matrix = m;
}

//void GameAsset::translate(float x, float y, float z){
//manipulate the model matrix to represent an x, y, z translation.
//	glm::mat4 m = glm::mat4(
//				glm::vec4(1.0, 0.0, 0.0, 0.0),
  //           			glm::vec4(0.0, 1.0, 0.0, 0.0),
//			     	glm::vec4(0.0, 0.0, 1.0, 0.0),
//			     	glm::vec4(x, y, z, 1.0)
//	);
//	model_matrix = model_matrix * m;
//}

glm::mat4 GameAsset::getModelMatrix(){
return model_matrix;
}
