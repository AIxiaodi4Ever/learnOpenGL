#include <iostream>

extern "C" {
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswresample/swresample.h>
    #include <libavutil/frame.h>
    #include <libavutil/mem.h>
}

int main(int argc, char *argv[]) {
    std::cout << avcodec_version() << std::endl;
    printf("FFmpeg version: %s\n", av_version_info());
    printf("avcodec version: %d.%d.%d\n",
       LIBAVCODEC_VERSION_MAJOR,
       LIBAVCODEC_VERSION_MINOR,
       LIBAVCODEC_VERSION_MICRO);
    return 0;
}