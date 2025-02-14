# Diffuse IBL
add_executable(6_1_DebugOutput)
target_sources(6_1_DebugOutput
  PRIVATE
  ./6_1_DebugOutput.cpp
)
target_link_directories(6_1_DebugOutput PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(6_1_DebugOutput
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)