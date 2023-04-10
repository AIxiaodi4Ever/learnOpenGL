add_executable(4_6_EnvironmentMapRefract)

file(GLOB SRC ./ *.cpp
  )

target_sources(4_6_EnvironmentMapRefract
  PRIVATE
  ${SRC}
  )

target_link_directories(4_6_EnvironmentMapRefract PRIVATE ${PROJECT_SOURCE_DIR}/Libs)

target_link_libraries(4_6_EnvironmentMapRefract
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )