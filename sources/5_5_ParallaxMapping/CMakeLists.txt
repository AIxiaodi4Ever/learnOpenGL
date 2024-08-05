# ParallaxMapping
add_executable(5_5_ParallaxMapping)
target_sources(5_5_ParallaxMapping
  PRIVATE
  ./5_5_ParallaxMapping.cpp
)
target_link_directories(5_5_ParallaxMapping PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(5_5_ParallaxMapping
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)