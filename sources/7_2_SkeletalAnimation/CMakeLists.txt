# SkeletalAnimation
add_executable(7_2_SkeletalAnimation)
target_sources(7_2_SkeletalAnimation
  PRIVATE
  ./7_2_SkeletalAnimation.cpp
)
target_link_directories(7_2_SkeletalAnimation PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(7_2_SkeletalAnimation
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)