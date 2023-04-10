add_executable(4_6_EnvironmentMap)

file(GLOB SRC ./ *.cpp
  )

target_sources(4_6_EnvironmentMap
  PRIVATE
  ${SRC}
  )

target_link_directories(4_6_EnvironmentMap PRIVATE ${PROJECT_SOURCE_DIR}/Libs)

target_link_libraries(4_6_EnvironmentMap
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )