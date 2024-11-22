# PBR
add_executable(5_10_PBR)
target_sources(5_10_PBR
  PRIVATE
  ./5_10_PBR.cpp
)
target_link_directories(5_10_PBR PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(5_10_PBR
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)

# PBR Textured
add_executable(5_10_PBR_Textured)
target_sources(5_10_PBR_Textured
  PRIVATE
  ./5_10_PBR_Textured.cpp
)
target_link_directories(5_10_PBR_Textured PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(5_10_PBR_Textured
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)