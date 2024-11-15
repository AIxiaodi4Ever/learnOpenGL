# SSAO
add_executable(5_9_SSAO)
target_sources(5_9_SSAO
  PRIVATE
  ./5_9_SSAO.cpp
)
target_link_directories(5_9_SSAO PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(5_9_SSAO
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)