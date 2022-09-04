add_executable(1_2_DrawRectangle)
target_sources(1_2_DrawRectangle
  PRIVATE
  drawRectangle.cpp
  )

target_link_libraries(1_2_DrawRectangle
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )