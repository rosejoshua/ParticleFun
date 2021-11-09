/*
 * Particle.cpp
 *
 *  Created on: Oct 31, 2021
 *      Author: Josh
 */

#include "Particle.h"
#include <math.h>
#include <stdlib.h>

namespace jrose {

Particle::Particle(): m_xPos(0), m_yPos(0) {
	init();
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::init() {
	m_xPos = 0;
	m_yPos = 0;
	m_direction = (2 * M_PI * rand()) / RAND_MAX; //random direction in radians
	m_speed = (0.03 * rand()) / RAND_MAX;

	m_speed *= m_speed;
}

void Particle::update(int interval) {

	m_direction += interval*.0003;

	double xSpeed = m_speed * cos(m_direction);
	double ySpeed = m_speed * sin(m_direction);

	m_xPos += xSpeed * interval;
	m_yPos += ySpeed * interval;

	if(m_xPos < -1 || m_xPos > 1 || m_yPos < -1 || m_yPos > 1 ){
		init();
	}

	if(rand() < RAND_MAX/100) {
		init();
	}
}
}
