#include "Screen.h"
#include <iostream>

namespace graphics {

Screen::Screen() :
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer_screen(NULL), m_buffer_color(NULL) {

}

bool Screen::init() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	m_window = SDL_CreateWindow("Particle Fire Explosion",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (m_window == NULL) {
		std::cout << "The window couldn't open: " << SDL_GetError();
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (m_renderer == NULL) {
		std::cout << "Could not create renderer." << SDL_GetError();
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	if (m_texture == NULL) {
		std::cout << "Could not create texture." << SDL_GetError();
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_buffer_screen = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	m_buffer_color = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(m_buffer_screen, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	memset(m_buffer_color, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	return true;
}

void Screen::boxBlur() {

	//Swaping the buffers using a temporary unsigned 32 integer.
	Uint32 *temp = m_buffer_screen; //Assaign it where the screen buffer is pointing.
	m_buffer_screen = m_buffer_color; //Assaign it where the color buffer is pointing(Which is nothing in the memory).
	m_buffer_color = temp; //Assaign the color buffer to the temporary one which pointed at the screen buffer.
	//So basically assaging it to the screen buffer.
	//This means that now we can work on the box blur without worrying for the screen buffer and it's allocated space.

	for (int y = 0; y < SCREEN_HEIGHT; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++) {
			//Pixel Imagination
			//So we are going to get a -1 to 1 position relative to the original pixel position.
			//If we do that will get a box with nine pixels!!
			//This is needed to implement the Box Blur.
			// 0  0  0
			// 0  1  0
			// 0  0  0

			//These are the values that are going to be spread to the box.
			int redTotal = 0;
			int greenTotal = 0;
			int blueTotal = 0;

			for (int row = -1; row <= 1; row++) {
				for (int col = -1; col <= 1; col++) {
					int currentX = x + row;
					int currentY = y + col;

					if (currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT) {
						Uint32 color = m_buffer_color[(currentY*SCREEN_WIDTH) + currentX];

						Uint8 red = color >> 24;
						Uint8 green = color >> 16;
						Uint8 blue = color >> 8;

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;
					}
				}
			}

			Uint8 red = redTotal / 9;
			Uint8 green = greenTotal / 9;
			Uint8 blue = blueTotal / 9;

			setPixel(x, y, red, green, blue);
		}
	}
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
		return;
	}

	Uint32 color = 0;

	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;
	m_buffer_screen[(y * SCREEN_WIDTH) + x] = color;


}

void Screen::update() {

	SDL_UpdateTexture(m_texture, NULL, m_buffer_screen, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);

}

bool Screen::processEvents() {

	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}

	return true;
}

void Screen::close() {
	delete[] m_buffer_screen;
	delete[] m_buffer_color;
	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}
}
