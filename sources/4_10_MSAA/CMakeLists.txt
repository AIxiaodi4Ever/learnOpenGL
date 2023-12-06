# Offline MSAA
add_executable(4_10_MSAA)
target_sources(4_10_MSAA
  PRIVATE
  ./4_10_MSAA.cpp
)
target_link_directories(4_10_MSAA PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(4_10_MSAA
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)

# Custom AA
add_executable(4_10_MSAA_self)
target_sources(4_10_MSAA_self
  PRIVATE
  ./4_10_MSAA_self.cpp
)
target_link_directories(4_10_MSAA_self PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(4_10_MSAA_self
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)


