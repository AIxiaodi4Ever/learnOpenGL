add_executable(4_1_DepthBuffer)

file(GLOB SRC ./ *.cpp
  )

target_sources(4_1_DepthBuffer
  PRIVATE
  ${SRC}
  )

target_link_directories(4_1_DepthBuffer PRIVATE ${PROJECT_SOURCE_DIR}/Libs)

target_link_libraries(4_1_DepthBuffer
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )