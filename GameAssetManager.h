#ifndef GAMEASSETMANAGER_H
#define GAMEASSETMANAGER_H

#include <memory>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>

#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>

#include <GL/gl.h>

#include "common.h"
#include "GameAsset.h"
#include "Camera.h"

/**
 * GameAssetManager is a container for GameAssets.  It also provides utility
 * functions to to create a simple OpenGL program that can be used to draw a
 * simple GameAsset.
 */
class GameAssetManager {
 public:
  explicit GameAssetManager(ApplicationMode); // constructor
  virtual ~GameAssetManager();
  GameAssetManager(GameAssetManager const&); // copy constructor
  GameAssetManager(GameAssetManager const&&); // move constructor
  void operator=(GameAssetManager const&); // assignment
  void AddAsset(std::shared_ptr<GameAsset>);
  void Draw();
  void move_forward();
  void move_backward();
  void move_left();
  void move_right();
  void rotate_up();
  void rotate_down();
  void rotate_left();
  void rotate_right();
 private:
  GLuint CreateGLProgram(std::string &, std::string &);
  GLuint CreateGLESShader(GLenum, std::string &);
  // As this is private and we're writing to the GPU, we will use raw pointers.
  std::pair<GLchar *, GLint>  ReadShader(std::string &);
  std::shared_ptr<Camera> camera;
  // The internal scene graph is a simple list.
  std::vector<std::shared_ptr<GameAsset>> draw_list;
  GLuint program_token;
};

#endif // GAMEASSETMANAGER_H