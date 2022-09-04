add_executable(1_1_DrawTriangle)
target_sources(1_1_DrawTriangle PRIVATE
  1-1drawTriangle.cpp
  )

target_link_libraries(1_1_DrawTriangle
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )