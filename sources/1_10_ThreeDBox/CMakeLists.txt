add_executable(1_10_ThreeDBox)
target_sources(1_10_ThreeDBox
  PRIVATE
  threeDbox.cpp
  )

target_link_libraries(1_10_ThreeDBox
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )