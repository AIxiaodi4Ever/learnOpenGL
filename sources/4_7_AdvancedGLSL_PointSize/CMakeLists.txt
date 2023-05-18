add_executable(4_7_AdvancedGLSL_PointSize)

file(GLOB SRC ./ *.cpp
  )

target_sources(4_7_AdvancedGLSL_PointSize
  PRIVATE
  ${SRC}
  )

target_link_directories(4_7_AdvancedGLSL_PointSize PRIVATE ${PROJECT_SOURCE_DIR}/Libs)

target_link_libraries(4_7_AdvancedGLSL_PointSize
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )