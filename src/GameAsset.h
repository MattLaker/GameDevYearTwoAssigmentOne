#ifndef GAMEASSET_H
#define GAMEASSET_H

#include <iostream>
#include <memory>
#include <GL/gl.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>

#include "AABoundingBox.h"
#include "GameMaths.h"

class GameAsset {
 public:
  GameAsset();
  virtual void Draw(GLuint) = 0;
  glm::mat4 getModelMatrix();
  std::shared_ptr<AABoundingBox> getBBox();

 private:
  glm::mat4 model_matrix;

 protected:
  std::shared_ptr<AABoundingBox> bbox;
};

#endif
