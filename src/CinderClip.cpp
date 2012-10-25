#include "CinderClip.h"

CinderClip::CinderClip(void)
{
	x=0;
	y=0;
	rotation=0;
	width=100;
	height=100;
	scaleX=1;
	scaleY=1;

	//new properties
	minDist=50;
	k=100;

	zDist = 0;
}

ci::Vec2f CinderClip::getCenter(){
	return ci::Vec2f(width/2, height/2);
}