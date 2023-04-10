add_executable(2_5_MultipleLight)

file(GLOB SRC ./ *.cpp
  )

# message(STATUS ${SRC})

target_sources(2_5_MultipleLight
  PRIVATE
  ${SRC}
  )

target_link_libraries(2_5_MultipleLight
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )