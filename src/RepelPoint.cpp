#ifndef REPELPOINT_H
#define REPELPOINT_H
#include "RepelPoint.h"

RepelPoint::RepelPoint(float x, float y, float k, float minDist){
	this->x = x;
	this->y = y;
	this->k = k;
	this->minDist = minDist;
}

#endif