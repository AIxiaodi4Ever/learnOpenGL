add_executable(1_8_RectangleTexture)
target_sources(1_8_RectangleTexture
  PRIVATE
  1-7-1rectangleTexture.cpp
  )

target_link_libraries(1_8_RectangleTexture
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )