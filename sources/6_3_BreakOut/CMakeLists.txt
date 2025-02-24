# TextRendering
add_executable(6_3_BreakOut)
target_sources(6_3_BreakOut
  PRIVATE
  ./6_3_BreakOut.cpp
  ./game.cpp
  ./resource_manager.cpp
  ./shader.cpp  
  ./texture.cpp
  ./sprite_renderer.cpp
  ./game_object.cpp
  ./game_level.cpp
  ./ball_object.cpp
  ./particle_generator.cpp
)
target_link_directories(6_3_BreakOut PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(6_3_BreakOut
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  ${FREETYPE}
  GLAD
  STB_IMAGE
)