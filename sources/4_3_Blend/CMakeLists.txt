add_executable(4_3_Blend)

file(GLOB SRC ./ *.cpp
  )

target_sources(4_3_Blend
  PRIVATE
  ${SRC}
  )

target_link_directories(4_3_Blend PRIVATE ${PROJECT_SOURCE_DIR}/Libs)

target_link_libraries(4_3_Blend
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )