add_executable(4_5_FrameBuffer)

file(GLOB SRC ./ *.cpp
  )

target_sources(4_5_FrameBuffer
  PRIVATE
  ${SRC}
  )

target_link_directories(4_5_FrameBuffer PRIVATE ${PROJECT_SOURCE_DIR}/Libs)

target_link_libraries(4_5_FrameBuffer
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )