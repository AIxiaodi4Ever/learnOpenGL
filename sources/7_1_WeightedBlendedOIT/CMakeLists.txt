# OIT
add_executable(7_1_WeightedBlendedOIT)
target_sources(7_1_WeightedBlendedOIT
  PRIVATE
  ./7_1_WeightedBlendedOIT.cpp
)
target_link_directories(7_1_WeightedBlendedOIT PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(7_1_WeightedBlendedOIT
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)