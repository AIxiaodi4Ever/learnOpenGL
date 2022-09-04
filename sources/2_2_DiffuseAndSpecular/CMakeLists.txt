add_executable(2_2_DiffuseAndSpecular)
target_sources(2_2_DiffuseAndSpecular
  PRIVATE
  2-04-1.cpp
  )

target_link_libraries(2_2_DiffuseAndSpecular
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )