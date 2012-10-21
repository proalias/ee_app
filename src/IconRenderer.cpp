#include "IconRenderer.h"


IconRenderer::IconRenderer(){
	std::vector<TweenParticle> points;
	mPoints = points;
	pos = Vec2f(0.0,0.0);
	
	scale = 1.0;
}


void IconRenderer::setPoints( std::vector<TweenParticle> &points){
	mPoints = points;
}

void IconRenderer::draw(){
	gl::pushMatrices();
	gl::translate(pos.value().x, pos.value().y, 0.0);
	gl::scale(scale.value(), scale.value(), 1.0);
	for( std::vector<TweenParticle>::iterator p = mPoints.begin(); p != mPoints.end(); ++p ){
		p->update(cinder::app::getElapsedSeconds());
		p->draw();
	}
	gl::popMatrices();
}