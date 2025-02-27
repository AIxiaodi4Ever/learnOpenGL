# glad
add_library(GLAD)
target_sources(GLAD 
  PRIVATE
  glad.c
  )

# stb_image
add_library(STB_IMAGE)
target_sources(STB_IMAGE 
  PRIVATE
  stb_image.cpp
  )

# model loader library: for test how to use dll
add_library(MODEL_LOADER)
target_sources(MODEL_LOADER PRIVATE modelLoaderCommon.cpp)
# copy assimp's dll
if (WIN32)
  file(GLOB ASSIMP_DLL ${PROJECT_SOURCE_DIR}/Libs/assimp-vc142-mt.dll)
  add_custom_command(TARGET MODEL_LOADER PRE_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy
      ${ASSIMP_DLL}
      ${PROJECT_BINARY_DIR}/$<CONFIG>/
      COMMENT "copy assimp's dll to project binary directory")
endif()