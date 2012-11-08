#include "cinder/Rand.h"

#include "FireFlyParticleController.h"
#include "Vect.h"
#include "FireFlyParticle.h"

#include "FireFlyWaveScheme.h"

#include <list>

using namespace ci;
using namespace ci::app;
using namespace std;

using std::list;

// TODO - check original source against this for Math.round... i used floor. should find alterntative and update everywhere

FireFlyParticleController::FireFlyParticleController(){}


void FireFlyParticleController::setParticles( std::vector<FireFlyParticleController> &theffparticles )
{
	ffparticles = &theffparticles;
}

void FireFlyParticleController::setActiveParticles( std::vector<FireFlyParticleController> &theactiveparticles )
{
	activeParticles = &theactiveparticles;
}

void FireFlyParticleController::setWaveParticles( std::vector<FireFlyParticleController> &thewaveparticles )
{
	waveparticles = &thewaveparticles;
}


FireFlyParticleController::FireFlyParticleController( float initX,
	float initY,
	Vect initPos,
	int initIndex,
	int prows,
	int pcolumns ){

	isOccupied = true;
	isActive = false;
	isRepelling = false;
	previousIndex = -1;
	giveTo = -1;
	exciter = -1;
	waveState = -1;
	waveIteration = -1;

	_takeFrom = -1;
	_waveSpeed = 0.08;

	// params
	x = initX;
	y = initY;
	pos = initPos;
	particlePos = initPos;
	index = initIndex;

	rows = prows;
	columns = pcolumns;

	// TODO -
	
	neighborOrder.push_back(1);
	neighborOrder.push_back(0);
	neighborOrder.push_back(3);
	neighborOrder.push_back(7);
	neighborOrder.push_back(6);
	neighborOrder.push_back(5);
	neighborOrder.push_back(4);
	

	// TODO - so not 100% sure yet. but think this may be due to the python
	// not having stage edge detection in the cinema 4D so these border flags could potentially 
	// also be replaced
	
	if ((x > 0) && (x < (rows - 1)) && (y > 0) && (y < (columns - 1)))
	{
		borderFlag = false;
				
		_neighborParticles.push_back( ( rows * y + x ) - 1 );
		_neighborParticles.push_back( ( rows * y + x ) + 1 );
		_neighborParticles.push_back( ( rows * y + x) + rows );
		_neighborParticles.push_back( ( rows * y + x) - rows );
		_neighborParticles.push_back( ( rows * y + x) + rows - 1 );
		_neighborParticles.push_back( ( rows * y + x) + rows + 1 );
		_neighborParticles.push_back( ( rows * y + x) - rows - 1 );
		_neighborParticles.push_back( ( rows * y + x) - rows + 1 );
	}
	else
	{
		borderFlag = true;

		if (x != 0) {
			_neighborParticles.push_back(( rows * y + x ) - 1);
		}
		if (x != rows-1) {
			_neighborParticles.push_back(( rows * y + x ) + 1);
		}
		if (y != columns-1) {
			_neighborParticles.push_back(( rows * y + x) + rows);
		}
		if (y != 0) {
			_neighborParticles.push_back(( rows * y + x) - rows);
		}
				
	}
	
	//FireFlyParticle particle;
	particle.pos.copyFrom(particlePos);
	particle.targetPos.copyFrom(particlePos);
}
		


bool FireFlyParticleController::startShuffle()
{
	if (isOccupied == false) {
		return false;
	}
	if (borderFlag) {
		return false;
	}
	
	//dispatchEvent( new Event(FIREFLY_ENTERED, true) ); // TODO - replace this with signal?

	isOccupied = false;				
	checkPath();
	
	return true;
}
		
bool FireFlyParticleController::checkPath()
{	
	if (borderFlag)
	{
		isOccupied = true;				
				
		FireFlyParticle newParticle;
					
		if (x == 0) { 
			newParticle.pos.reset(0, particlePos.y);
		} else if (x == (rows - 1)) {
			newParticle.pos.reset( getWindowWidth(), particlePos.y );
		} else if (y == 0) { 
			newParticle.pos.reset(particlePos.x, 0);
		} else if (y == (columns - 1)) {
			newParticle.pos.reset( particlePos.x, getWindowWidth() );
		}
					
		newParticle.targetPos.copyFrom(particlePos);
				
		newParticle.isActive = true;
		newParticle.fadeIn = true;

		particle = newParticle;	
				
		// dispatchEvent( new Event(FIREFLY_LEFT, true) ); // TODO - replace this
				
		return true;
	}
			
	std::vector<int> possibleNeighbors;
	int neighborParticleIndex;
			
	for( int i = 0; i < 4; i++ )
	{
		neighborParticleIndex = _neighborParticles[i];
				
		if (ffparticles->at(neighborParticleIndex).isOccupied && ffparticles->at(neighborParticleIndex).borderFlag) {
			possibleNeighbors.push_back(neighborParticleIndex);
			break;
		} else if(ffparticles->at(neighborParticleIndex).index == previousIndex) {
			continue;
		} else if(ffparticles->at(neighborParticleIndex).isOccupied) {
			possibleNeighbors.push_back(neighborParticleIndex);
		}
	} 
			
	if (possibleNeighbors.size() == 0) {
		return false;
	}
			
	int activeNeighborIndex = floor( randFloat( 0, possibleNeighbors.size()-1) );
	int	activeNeighbor = possibleNeighbors[activeNeighborIndex];
	int	chosenIndex = 0;
				
	int len = _neighborParticles.size();
	for ( int j = 0; j < len; j++) {
		if (_neighborParticles[j] == activeNeighbor) {
			chosenIndex = j;
			break;	
		}
	}
			
	_takeFrom = chosenIndex;
			
	ffparticles->at(activeNeighbor).giveTo = neighborOrder[_takeFrom];
	ffparticles->at(activeNeighbor).previousIndex = index;
			
	checkWave();
			
	particle.pos.copyFrom(ffparticles->at(activeNeighbor).particlePos);

	isOccupied = false;
	isActive = true;
			
	activeParticles->push_back( ffparticles->at(activeNeighbor) );
	
	return true;
}


void FireFlyParticleController::setParticleFollow()
{
	particle.targetPos.copyFrom(particlePos);
	particle.isActive = true;
	isActive = false;
	isOccupied = true;
	particle.isNormal = true;
}

	
void FireFlyParticleController::checkWave()
{	
	
	//var waveNextIndexes : Array = _grid.waveStartScheme["" + _takeFrom + "" + giveTo + ""];

	std::vector<int> waveNextIndexes;
	//int o[] = { 0, 1, 3, 6, 7 };
	//waveNextIndexes.push_back( std::vector<int>( o, o+(sizeof(o)/sizeof(o[0])) ) );

	waveNextIndexes.push_back( 0 );
	waveNextIndexes.push_back( 1 );
	waveNextIndexes.push_back( 3 );
	waveNextIndexes.push_back( 6 );
	waveNextIndexes.push_back( 7 );

	int len = waveNextIndexes.size();
	int waveIndex;
	//var controller : FireFlyParticleController;
			
	for( int i = 0; i < len; i++ )
	{
		//if( ffparticles[_neighborParticles[waveNextIndexes[i]]] )
		if( true )
		{
			waveIndex = waveNextIndexes[i];

			if( ffparticles->at(_neighborParticles[waveIndex]).isOccupied && ! ffparticles->at(_neighborParticles[waveIndex]).isActive && ! ffparticles->at(_neighborParticles[waveIndex]).particle.isActive )
			{
				FireFlyParticleController controller = ffparticles->at(_neighborParticles[waveIndex]);
						
				controller.exciter = neighborOrder[waveIndex];
				controller.waveIteration = 0;
				controller.waveState = 0;
				waveparticles->push_back(controller);
			}
			
		} else {
			//trace("waveNextIndex not found for: ", _neighborParticles[waveNextIndexes[i]]);	
		}
	}
	
}


bool FireFlyParticleController::resetGrid()
{
	if (isActive || particle.isActive || particle.pos.equals(particlePos)) {
		return false;
	}
			
	particle.targetPos.copyFrom(particlePos);
	particle.isActive = true;
	particle.isWave = true;
	particle.isNormal = false;

	return true;
}



bool FireFlyParticleController::makeWave()
{

	if (borderFlag || !isOccupied || isActive || particle.isActive) {
		return false;
	}

	if (waveState == 0) {
				
		Vect force = particlePos.clone();
		int	exciterIndex = _neighborParticles[exciter];
				
		force.minusEq(ffparticles->at(exciterIndex).pos);
				
		if (force.magnitude() > 1) {
			if (exciter > 3) {
				force.multiplyEq(0.155);
			} else {
				force.multiplyEq(0.15);	
			}
			particle.targetPos.plusEq(force);
			particle.isActive = true;
			particle.isWave = true;
			particle.isNormal = false;
		} 
				
		reactToWave();				
	} else if (waveState > 0) {
		reactToWave();
	}

	return true;
}
		

bool FireFlyParticleController::reactToWave()
{
	if (isActive || !isOccupied || borderFlag) {
		return false;
	}
			
	//var considerParticles : Array = waveScheme[ neighborOrder[ exciter ] ];
	// TODO
	std::vector<int> considerParticles;// = { 0, 1, 2, 4, 5 };
	considerParticles.push_back(0);
	considerParticles.push_back(1);
	considerParticles.push_back(2);
	considerParticles.push_back(4);
	considerParticles.push_back(5);

	float damping = 0;
	float waveDamping = 0.05;
	
	int len = considerParticles.size();
	Vect force;
	int considerParticlesIndex;
	FireFlyParticleController controller;			
			
	for( int i=0;  i < len; i++) {

		considerParticlesIndex = considerParticles[i];
		controller = ffparticles->at( _neighborParticles[considerParticlesIndex] );
				
		if (!controller.isOccupied || controller.isActive || controller.particle.isActive || controller.borderFlag) {
			continue;
		}
		controller.waveState = waveState + 1;
				
		force = controller.particle.pos.clone();
				
		force.minusEq(particle.pos);
				
		if (force.magnitude() > 1) {
			if (i > 2) {
				force.multiplyEq(0.155);	
			} else {
				force.multiplyEq(0.15);	
			}
					
			damping += waveDamping;
			if (damping >= 1) {
				damping = 1;	
			}
					
			force.multiplyEq(1-damping);
					
			controller.particle.targetPos.plusEq(force);
			controller.particle.isActive = true;
			controller.particle.isWave = true;
			controller.particle.isNormal = false;				
		}				
	}

	return true;
}

	
bool FireFlyParticleController::repel()
{
	if (particle.isActive || particle.isWave) {				
		return false;	
	}
	
	Vect thisParticlePos = particle.pos.clone();
	Vect repelForce = thisParticlePos.clone();
	float distanceToRepel = (ffparticles->at(1).particlePos.x - ffparticles->at(0).particlePos.x);
	int magnitude = 0;
	float repelStrength = 0;
	float speed = 0.01;
	Vect borderParticlePos;
	int totalRepelForce = 0;
	float dampen = 0.2;
	//FireFlyParticle borderParticle;
			
	for ( int i = 3; i >=0; i--)
	{
		if ( borderFlag && !(_neighborParticles[i]) ) {
			continue;	
		}
				
		FireFlyParticle borderParticle = ffparticles->at(_neighborParticles[i]).particle;
				
		repelForce.copyFrom(thisParticlePos);
		repelForce.minusEq(borderParticle.pos);

		magnitude = repelForce.magnitude();
		repelStrength = distanceToRepel-magnitude;
		
		if(repelStrength > 1 && magnitude > 1)	{						
			repelForce.multiplyEq(speed);
			particle.vel.plusEq(repelForce);
			totalRepelForce += magnitude;
		}

	}	
			
	if (totalRepelForce > 1) {
		isRepelling = true;
	} else {
		isRepelling = false;
	}
	
	return true;
}



bool FireFlyParticleController::applyFade()
{

	// TODO - nail this 

	
	if (particle.pos.equals(particlePos)) {
		return false;
	}

	int defaultDistance = ffparticles->at(1).particlePos.x - ffparticles->at(0).particlePos.x;
	float scaler = defaultDistance/15;
	Vect tempPos = particle.pos.clone();
	int distanceFromOriginalPos = particle.pos.x;//tempPos.minusEq(particlePos).magnitude();
	int fade = floor((distanceFromOriginalPos * scaler / defaultDistance) * 10);
				
	//fade = fade > 10 ? 10 : (fade < 1 ? 1 : (0.5 + fade) | 0);
			
	particle.fade = distanceFromOriginalPos > 0 ? (fade > 0 ? fade : 1) : 1;
			
	return true;



//	return false;
}