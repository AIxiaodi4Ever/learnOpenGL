add_executable(4_4_FaceCulling)

file(GLOB SRC ./ *.cpp
  )

target_sources(4_4_FaceCulling
  PRIVATE
  ${SRC}
  )

target_link_directories(4_4_FaceCulling PRIVATE ${PROJECT_SOURCE_DIR}/Libs)

target_link_libraries(4_4_FaceCulling
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )