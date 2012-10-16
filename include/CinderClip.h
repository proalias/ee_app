#ifndef CINDERCLIP_H
#define CINDERCLIP_H

#include "cinder\Cinder.h"
#include "cinder\Vector.h"
#include "cinder\gl\gl.h"
#include <stdio.h>
#include <string.h>
#include "cinder\app\MouseEvent.h"
#include "cinder\CinderMath.h"
#include "cinder\Rand.h"

class CinderClip{
public:
	
	//flash properties
	float x;
	float y;
	float rotation;
	float width;
	float height;
	float scaleX;
	float scaleY;

	//new properties
	float minDist;
	float k;

	ci::Vec2f getCenter();

	CinderClip(void);

};

#endif