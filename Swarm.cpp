/*
 * Swarm.cpp
 *
 *  Created on: Oct 31, 2021
 *      Author: Josh
 */

#include "Swarm.h"

namespace jrose {

Swarm::Swarm(): lastTime(0) {
	m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
	delete []m_pParticles;
}

//move this into main game draw loop for better efficiency
void Swarm::update(int elapsed) {

	int interval = elapsed - lastTime;

	for (int i = 0; i < jrose::Swarm::NPARTICLES; i++) {
		m_pParticles[i].update(interval);
	}

	lastTime = elapsed;
}

} /* namespace jrose */
