add_executable(1_7_ShaderClass)
target_sources(1_7_ShaderClass
  PRIVATE
  1-6-3shaders_class.cpp
  )

target_link_libraries(1_7_ShaderClass
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )