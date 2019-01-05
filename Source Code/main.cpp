#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
#include "SDL.h"
#include "Screen.h"
using namespace std;
using namespace graphics;

int main() {

	srand(time(NULL));

	Screen screen;

	if(!screen.init()){
		std::cout << "SDL initialization failed.";
	}

	Swarm swarm;

	while(true){

		//Animate particles
		int elapsed = SDL_GetTicks();

		swarm.update(elapsed);

		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0006)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0009)) * 128);

		const Particle *const pParticle = swarm.getParticle();

		for(int i = 0; i < Swarm::NPARTICLES; i++){
			Particle particle = pParticle[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = particle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();
		//Draw the screen
		screen.update();

		if(!screen.processEvents()){
			break;
		}

	}

	screen.close();

	return 0;
}
