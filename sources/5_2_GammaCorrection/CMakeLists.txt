# Blinn-Phong
add_executable(5_2_GammaCorrection)
target_sources(5_2_GammaCorrection
  PRIVATE
  ./5_2_GammaCorrection.cpp
)
target_link_directories(5_2_GammaCorrection PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(5_2_GammaCorrection
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)

