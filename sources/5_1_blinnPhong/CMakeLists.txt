# Blinn-Phong
add_executable(5_1_blinnPhong)
target_sources(5_1_blinnPhong
  PRIVATE
  ./5_1_blinnPhong.cpp
)
target_link_directories(5_1_blinnPhong PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(5_1_blinnPhong
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)

