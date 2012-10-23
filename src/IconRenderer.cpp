#include "IconRenderer.h"


IconRenderer::IconRenderer(){
	std::vector<TweenParticle> points;
	mPoints = points;
	pos = Vec2f(0.0,0.0);
	
	scale = 1.0;
}

void IconRenderer::disperseParticles(){

		for( std::vector<TweenParticle>::iterator p = mPoints.begin(); p != mPoints.end(); ++p ){
			p->animateTo(getRandomPointOnGrid(), ci::Vec2f(p->xpos,p->ypos),1.0,ci::app::getElapsedSeconds(),0);
			p->update(ci::app::getElapsedSeconds());
		}
}

ci::Vec2f IconRenderer::getRandomPointOnGrid(){
	
	int SPACING = 40;

	float COLUMNS = cinder::app::getWindowWidth()/SPACING;
	float ROWS = cinder::app::getWindowHeight()/SPACING;
	
	float pX = randInt(-COLUMNS, COLUMNS)*SPACING;
	float pY = randInt(-ROWS, ROWS)*SPACING;
	return ci::Vec2f(pX,pY);	
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