# Bloom
add_executable(5_7_Bloom)
target_sources(5_7_Bloom
  PRIVATE
  ./5_7_Bloom.cpp
)
target_link_directories(5_7_Bloom PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(5_7_Bloom
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)