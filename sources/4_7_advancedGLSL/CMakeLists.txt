add_executable(4_7_AdvancedGLSL)

file(GLOB SRC ./ *.cpp
  )

target_sources(4_7_AdvancedGLSL
  PRIVATE
  ${SRC}
  )

target_link_directories(4_7_AdvancedGLSL PRIVATE ${PROJECT_SOURCE_DIR}/Libs)

target_link_libraries(4_7_AdvancedGLSL
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )