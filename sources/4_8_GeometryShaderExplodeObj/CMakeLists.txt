add_executable(4_8_GeometryShaderExplodeObj)

file(GLOB SRC ./ *.cpp)

target_sources(4_8_GeometryShaderExplodeObj
  PRIVATE
  ${SRC})

target_link_directories(4_8_GeometryShaderExplodeObj PRIVATE ${PROJECT_SOURCE_DIR}/Libs)

target_link_libraries(4_8_GeometryShaderExplodeObj
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
  )
