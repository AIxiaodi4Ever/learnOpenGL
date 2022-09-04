add_executable(1_6_MoreAttributes)
target_sources(1_6_MoreAttributes
  PRIVATE
  moreAttributes.cpp
  )

target_link_libraries(1_6_MoreAttributes
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  GLAD
  STB_IMAGE
  )