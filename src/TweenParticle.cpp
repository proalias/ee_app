#include "TweenParticle.h"

TweenParticle::TweenParticle( float pX,float pY,float pRad, bool jitters)
{
	moving = false;
	xpos = pX;
	ypos = pY;
	rad = pRad;
	snapback = ci::randFloat(1.3);
	color = Color(1.0,1.0,1.0);

	mDestRad = pRad;
	mStartRad = pRad;
	
	mPerlin = Perlin();
	this->jitters = jitters;
	jitterSpeed = randFloat(-10,10);
	xJitter = 0;
	yJitter = 0;
	alpha = randFloat (0.8,1.0);
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

	noise = 0;
	xJitter = 0;
	yJitter = 0;
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

	
	gl::color(ColorA(1.0,1.0,1.0,alpha));
	gl::drawSolidCircle(ci::Vec2f(xpos + xJitter, ypos + yJitter) ,rad);
	
	

	/* TODO - get particles drawing with textures
	float halfRad = rad * 0.5;
	Rectf rect = Rectf(xpos - halfRad,ypos - halfRad,xpos+halfRad, ypos+halfRad);
	gl::draw(,rect);
	*/
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
	if (jitters==true){
		noise =  mPerlin.fBm( xpos, ypos, t * 0.1f ) * 10;
	
		xJitter = cinder::math<float>::sin(t*jitterSpeed) * noise;
		yJitter = cinder::math<float>::cos(t*jitterSpeed) * noise;
	}
	
}
float TweenParticle::ease(float time,float begin,float change,float duration,float snapback = 1.70158){
	return change*((time=time/duration-1)*time*((snapback+1)*time + snapback) + 1) + begin;
}

