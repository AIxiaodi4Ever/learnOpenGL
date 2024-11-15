include_directories(${PROJECT_SOURCE_DIR}/includes)

# common source
add_subdirectory(Common)

# GLFW
find_library(GLFW NAMES glfw3 PATHS ${PROJECT_SOURCE_DIR}/Libs)

# assimp
find_library(ASSIMP NAMES assimp-vc142-mt PATHS ${PROJECT_SOURCE_DIR}/Libs)

# OpenGL
find_package(OpenGL REQUIRED OPTIONAL_COMPONENTS OpenGL)

link_directories(${PROJECT_SOURCE_DIR}/Libs)

message(STATUS "GLFW IS: ${GLFW}")
message(STATUS "ASSIMP IS: ${ASSIMP}")
message(STATUS "OPENGL_LIBRARY is: ${OPENGL_LIBRARY}")

# Set compiler flags to ignore warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")
elseif(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /w")
endif()

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
    3_1_AssimpLoadModel
    4_1_DepthBuffer
    4_2_StencilBuffer
    4_3_Blend
    4_4_FaceCulling
    4_5_FrameBuffer
    4_5_Framebuffer_PostProcess
    4_6_Skybox
    4_6_EnvironmentMap
    4_6_EnvironmentMapRefract
    4_7_AdvancedGLSL_UniformBuffer
    4_7_AdvancedGLSL_PointSize
    4_8_GeometryShaderDrawHouse
    4_8_GeometryShaderExplodeObj
    4_8_GeometryShaderDrawNormal
    4_9_Instancing
    4_10_MSAA
    5_1_blinnPhong
    5_2_GammaCorrection
    5_3_Shadows
    5_4_NormalMap
    5_5_ParallaxMapping
    5_6_HDRToneMapping
    5_7_Bloom
    5_8_DeferredShading
    5_9_SSAO
    )
  add_subdirectory(${sample}) 
endforeach()
