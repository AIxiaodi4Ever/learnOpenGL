# ParallaxMapping
add_executable(5_6_HDRToneMapping)
target_sources(5_6_HDRToneMapping
  PRIVATE
  ./5_6_HDRToneMapping.cpp
)
target_link_directories(5_6_HDRToneMapping PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(5_6_HDRToneMapping
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)