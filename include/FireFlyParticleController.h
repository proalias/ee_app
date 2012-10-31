#pragma once

#include "cinder/app/App.h"
#include "cinder/Vector.h"
#include <vector>

#include "FireFlyParticle.h"
#include "Vect.h"


#include <list>
using std::list;

class FireFlyParticleController {
 
public:

	static const int FIREFLY_ENTERED = 0;
	static const int FIREFLY_LEFT = 1;
	
	float x;
	float y;

	int index;
	bool isOccupied;
	bool isActive;
	bool isRepelling;
	
	Vect pos;
	Vect particlePos;
	int previousIndex;
	int giveTo;
	int exciter;
	int waveState;
	int waveIteration;
	bool borderFlag;

	FireFlyParticle particle;

	std::vector<int> neighborOrder;

	int rows;
	int columns;
	
//	FireFlyEffect * _grid;
	//::vector<FireFlyParticle> particles; // TODO - check this works and were not cloning.
	int _takeFrom;
	float _waveSpeed;
	
	std::vector<int> _neighborParticles;
	
	FireFlyParticleController();

	FireFlyParticleController( float initX,
		float initY,
		Vect initPos,
		int initIndex,
		int prows,
		int pcolumns );
	
	bool startShuffle(void);
	bool checkPath(void);
	void setParticleFollow(void);
	void checkWave(void);
	bool resetGrid(void);
	bool makeWave(void);
	bool reactToWave(void);
	bool repel(void);
	bool applyFade(void);

	std::vector<FireFlyParticleController>* ffparticles;
	void setParticles( std::vector<FireFlyParticleController> &ffparticles );

	std::vector<FireFlyParticleController>* activeParticles;
	void setActiveParticles( std::vector<FireFlyParticleController> &theactiveParticles );

	std::vector<FireFlyParticleController>* waveparticles;
	void setWaveParticles( std::vector<FireFlyParticleController> &thewaveParticles );

};