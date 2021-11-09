/*
 * Swarm.h
 *
 *  Created on: Oct 31, 2021
 *      Author: Josh
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace jrose {

class Swarm {
private:
	Particle * m_pParticles;
	int lastTime;

public:
	const static int NPARTICLES = 5000;
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);

	const Particle * const getParticles() {return m_pParticles;};
};

} /* namespace jrose */

#endif /* SWARM_H_ */
