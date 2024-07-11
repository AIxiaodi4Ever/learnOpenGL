# LightDepthBuffer
add_executable(5_4_NormalMap)
target_sources(5_4_NormalMap
  PRIVATE
  ./5_4_NormalMap.cpp
)
target_link_directories(5_4_NormalMap PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(5_4_NormalMap
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)