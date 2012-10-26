#pragma once

#include "cinder/app/App.h"
#include "cinder/Vector.h"
#include <vector>

#include "Vect.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class FireFlyParticle {
 
public:

	Vect pos;
	Vect targetPos;
	Vect vel;
		
	bool isNormal;
	bool isActive;
	bool isWave;
		
	int fade;
	bool fadeIn;
		
	std::vector<int> _fadeSizes;
	Vect _force;
		
	float _drag; 
	float _speed;

	FireFlyParticle(void);

	void applyShuffle(void );
		
	void update(void);
	void draw(void);

};