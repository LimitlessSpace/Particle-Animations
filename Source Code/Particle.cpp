#include <stdlib.h>
#include "Particle.h"

namespace graphics {

Particle::Particle() {
	m_x = ((2.0*rand())/RAND_MAX) - 1;
	m_y = ((2.0*rand())/RAND_MAX) - 1;

	m_xspeed = 0.001 * (((2.0 *rand())/RAND_MAX) - 1);
	m_yspeed = 0.001 * (((2.0 *rand())/RAND_MAX) - 1);
}

void Particle::update(){
	m_x += m_xspeed;
	m_y += m_yspeed;

	if(m_x <= -1.0 || m_x >= 1.0){
		m_x = -m_xspeed;
	}

	if(m_y <= -1.0 || m_y >= 1.0){
		m_y = -m_yspeed;
	}

}

Particle::~Particle() {

}

}

