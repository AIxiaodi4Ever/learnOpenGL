# BreakOut
add_executable(0_0_TestFFmpeg)
target_sources(0_0_TestFFmpeg
  PRIVATE
  ./0_0_TestFFmpeg.cpp
)

target_link_libraries(0_0_TestFFmpeg
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  ${FREETYPE}
  GLAD
  STB_IMAGE
  ${AVDEVICE_LIB}
  ${AVFILTER_LIB}
  ${AVFORMAT_LIB}
  ${AVCODEC_LIB}
  ${SWRESAMPLE_LIB}
  ${SWSCALE_LIB}
  ${POSTPROC_LIB}
  ${AVUTIL_LIB}
)

# copy dll to build
if (WIN32)
    file(GLOB_RECURSE FFMPEG_DLLS
        "${PROJECT_LIB_DIR}/ffmpeg/bin/avcodec-*.dll"
        "${PROJECT_LIB_DIR}/ffmpeg/bin/avformat-*.dll"
        "${PROJECT_LIB_DIR}/ffmpeg/bin/avdevice-*.dll"
        "${PROJECT_LIB_DIR}/ffmpeg/bin/avutil-*.dll"
        "${PROJECT_LIB_DIR}/ffmpeg/bin/swresample-*.dll"
    )

    # 添加复制命令到主目标
    add_custom_command(TARGET 0_0_TestFFmpeg POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${FFMPEG_DLLS}
        ${PROJECT_BINARY_DIR}/$<CONFIG>/
        COMMENT "Copying FFmpeg DLLs to output directory"
    )
endif()