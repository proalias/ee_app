#ifndef TWEENPARTICLE_H
#define TWEENPARTICLE_H

#include "cinder\Cinder.h"
#include "cinder\Timeline.h"
#include "cinder\Vector.h"
#include "cinder\gl\gl.h"
#include "cinder\Rand.h"
#include "cinder\Perlin.h"
#include "cinder\CinderMath.h"
#include "cinder\app\AppBasic.h"
//#include "ParticleImageContainer.h"

using namespace cinder;

class TweenParticle {
public:
	TweenParticle(float pX,float pY,float pRad);
	void update(double t);
	void draw();

	float ease(float time,float begin,float change,float duration,float snapback);
	void tweenTo(float px, float py);
	void animateTo(ci::Vec2f dest, ci::Vec2f begin, float duration, float startTime, float rad);
	void animateTo(ci::Vec2f dest, float duration, float startTime, float rad);
	float xpos;
	float ypos;
	float rad;
	Color color;
	bool moving;

	
	//ci::Timeline	&mTimeline;
	float mDuration;
	float mStartTime;

	float mDestRad;
	float mStartRad;

	ci::Vec2f mDest;
	ci::Vec2f mBegin;

	float snapback;

	//jitter values
	Perlin mPerlin;
	float noise;
	float xJitter;
	float yJitter;
	float jitterSpeed;

};
#endif