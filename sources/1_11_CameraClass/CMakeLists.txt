add_executable(1_11_CameraClass)
target_sources(1_11_CameraClass
  PRIVATE
  cameraClass.cpp
  )

target_link_libraries(1_11_CameraClass
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )