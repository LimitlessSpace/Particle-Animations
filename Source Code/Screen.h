
#ifndef SCREEN_H_
#define SCREEN_H_
#include <SDL.h>

namespace graphics {

class Screen {

public:
	const static int SCREEN_WIDTH = 1600;
	const static int SCREEN_HEIGHT = 900;

private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;

public:
	Screen();
	bool init();
	bool processEvents();
	void setPixel(int x, int y, Uint32 red, Uint32 green, Uint32 blue);
	void clear();
	void close();
	void update();
};

}

#endif
