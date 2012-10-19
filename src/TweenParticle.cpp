
#include "TweenParticle.h"



TweenParticle::TweenParticle( float pX,float pY,float pRad)
{
	moving = false;
	xpos = pX;
	ypos = pY;
	rad = pRad;
	snapback = ci::randFloat(0.4);
	color = Color(1.0,1.0,1.0);

	mDestRad = pRad;
	mStartRad = pRad;
}


void TweenParticle::tweenTo(float px, float py){
	//mTimeline.apply(&xpos,px,3.0,ci::EaseOutBack());
}

void TweenParticle::animateTo(ci::Vec2f dest, ci::Vec2f begin, float duration, float startTime, float newrad){
	mDest = dest;
	mBegin = begin;
	mDuration = duration;
	mStartTime = startTime;
	mStartRad = rad;
	mDestRad = newrad;
	moving = true;
}

void TweenParticle::animateTo(ci::Vec2f dest, float duration, float startTime, float newrad){
	mDest = dest;
	mBegin = ci::Vec2f(xpos, ypos);
	mDuration = duration;
	mStartTime = startTime;
	mStartRad = rad;
	mDestRad = newrad;
	moving = true;
}

void TweenParticle::draw(){
	gl::drawSolidCircle(ci::Vec2f(xpos, ypos) ,rad*2.5);
}

void TweenParticle::update(double t){
	if (moving){
		if (t < mDuration+mStartTime){
			float time = t - mStartTime;
			xpos = ease(time,mBegin.x,mDest.x - mBegin.x, mDuration, snapback);
			ypos = ease(time,mBegin.y,mDest.y - mBegin.y, mDuration, snapback);
			rad =  ease(time,mStartRad,mDestRad - mStartRad, mDuration, snapback);
		}else{
			xpos = mDest.x;
			ypos = mDest.y;
			moving = false;
		}
	}
}
float TweenParticle::ease(float time,float begin,float change,float duration,float snapback = 1.70158){
	return change*((time=time/duration-1)*time*((snapback+1)*time + snapback) + 1) + begin;
}
