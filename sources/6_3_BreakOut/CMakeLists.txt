# BreakOut
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
  ./post_processor.cpp
  ./text_renderer.cpp
)

target_link_libraries(6_3_BreakOut
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  ${FREETYPE}
  GLAD
  STB_IMAGE
  ${IRRKLANG}
  ${FREETYPE}
)

# copy irrKlang dlls to build
if (WIN32)
    file(GLOB_RECURSE IRRKLANG_DLL
        "${IRRKLANG_LIB_DIR}/ikpFlac.dll"
        "${IRRKLANG_LIB_DIR}/ikpMP3.dll"
        "${IRRKLANG_LIB_DIR}/irrKlang.dll"
    )

    # 添加复制命令到主目标
    add_custom_command(TARGET 6_3_BreakOut POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${IRRKLANG_DLL}
        ${PROJECT_BINARY_DIR}/$<CONFIG>/
        COMMENT "Copying IRRKLANG_DLL to output directory"
    )
endif()