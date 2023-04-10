add_executable(4_5_Framebuffer_PostProcess)

file(GLOB SRC ./ *.cpp
  )

target_sources(4_5_Framebuffer_PostProcess
  PRIVATE
  ${SRC}
  )

target_link_directories(4_5_Framebuffer_PostProcess PRIVATE ${PROJECT_SOURCE_DIR}/Libs)

target_link_libraries(4_5_Framebuffer_PostProcess
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )