add_executable(4_6_Skybox)

file(GLOB SRC ./ *.cpp
  )

target_sources(4_6_Skybox
  PRIVATE
  ${SRC}
  )

target_link_directories(4_6_Skybox PRIVATE ${PROJECT_SOURCE_DIR}/Libs)

target_link_libraries(4_6_Skybox
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )