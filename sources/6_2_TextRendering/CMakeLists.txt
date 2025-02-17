# TextRendering
add_executable(6_2_TextRendering)
target_sources(6_2_TextRendering
  PRIVATE
  ./6_2_TextRendering.cpp
)
target_link_directories(6_2_TextRendering PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(6_2_TextRendering
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  ${FREETYPE}
  GLAD
  STB_IMAGE
)