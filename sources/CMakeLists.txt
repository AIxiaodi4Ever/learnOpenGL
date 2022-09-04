# common source
add_subdirectory(Common)

# GLFW
find_library(GLFW NAMES glfw3 PATHS ${PROJECT_SOURCE_DIR}/Libs)
# OpenGL
find_package(OpenGL REQUIRED OPTIONAL_COMPONENTS OpenGL)

message(STATUS "GLFW IS: ${GLFW}")
message(STATUS "OPENGL_LIBRARY is: ${OPENGL_LIBRARY}")

# each step
foreach(sample IN ITEMS
    1_1_DrawTriangle
    1_2_DrawRectangle
    1_3_DualVAOandVBOs
    1_4_TwoFragmentShaders
    1_5_UseUniform
    1_6_MoreAttributes
    1_7_ShaderClass
    1_8_RectangleTexture
    1_9_CoordinateSystem
    1_10_ThreeDBox
    1_11_CameraClass
    2_1_LightCube
    2_2_DiffuseAndSpecular
    2_3_Material
    2_4_LightCaster
    2_5_MultipleLight
    )
  add_subdirectory(${sample}) 
endforeach()
