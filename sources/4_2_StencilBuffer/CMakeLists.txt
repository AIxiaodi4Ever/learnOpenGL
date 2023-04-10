add_executable(4_2_StencilBuffer)

file(GLOB SRC ./ *.cpp
  )

target_sources(4_2_StencilBuffer
  PRIVATE
  ${SRC}
  )

target_link_directories(4_2_StencilBuffer PRIVATE ${PROJECT_SOURCE_DIR}/Libs)

target_link_libraries(4_2_StencilBuffer
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )