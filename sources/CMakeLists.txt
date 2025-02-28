include_directories(${PROJECT_SOURCE_DIR}/includes)
include_directories(${PROJECT_SOURCE_DIR}/includes/ffmpeg)

# common source
add_subdirectory(Common)

# set project lib dir
set(PROJECT_LIB_DIR ${PROJECT_SOURCE_DIR}/Libs)
# GLFW
find_library(GLFW NAMES glfw3 PATHS ${PROJECT_LIB_DIR} REQUIRED)

# assimp
find_library(ASSIMP NAMES assimp-vc142-mt PATHS ${PROJECT_LIB_DIR} REQUIRED)

# freetype
find_library(FREETYPE NAMES freetype.lib PATHS ${PROJECT_LIB_DIR} REQUIRED)

# ffmpeg
set(FFMPEG_LIB_DIR "${PROJECT_LIB_DIR}/ffmpeg/lib")
find_library(AVCODEC_LIB avcodec PATHS ${FFMPEG_LIB_DIR} REQUIRED)
find_library(AVFORMAT_LIB avformat PATHS ${FFMPEG_LIB_DIR} REQUIRED)
find_library(AVDEVICE_LIB avdevice PATHS ${FFMPEG_LIB_DIR} REQUIRED)
find_library(AVUTIL_LIB avutil PATHS ${FFMPEG_LIB_DIR} REQUIRED)
find_library(SWRESAMPLE_LIB swresample PATHS ${FFMPEG_LIB_DIR} REQUIRED)
find_library(SWSCALE_LIB swscale PATHS ${FFMPEG_LIB_DIR} REQUIRED)
find_library(AVFILTER_LIB avfilter PATHS ${FFMPEG_LIB_DIR} REQUIRED)
find_library(POSTPROC_LIB postproc PATHS ${FFMPEG_LIB_DIR} REQUIRED)

# SDL2
set(SDL2_LIB_DIR "${PROJECT_LIB_DIR}/SDL2")
find_library(SDL2 SDL2 PATHS ${SDL2_LIB_DIR} REQUIRED)
find_library(SDL2MAIN SDL2main PATHS ${SDL2_LIB_DIR} REQUIRED)
find_library(SDL2_MIXER SDL2_mixer PATHS ${SDL2_LIB_DIR} REQUIRED)

# irrKlang
set(IRRKLANG_LIB_DIR "${PROJECT_LIB_DIR}/irrKlang")
find_library(IRRKLANG irrKlang PATHS ${IRRKLANG_LIB_DIR} REQUIRED)

# OpenGL
find_package(OpenGL REQUIRED OPTIONAL_COMPONENTS OpenGL)

link_directories(${PROJECT_SOURCE_DIR}/Libs)

message(STATUS "GLFW IS: ${GLFW}")
message(STATUS "ASSIMP IS: ${ASSIMP}")
message(STATUS "OPENGL_LIBRARY is: ${OPENGL_LIBRARY}")
message(STATUS "AVCODEC_LIB is: ${AVCODEC_LIB}")
message(STATUS "AVFORMAT_LIB is: ${AVFORMAT_LIB}")
message(STATUS "AVDEVICE_LIB IS: ${AVDEVICE_LIB}")
message(STATUS "AVUTIL_LIB is: ${AVUTIL_LIB}")
message(STATUS "SWRESAMPLE_LIB is: ${SWRESAMPLE_LIB}")
message(STATUS "SWSCALE_LIB is: ${SWSCALE_LIB}")
message(STATUS "AVFILTER_LIB IS: ${AVFILTER_LIB}")
message(STATUS "POSTPROC_LIB is: ${POSTPROC_LIB}")
message(STATUS "SDL2 is: ${SDL2}")
message(STATUS "SDL2_MIXER is: ${SDL2_MIXER}")
message(STATUS "SDL2MAIN is: ${SDL2MAIN}")
message(STATUS "IRRKLANG is: ${IRRKLANG}")

# Set compiler flags to ignore warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")
elseif(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /w")
endif()

# each step
foreach(sample IN ITEMS
    0_0_TestFFmpeg
    0_1_TestSDL2
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
    5_10_PBR
    5_11_IBL
    6_1_DebugOutput
    6_2_TextRendering
    6_3_BreakOut
    )
  add_subdirectory(${sample}) 
endforeach()
