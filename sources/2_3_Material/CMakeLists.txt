add_executable(2_3_Material)
target_sources(2_3_Material
  PRIVATE
  2-03-1Material.cpp
  )

target_link_libraries(2_3_Material
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )