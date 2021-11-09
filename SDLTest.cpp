//============================================================================
// Name        : SDLtest.cpp
// Author      : Joshua Rose
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "Screen.h"
#include "Swarm.h"
#include "Particle.h"
using namespace std;

int main() {

	srand(time(NULL));

	jrose::Screen screen;

	if(screen.init() == false) {
		cout << "Error initializing SDL." << endl;
	}

	jrose::Swarm swarm;

	while(true) {
		//update particles
		//draw particles
		int elapsed = SDL_GetTicks();

		swarm.update(elapsed);

		//this may have an error of color jumping when value barely
		//exceeds what can be stored and the value abrubtly goes to
		//another color.
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.001)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.003)) * 128);

		const jrose::Particle *const pParticles = swarm.getParticles();

		for(int i=0; i<jrose::Swarm::NPARTICLES; i++){
			jrose::Particle particle = pParticles[i];

			int xPos = (particle.m_xPos + 1) * jrose::Screen::SCREEN_WIDTH/2;
			int yPos = particle.m_yPos * jrose::Screen::SCREEN_WIDTH/2 + jrose::Screen::SCREEN_HEIGHT/2;

			screen.setPixel(xPos, yPos, red, green, blue);
		}

		screen.boxBlur();

		//draw the screen
		screen.update();

		//check for messages/events


		if (!screen.processEvents()) {
			break;
		}
	}

	screen.close();

	return 0;
}
