# LightDepthBuffer
add_executable(5_3_LightDepthBuffer)
target_sources(5_3_LightDepthBuffer
  PRIVATE
  ./5_3_LightDepthBuffer.cpp
)
target_link_directories(5_3_LightDepthBuffer PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(5_3_LightDepthBuffer
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)

# DepthShading
add_executable(5_3_DepthShading)
target_sources(5_3_DepthShading
  PRIVATE
  ./5_3_DepthShading.cpp
)
target_link_directories(5_3_DepthShading PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(5_3_DepthShading
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)

# point light
add_executable(5_3_PointShadows)
target_sources(5_3_PointShadows
  PRIVATE
  ./5_3_PointShadows.cpp
)
target_link_directories(5_3_PointShadows PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(5_3_PointShadows
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)
