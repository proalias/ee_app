#ifndef TWEENPARTICLE_H
#define TWEENPARTICLE_H

#include "cinder\Cinder.h"
#include "cinder\Timeline.h"
#include "cinder\Vector.h"
#include "cinder\gl\gl.h"
#include "cinder\Rand.h"
#include "cinder\Perlin.h"
#include "cinder\CinderMath.h"
#include "TextureGlobals.h"
#include "ColorConstants.h"
#include "cinder\app\App.h"
#include "cinder\Easing.h"
//#include "ParticleImageContainer.h"


class TweenParticle {
public:
	
	TweenParticle( float pX,float pY,float pRad, bool isRandomised);
	void update(double t);
	void draw();

	float ease(float time,float begin,float change,float duration,float snapback);
	void tweenTo(float px, float py);
	void animateTo(ci::Vec2f dest, ci::Vec2f begin, float duration, float startTime, float newrad, float delay);
	void animateTo(ci::Vec2f dest, ci::Vec2f begin, float duration, float startTime, float rad);
	void animateTo(ci::Vec2f dest, float duration, float startTime, float rad);
	float xpos;
	float ypos;
	float rad;
	ci::Color color;
	bool moving;
	int textureType;
	float delay;

	ci::Anim <float> colorR;
	ci::Anim <float> colorG;
	ci::Anim <float> colorB;
	
	bool __isYellow;
	void isYellow( bool isYellow);

	
	void TweenParticle::tweenYellowToWhite(float delay, float duration);
	void TweenParticle::tweenWhiteToYellow(float delay, float duration);

	bool jitters;
	ci::gl::Texture* particleTexture;
	
	//ci::Timeline	&mTimeline;
	float mDuration;
	float mStartTime;

	float mDestRad;
	float mStartRad;

	ci::Vec2f mDest;
	ci::Vec2f mBegin;

	float snapback;

	//jitter values
	ci::Perlin mPerlin;
	float noise;
	float xJitter;
	float yJitter;
	float jitterSpeed;

	int sparking;

};
#endif