/*
 * Particle.h
 *
 *  Created on: Oct 31, 2021
 *      Author: Josh
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace jrose {

class Particle {
public: //breaking encapsulation or the sake of speed
	double m_xPos;
	double m_yPos;

	double m_speed;
	double m_direction;

	Particle();
	virtual ~Particle();
	void update(int interval);

private:
	void init();
};

} /* namespace jrose */

#endif /* PARTICLE_H_ */
