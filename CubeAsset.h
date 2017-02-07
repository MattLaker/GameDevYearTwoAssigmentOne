#ifndef CUBEASSET_H
#define CUBEASSET_H

#include <vector>

#include <SDL2/SDL.h>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class CubeAsset : public GameAsset {
 public:
  CubeAsset(GLfloat, GLfloat, GLfloat);
  ~CubeAsset();
  virtual void Draw(GLuint);
  glm::vec3 getColour();
  void setColour(float, float, float);

 private:
  GLuint element_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token;
  glm::vec3 colour_token;
};

#endif // CUBEASSET_H
