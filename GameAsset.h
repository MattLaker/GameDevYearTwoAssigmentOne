#ifndef GAMEASSET_H
#define GAMEASSET_H

#include <iostream>
#include <memory>
#include <GL/gl.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>

class GameAsset {
 public:
  GameAsset();
  virtual void Draw(GLuint) = 0;
  glm::mat4 getModelMatrix();

 private:
  glm::mat4 model_matrix;
};

#endif
