add_executable(4_7_AdvancedGLSLUniformBuffer)

file(GLOB SRC ./ *.cpp
  )

target_sources(4_7_AdvancedGLSLUniformBuffer
  PRIVATE
  ${SRC}
  )

target_link_directories(4_7_AdvancedGLSLUniformBuffer PRIVATE ${PROJECT_SOURCE_DIR}/Libs)

target_link_libraries(4_7_AdvancedGLSLUniformBuffer
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )