#include "IconRenderer.h"


using namespace ci;

IconRenderer::IconRenderer(){
	std::vector<TweenParticle> points;
	mPoints = points;
	pos = Vec2f(0.0,0.0);
	rotation = 0;
	scale = 1.0;
}

//creates a lookup table of gr

void IconRenderer::animateIn(){

		float t = 0;////offset each time value slightly

		for( std::vector<TweenParticle>::iterator p = mPoints.begin(); p != mPoints.end(); ++p ){
				float destRad = p->rad;
				p->rad = 0;
				p->animateTo(ci::Vec2f(p->xpos,p->ypos),getRandomPointOnGrid(),1.5,ci::app::getElapsedSeconds()+t,destRad);
				p->update(ci::app::getElapsedSeconds());
		}

}


void IconRenderer::animateOut(){

		for( std::vector<TweenParticle>::iterator p = mPoints.begin(); p != mPoints.end(); ++p ){
			p->animateTo(getRandomPointOnGrid(), ci::Vec2f(p->xpos,p->ypos),1.0,ci::app::getElapsedSeconds(),0);
			p->update(ci::app::getElapsedSeconds());
		}
}

ci::Vec2f IconRenderer::getRandomPointOnGrid(){
	
	int SPACING = 38;

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


		// kill this all and refresh
	gl::disableAlphaBlending();
	gl::enableAlphaBlending();
	gl::enableAdditiveBlending();

	gl::color( ColorA( 1, 1, 1, 1 ) );


	gl::pushMatrices();
	gl::translate(pos.value().x, pos.value().y, 0.0);
	gl::rotate(rotation);
	gl::scale(scale.value(), scale.value(), 1.0);
	for( std::vector<TweenParticle>::iterator p = mPoints.begin(); p != mPoints.end(); ++p ){
		p->update(cinder::app::getElapsedSeconds());
		p->draw();
	}
	gl::popMatrices();



	gl::disableAlphaBlending();


}