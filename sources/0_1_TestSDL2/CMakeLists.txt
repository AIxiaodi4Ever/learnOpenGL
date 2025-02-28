# BreakOut
add_executable(0_1_TestSDL2)
target_sources(0_1_TestSDL2
  PRIVATE
  ./0_1_TestSDL2.cpp
)

target_link_libraries(0_1_TestSDL2
  PRIVATE
  GLAD
  STB_IMAGE
  ${SDL2}
  ${SDL2_MIXER}
  ${SDL2MAIN}
)

# copy SDL2 dlls to build
if (WIN32)
    file(GLOB_RECURSE SDL_DLL
        "${SDL2_LIB_DIR}/SDL2.dll"
        "${SDL2_LIB_DIR}/SDL2_mixer.dll"
    )

    # 添加复制命令到主目标
    add_custom_command(TARGET 0_1_TestSDL2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${SDL_DLL}
        ${PROJECT_BINARY_DIR}/$<CONFIG>/
        COMMENT "Copying SDL_DLLs to output directory"
    )
endif()