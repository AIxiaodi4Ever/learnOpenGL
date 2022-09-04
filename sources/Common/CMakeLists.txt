# glad
add_library(GLAD)
target_sources(GLAD 
  PRIVATE
  glad.c
  )
target_include_directories(GLAD 
  PUBLIC
  ${PROJECT_SOURCE_DIR}/includes
  )

# stb_image
add_library(STB_IMAGE)
target_sources(STB_IMAGE 
  PRIVATE
  stb_image.cpp
  )
target_include_directories(STB_IMAGE
  PUBLIC
  ${PROJECT_SOURCE_DIR}/includes
  )