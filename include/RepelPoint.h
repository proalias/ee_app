#ifndef REPELPOINT_H
#define REPELPOINT_H

#include "cinder\Cinder.h"
#include "cinder\Vector.h"
#include "cinder\gl\gl.h"
#include <stdio.h>
#include <string.h>
#include "cinder\app\MouseEvent.h"
#include "cinder\CinderMath.h"
#include "cinder\Rand.h"
#include "CinderClip.h"

using namespace ci;

class RepelPoint{
public:
	RepelPoint(float x, float y, float k, float minDist);
	float x;
	float y;
	float minDist;
	float k;
};

#endif