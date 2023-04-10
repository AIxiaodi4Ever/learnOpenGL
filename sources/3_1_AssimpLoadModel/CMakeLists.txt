add_executable(3_1_AssimpLoadModel)

file(GLOB SRC ./ *.cpp
  )

target_sources(3_1_AssimpLoadModel
  PRIVATE
  ${SRC}
  )

target_link_directories(3_1_AssimpLoadModel PRIVATE ${PROJECT_SOURCE_DIR}/Libs)

target_link_libraries(3_1_AssimpLoadModel
  PRIVATE
  ${GLFW}
  ${ASSIMP}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )