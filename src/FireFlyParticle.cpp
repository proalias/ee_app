#include "FireFlyParticle.h"

#include "cinder/app/AppBasic.h"
#include "cinder/Utilities.h"

#include "Vect.h"

using namespace ci;
using namespace ci::app;
using namespace std;

FireFlyParticle::FireFlyParticle()
{	
	isNormal = true;
	isActive = false;
	isWave = false;
		
	fade = 1;
	fadeIn = false;
	
	// [0, 1, 1.34, 1.68, 2.02, 2.36, 2.70, 3.04, 3.38, 3.72, 4.06];
	_fadeSizes.push_back(0);
	_fadeSizes.push_back(1);
	_fadeSizes.push_back(1.34);
	_fadeSizes.push_back(1.68);
	_fadeSizes.push_back(2.02);
	_fadeSizes.push_back(2.36);
	_fadeSizes.push_back(2.70);
	_fadeSizes.push_back(3.04);
	_fadeSizes.push_back(3.38);
	_fadeSizes.push_back(3.72);
	_fadeSizes.push_back(4.06);

	_drag = 0.5; 
	_speed = 0.07;		
}

void FireFlyParticle::applyShuffle()
{
	_force.copyFrom(targetPos); 
	_force.minusEq(pos); 
				
	if (_force.magnitude() > 1)
	{
		float newSpeed = isNormal ? _speed : _speed/2;
		_force.multiplyEq(newSpeed);
		vel.plusEq(_force);
	}
	else
	{
		isActive = false;
		isWave = false;
		isNormal = true;
		vel.reset(0,0);
		pos.reset( targetPos.x, targetPos.y );				
	}
}
		
void FireFlyParticle::update()
{
	// simulate drag
	vel.multiplyEq(_drag);
			
	// add the velocity to the position
	pos.plusEq(vel);
			
	if (fade > 2 && !fadeIn){
		fade -= 1;	
	} else if (fade < 5 && fadeIn) {
		fade += 1;
	} else {
		fadeIn = false;	
	}

	//scaleX = scaleY = _fadeSizes[this.fade];
}

void FireFlyParticle::draw()
{
	gl::drawSolidCircle( Vec2f(pos.x,pos.y), _fadeSizes[fade]*2 );//2 );//_fadeSizes[fade] );
}