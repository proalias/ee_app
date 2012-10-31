#ifndef IconRenderer_H
#define IconRenderer_H


#include "cinder/Cinder.h"
#include "cinder/Timeline.h"
#include <stdio.h>
#include "TweenParticle.h"
#include "cinder/app/AppBasic.h"

class IconRenderer{
public :
	IconRenderer( void ); 
	void setPoints( std::vector<TweenParticle> &points);
	void draw();
	void update();
	
	void disperseParticles();
	ci::Anim<ci::Vec2f> pos;
	ci::Anim<float> scale;

	std::vector<TweenParticle> mPoints;

private:
	ci::Vec2f IconRenderer::getRandomPointOnGrid();
};
#endif