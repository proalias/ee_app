#pragma once
#include "cinder/Channel.h"
#include "cinder/Vector.h"

#include <vector>

class Particle {
 public:
	Particle();
	Particle( ci::Vec2f, float );
	void update();
	void draw();
	
	ci::Vec2f	sLoc; // start locations im adding so if location changes they can return
	ci::Vec2f	mLoc;
	ci::Vec2f	mDir;
	float		mVel;
	
	float		mRadius;
};