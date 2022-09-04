add_executable(2_1_LightCube)
target_sources(2_1_LightCube
  PRIVATE
  2-01-1lightCube.cpp
  )

target_link_libraries(2_1_LightCube
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )