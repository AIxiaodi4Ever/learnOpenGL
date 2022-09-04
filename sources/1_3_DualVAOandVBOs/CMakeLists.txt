add_executable(1_3_DualVAOandVBOs)
target_sources(1_3_DualVAOandVBOs
  PRIVATE
  twoVAOsandVBOs.cpp
  )

target_link_libraries(1_3_DualVAOandVBOs
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )