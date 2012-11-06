#pragma once

#include "cinder/app/App.h"
#include "cinder/Vector.h"
#include <vector>

#include "FireFlyWaveScheme.h"
#include "FireFlyParticleController.h"

class FireFlyEffect {
 
public:

	FireFlyEffect(void);
	//~FireFlyEffect(void);

	std::vector<FireFlyWaveScheme> waveStartScheme;

	std::vector<ci::Vec3f> waveScheme;
	
	std::vector<FireFlyParticleController> particles;
	std::vector<FireFlyParticleController> activeParticles;
	std::vector<FireFlyParticleController> waveParticles;

	int rows;
	int columns;
		
	float _spriteScale;
	float _delayNewFireFly;
	int	_count;
	int	_maxCount;

	void createGrid(void);
	void update(void);
	void increment(void);
	void decrement(void);
	void draw(void);
	
	bool repel(void);

};