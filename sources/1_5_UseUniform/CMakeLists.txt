add_executable(1_5_UseUniform)
target_sources(1_5_UseUniform
  PRIVATE
  useUniform.cpp
  )

target_link_libraries(1_5_UseUniform
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )