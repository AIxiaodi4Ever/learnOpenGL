# CascadeShadowMap
add_executable(7_3_CascadeShadowMap)
target_sources(7_3_CascadeShadowMap
  PRIVATE
  ./7_3_CascadeShadowMap.cpp
)
target_link_directories(7_3_CascadeShadowMap PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(7_3_CascadeShadowMap
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)