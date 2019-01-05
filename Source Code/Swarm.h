#ifndef SWARM_H_
#define SWARM_H_
#include "Particle.h"

namespace graphics {

class Swarm {
public:
	const static int NPARTICLES = 5000;

private:
	Particle *m_pParticle;
	double lastTime;

public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);

	const Particle *const getParticle() {return m_pParticle;};

};

}
#endif
