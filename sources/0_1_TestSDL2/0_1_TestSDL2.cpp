// https://www.cnblogs.com/AnnihilateSword/articles/sdlstart_18stdMixerPlayMusicAndChunk.html
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

constexpr int SRC_WIDTH = 640;
constexpr int SRC_HEIGHT = 480;
// 错误处理
#define MyError(ErrorMessage) \
	{\
		std::cout << "[Error]: " << (ErrorMessage) << std::endl;\
		return -1;\
	}

int main(int argc, char* argv[])
{
	// Init
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		MyError("Failed to Initialize SDL!");
	SDL_Window* window = SDL_CreateWindow("HelloSDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SRC_WIDTH, SRC_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window)
		MyError("Failed to create window!");
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer)
		MyError("Failed to create window renderer");

	// --- 播放音乐 -----------------------------------------------------------------
	//if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096) == -1)
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_CHANNELS, 4096) == -1)  // 也可以设置最大通道 MIX_CHANNELS 8
		MyError("Failed to Open Audio!");
	// 音乐的SDL_mixer数据类型为 Mix_Music，短音的数据类型为 Mix_Chunk。
	// 加载音乐（比较长的音乐），一般这个只有一个通道，所以使用这个不能同时播放音乐
	Mix_Music* music = Mix_LoadMUS("../resources/audio/breakout.mp3");

	// 如果需要同时播放音乐，可以使用下面的函数，一般电脑上通道限制可能是 8 个，每个音乐会占用一个通道
	// 音效（短音）一般用这个，虽然函数名后缀是 WAV，不过除了 wav 也能加载其他格式，如 mp3
	Mix_Chunk* chunkScratch = Mix_LoadWAV("../resources/audio/bleep.wav");
	Mix_Chunk* chunkHigh = Mix_LoadWAV("../resources/audio/powerup.wav");
	Mix_Chunk* chunkLow = Mix_LoadWAV("../resources/audio/solid.wav");
	Mix_Chunk* chunkMedium = Mix_LoadWAV("../resources/audio/bleep.mp3");

	// SDL_mixer 对音频数据有两个单独的数据结构。一个它称为“块”，这意味着一个完全解码到预先内存中的文件，另一个它称为“音乐”，这是一个旨在按需解码的文件。
	// 最初，像未压缩的WAV文件这样的简单格式是块，压缩的东西，如MP3，应该是音乐，你会为游戏的音乐流式传输一件事，并用块制作重复的声音效果。

	// 【总之，一般 Mix_Music 只有一个，一般用作背景音乐或其他，Mix_Chunk 有多个且可以同时播放】

	// Game Running
	SDL_Event event;
	bool running = true;
	while (running)
	{
		// Event Loop
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = false;
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
					// 播放音效
				case SDLK_1: Mix_PlayChannel(-1, chunkHigh, 0); break;
				case SDLK_2: Mix_PlayChannel(-1, chunkMedium, 0); break;
				case SDLK_3: Mix_PlayChannel(-1, chunkLow, 0); break;
				case SDLK_4: Mix_PlayChannel(-1, chunkScratch, 0); break;

				case SDLK_9:
					if (Mix_PlayingMusic() == 0)
					{
                        std::cout << "play music" << std::endl;
						Mix_PlayMusic(music, -1);  // 播放音乐
					}
					else if(Mix_PausedMusic() == 1)
					{
						Mix_ResumeMusic();  // 从暂停的位置恢复音频继续播放
					}
					else
					{
						Mix_PauseMusic();  // 暂停音乐
					}
					break;
					// 停止播放音乐流
				case SDLK_0: Mix_HaltMusic(); break;
				}
			}
		}
		// 清屏（黑色）
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		// 更新屏幕
		SDL_RenderPresent(renderer);
	}
	// Clear up
	// 清理音乐
	Mix_FreeChunk(chunkHigh);
	Mix_FreeChunk(chunkLow);
	Mix_FreeChunk(chunkMedium);
	Mix_FreeChunk(chunkScratch);
	Mix_FreeMusic(music);
	Mix_Quit();  // 退出 Mix

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}