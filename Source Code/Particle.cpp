#include <stdlib.h>
#include "Particle.h"
#include <math.h>

namespace graphics {

Particle::Particle(): m_x(0), m_y(0) {
	m_direction = (2 * M_PI * rand())/RAND_MAX;
	m_speed = (0.00003 * rand())/RAND_MAX;
}

void Particle::update(int interval){
	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	m_x += xspeed * interval;
	m_y += yspeed * interval;
}

Particle::~Particle() {

}

}

