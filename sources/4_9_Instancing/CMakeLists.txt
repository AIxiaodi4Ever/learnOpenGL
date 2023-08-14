# example 1 instancing quads
add_executable(4_9_InstancingQuads)
target_sources(4_9_InstancingQuads
  PRIVATE
  ./4_9_InstancingQuads.cpp
)
target_link_directories(4_9_InstancingQuads PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(4_9_InstancingQuads
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)

# example 2 draw asteroid without instancing
add_executable(4_9_AsteroidNoInstancing)
target_sources(4_9_AsteroidNoInstancing
  PRIVATE
  ./4_9_AsteroidNoInstancing.cpp
)
target_link_directories(4_9_AsteroidNoInstancing PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(4_9_AsteroidNoInstancing
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE
)

# example 3 draw asteroid with instancing
add_executable(4_9_AsteroidInstancing)
target_sources(4_9_AsteroidInstancing
  PRIVATE
  ./4_9_AsteroidInstancing.cpp
)
target_link_directories(4_9_AsteroidInstancing PRIVATE ${PROJECT_SOURCE_DIR}/Libs)
target_link_libraries(4_9_AsteroidInstancing
  PRIVATE
  ${GLFW}
  ${OPENGL_LIBRARY}
  ${ASSIMP}
  GLAD
  STB_IMAGE  
)
