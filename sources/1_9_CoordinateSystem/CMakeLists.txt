add_executable(1_9_CoordinateSystem)
target_sources(1_9_CoordinateSystem
  PRIVATE
  1-9-1coordinateSystem.cpp
  )

target_link_libraries(1_9_CoordinateSystem
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )