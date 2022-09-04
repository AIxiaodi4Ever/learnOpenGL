add_executable(2_4_LightCaster)
target_sources(2_4_LightCaster
  PRIVATE
  LightCaster.cpp
  )

target_link_libraries(2_4_LightCaster
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )