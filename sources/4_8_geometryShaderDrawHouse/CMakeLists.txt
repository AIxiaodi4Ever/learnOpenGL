add_executable(4_8_GeometryShaderDrawHouse)

file(GLOB SRC ./ *.cpp)

target_sources(4_8_GeometryShaderDrawHouse
  PRIVATE
  ${SRC})

target_link_directories(4_8_GeometryShaderDrawHouse PRIVATE ${PROJECT_SOURCE_DIR}/Libs)

target_link_libraries(4_8_GeometryShaderDrawHouse
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )
