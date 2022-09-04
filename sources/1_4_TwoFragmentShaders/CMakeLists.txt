add_executable(1_4_TwoFragmentShaders)
target_sources(1_4_TwoFragmentShaders
  PRIVATE
  twoFragmentShaders.cpp
  )

target_link_libraries(1_4_TwoFragmentShaders
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )