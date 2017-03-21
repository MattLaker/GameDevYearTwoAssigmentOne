#include "CubeAsset.h"

CubeAsset::CubeAsset(float x, float y, float z) {
  Vector3 v = Vector3(x, y, z);
  bbox = std::make_shared<AABoundingBox>(v, 1.0f, 1.0f, 1.0f);

  // model coordinates, origin at centre.
	GLfloat size = 0.5;
  GLfloat vertex_buffer [] {
    //front face of cube
        x-size, y-size, z+size		//0
      , x-size, y+size, z+size		//1
      , x+size, y-size, z+size		//2
      , x+size, y+size, z+size		//3
    //back face of cube
      , x-size, y-size, z-size		//4
      , x-size, y+size, z-size		//5
      , x+size, y-size, z-size		//6
      , x+size, y+size, z-size	  	//7
  };
  

  element_buffer_length = 36;
  GLuint element_buffer []  {
    //front
       0, 2, 1
    ,  1, 2, 3
    //back
    ,  4, 6, 5
    ,  5, 6, 7
    //top
    ,  1, 3, 5
    ,  5, 3, 7
    //bottom
    ,  0, 2, 4
    ,  4, 2, 6
    //left
    ,  4, 0, 5
    ,  5, 0, 1
    //right
    ,  2, 6, 3
    ,  3, 6, 7
	 
 };

  // Transfer buffers to the GPU
  //

  // create buffer
  glGenBuffers(1, &vertex_buffer_token);

  // immediately bind the buffer and transfer the data
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 24, vertex_buffer, GL_STATIC_DRAW);

  glGenBuffers(1, &element_buffer_token);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * element_buffer_length, element_buffer, GL_STATIC_DRAW);

}

CubeAsset::~CubeAsset() {
}

#ifdef DEBUG
#define checkGLError() checkError(__FILE__, __LINE__)
#else
// define symbol to be nothing
#define checkGLError()
#endif

void checkError(std::string file, int line) {
  GLenum gl_error = glGetError();
  if(GL_NO_ERROR != gl_error) {
    std::cerr << "GL error in " << file << " at line " << line << " error: " << gl_error << std::endl;
    exit(-1);
  }
}
void CubeAsset::Draw(GLuint program_token) {
	glm::mat4 m = this->getModelMatrix();
	GLuint model_uniform = glGetUniformLocation(program_token, "model");
	glUniformMatrix4fv(model_uniform, 1, false, glm::value_ptr(m));

	glm::vec3 c = this->getColour();
	GLuint colour_uniform = glGetUniformLocation(program_token, "colour");
	glUniform3fv(colour_uniform, 1, glm::value_ptr(c));


  if(!glIsProgram(program_token)) {
    std::cerr << "Drawing Cube with invalid program" << std::endl;
    return;
  }
  GLint validation_ok;
  glValidateProgram(program_token);
  glGetProgramiv(program_token, GL_VALIDATE_STATUS, &validation_ok);
  if(!validation_ok) {
    GLint maxLength = 0;
    glGetProgramiv(program_token, GL_INFO_LOG_LENGTH, &maxLength);

    //The maxLength includes the NULL character
    std::vector<char> errorLog(maxLength);
    glGetProgramInfoLog(program_token, maxLength, &maxLength, &errorLog[0]);

    std::cerr << "Invalid program " << program_token << " with error code " << validation_ok << std::endl;
    for(auto c: errorLog) {
      std::cerr << c;
    }
    exit(-1);
  }

  GLuint position_attrib = glGetAttribLocation(program_token, "position");
  checkGLError();

  glUseProgram(program_token);
  checkGLError();

  // use the previously transferred buffer as the vertex array.  This way
  // we transfer the buffer once -- at construction -- not on every frame.
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glVertexAttribPointer(
                        position_attrib,               /* attribute */
                        3,                             /* size */
                        GL_FLOAT,                      /* type */
                        GL_FALSE,                      /* normalized? */
                        0,                             /* stride */
                        (void*)0                       /* array buffer offset */
                        );
  glEnableVertexAttribArray(position_attrib);

  checkGLError();

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glDrawElements(
                 GL_TRIANGLES,
                 element_buffer_length,
                 GL_UNSIGNED_INT,
                 (GLvoid*) 0
                 );

  checkGLError();

  glDisableVertexAttribArray(position_attrib);
}

glm::vec3 CubeAsset::getColour() {
	return colour_token;
}

void CubeAsset::setColour(float r, float g, float b) {
	colour_token = glm::vec3(r, g, b);
}
