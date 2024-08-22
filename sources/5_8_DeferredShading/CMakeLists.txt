# Deferred Shading
add_executable(5_8_DeferredShading)
target_sources(5_8_DeferredShading
  PRIVATE
  ./5_8_DeferredShading.cpp
)
target_link_directories(5_8_DeferredShading PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(5_8_DeferredShading
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)