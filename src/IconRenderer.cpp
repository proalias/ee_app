#include "IconRenderer.h"


IconRenderer::IconRenderer(){
	std::vector<TweenParticle> points;
	mPoints = points;
	xPos = 0.0;
	yPos = 0.0;
	xScale = 1.0;
	yScale = 1.0;
}


void IconRenderer::setPoints( std::vector<TweenParticle> &points){
	mPoints = points;
}

void IconRenderer::tweenTo( Timeline &timeline, float xPosDest, float yPosDest, float duration )
{
	timeline.apply( &xPos, xPosDest, duration, EaseOutBack( 0.3 ) );
	timeline.apply( &yPos, yPosDest, duration, EaseOutBack( 0.3 ) );
}

void IconRenderer::draw(){
	gl::pushMatrices();
	gl::translate(this->xPos, this->yPos, 0.0);
	gl::scale(this->xScale, this->yScale, 1.0);
	for( std::vector<TweenParticle>::iterator p = mPoints.begin(); p != mPoints.end(); ++p ){
		p->draw();
	}
	gl::popMatrices();
}