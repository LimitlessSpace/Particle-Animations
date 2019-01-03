#ifndef SWARM_H_
#define SWARM_H_
#include "Particle.h"

namespace graphics {

class Swarm {
public:
	const static int NPARTICLES = 1000;

private:
	Particle *m_pParticle;

public:
	Swarm();
	virtual ~Swarm();
	void update();

	const Particle *const getParticle() {return m_pParticle;};

};

}
#endif
