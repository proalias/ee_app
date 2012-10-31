#include "TweenParticle.h"


TweenParticle::TweenParticle( float pX,float pY,float pRad, bool isRandomised)
{
	moving = false;
	xpos = pX;
	ypos = pY;
	rad = pRad;
	snapback = ci::randFloat(1.3 + 0.8);
	color = Color(1.0,1.0,1.0);

	colorR = color.r;
	colorG = color.g;
	colorB = color.b;

	mDestRad = pRad;
	mStartRad = pRad;
	
	mPerlin = Perlin();
	this->jitters = isRandomised;//if the particle is text, don't make it jitter.
	jitterSpeed = randFloat(-10,10);
	xJitter = 0;
	yJitter = 0;

	
	sparking = false;

	if (!isRandomised){
		textureType = 0;
	}else if (randFloat(1.0) > 0.8){
		textureType = randInt(4)+1;
		
	}else{
		textureType = 0;
	}
	
	particleTexture = TextureGlobals::getInstance()->getParticleTexture(textureType);
	
}

void TweenParticle::isYellow( bool isYellow = false){
	__isYellow = isYellow;
	//if (isYellow == true){
	//	particleTexture = TextureGlobals::getInstance()->getParticleTexture(7);
	//}else{
	//	particleTexture = TextureGlobals::getInstance()->getParticleTexture(0);
	//}
}


void TweenParticle::tweenTo(float px, float py){
	//mTimeline.apply(&xpos,px,3.0,ci::EaseOutBack());
}


void TweenParticle::animateTo(ci::Vec2f dest, ci::Vec2f begin, float duration, float startTime, float newrad, float delay){
	mDest = dest;
	mBegin = begin;
	mDuration = duration;
	mStartTime = startTime;
	mStartRad = rad;
	mDestRad = newrad;
	moving = true;
	delay = delay;
	noise = 0;
	xJitter = 0;
	yJitter = 0;
}

void TweenParticle::animateTo(ci::Vec2f dest, ci::Vec2f begin, float duration, float startTime, float newrad){
	mDest = dest;
	mBegin = begin;
	mDuration = duration;
	mStartTime = startTime;
	mStartRad = rad;
	mDestRad = newrad;
	moving = true;
	delay = 0;
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
	delay = 0;

}

void TweenParticle::draw(){

	if (__isYellow == true){
		gl::color(colorR, colorG, colorB);
		gl::drawSolidCircle(ci::Vec2f(xpos + xJitter, ypos + yJitter) ,rad);
		gl::color(1.0,1.0,1.0,1.0);
		return;
	}
	

		
	Rectf rect = Rectf(xpos - rad*2 + xJitter, ypos - rad*2 + yJitter,xpos+rad*2 + xJitter, ypos+rad*2+ yJitter);
	gl::draw(*particleTexture,rect);
	

	
	/* TODO - get particles drawing with textures
	float halfRad = rad * 0.5;
	Rectf rect = Rectf(xpos - halfRad,ypos - halfRad,xpos+halfRad, ypos+halfRad);
	gl::draw(,rect);
	*/
}



void TweenParticle::tweenWhiteToYellow(float delay, float duration){
	ci::app::timeline().apply(&colorR,ColorConstants::WHITE.r,ColorConstants::PRIMARY_YELLOW.r,duration,ci::EaseInQuad() ).delay(delay);
	ci::app::timeline().apply(&colorG,ColorConstants::WHITE.g,ColorConstants::PRIMARY_YELLOW.g,duration,ci::EaseInQuad() ).delay(delay);
	ci::app::timeline().apply(&colorB,ColorConstants::WHITE.b,ColorConstants::PRIMARY_YELLOW.b,duration,ci::EaseInQuad() ).delay(delay);
}

void TweenParticle::tweenYellowToWhite(float delay, float duration){
	ci::app::timeline().apply(&colorR,ColorConstants::PRIMARY_YELLOW.r,ColorConstants::WHITE.r,duration,ci::EaseInQuad() ).delay(delay);
	ci::app::timeline().apply(&colorG,ColorConstants::PRIMARY_YELLOW.g,ColorConstants::WHITE.g,duration,ci::EaseInQuad() ).delay(delay);
	ci::app::timeline().apply(&colorB,ColorConstants::PRIMARY_YELLOW.b,ColorConstants::WHITE.b,duration,ci::EaseInQuad() ).delay(delay);
}

void TweenParticle::update(double t){
	if (moving){
		if (t < mDuration+mStartTime+delay ){
			float time = t - mStartTime - delay;
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

		if (sparking == 0 && randFloat(1.0) > 0.99){
			sparking = 20;
		}

		if (sparking > 0){
			sparking -= 1;
			textureType = sparking % 4 +1;
			particleTexture = TextureGlobals::getInstance()->getParticleTexture(textureType);
		}else if (sparking == 0){
			textureType = 0;
			particleTexture = TextureGlobals::getInstance()->getParticleTexture(textureType);
		}
	}
}

float TweenParticle::ease(float time,float begin,float change,float duration,float snapback = 1.70158){
	return change*((time=time/duration-1)*time*((snapback+1)*time + snapback) + 1) + begin;
}

