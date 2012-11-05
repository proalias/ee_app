#include "GestureTracker.h"

#include "cinder\gl\gl.h"

using namespace ci;
using namespace gl;

bool GestureTracker::instanceFlag = false;
GestureTracker* GestureTracker::single = NULL;

GestureTracker* GestureTracker::getInstance()
{
    if(! instanceFlag)
    {
        single = new GestureTracker();
        instanceFlag = true;

        return single;
    }
    else
    {
        return single;
    }
}

void GestureTracker::addPoint(int boneIndex, ci::Vec3f position){
	
	maxFrames = 60;

	if (bonePositions[boneIndex].size() == maxFrames){
		bonePositions[boneIndex].pop_front();
	}
	bonePositions[boneIndex].push_back(position);
}



bool GestureTracker::lookForGesture(int gestureId){
	//TODO - call appropriate gesture recognition method, return result.
	switch(gestureId){
		case GESTURE_WAVE : 
			if (this->lookForWaveLeft()==true || lookForWaveRight()==true){
				return true;
			}		
			break;
	}

	return false;
}

bool GestureTracker::lookForWaveLeft(){
	bool gestureDetected = false;

	float lastX = bonePositions[NUI_SKELETON_POSITION_HAND_LEFT].front().x;
	float lastY = bonePositions[NUI_SKELETON_POSITION_HAND_LEFT].front().y;

	float lastVX = 0;
	float lastVY = 0;

	int directionChanges = 0;
	//analyse left hand velocity
	int frameIndex = 0;
	for (std::list<ci::Vec3f>::iterator p = bonePositions[NUI_SKELETON_POSITION_HAND_LEFT].begin(); p != bonePositions[NUI_SKELETON_POSITION_HAND_LEFT].end(); p++, frameIndex++){
		
		//check hand is above lower back
		if (p->y > bonePositions[NUI_SKELETON_POSITION_SPINE].back().y){

			//check for changes in velocity
			float vX, vY;
			vX = lastX - p->x;
			vY = lastY - p->y;
		
			
			if (vX < 0 && lastVX > 0){
				directionChanges += 1;
			}

			if (vX > 0 && lastVX < 0){
				directionChanges += 1;
			}

			lastVX = vX;
			lastVY = vY;
		}

		if (directionChanges > 2){
			gestureDetected = true;
		}
	}
	return gestureDetected;
}

bool GestureTracker::lookForWaveRight(){
	bool gestureDetected = false;

	float lastX = bonePositions[NUI_SKELETON_POSITION_HAND_RIGHT].front().x;
	float lastY = bonePositions[NUI_SKELETON_POSITION_HAND_RIGHT].front().y;

	float lastVX = 0;
	float lastVY = 0;

	int directionChanges = 0;
	//analyse right hand velocity

	int frameIndex = 0;
	for (std::list<ci::Vec3f>::iterator p = bonePositions[NUI_SKELETON_POSITION_HAND_RIGHT].begin(); p != bonePositions[NUI_SKELETON_POSITION_HAND_RIGHT].end(); p++, frameIndex++){
		
		//check hand is above lower back
		if (p->y > bonePositions[NUI_SKELETON_POSITION_SPINE].back().y){

			//ci::gl::color(ci::Color(1.0,0.0,0.0));
			//ci::gl::drawSolidCircle(ci::Vec2f(100,100),100);

			//check for changes in velocity
			float vX, vY;
			vX = lastX - p->x;
			vY = lastY - p->y;
		
			

			if (vX < 0 && lastVX > 0){
				directionChanges += 1;
			}

			if (vX > 0 && lastVX < 0){
				directionChanges += 1;
			}

			lastVX = vX;
			lastVY = vY;
		}

		if (directionChanges > 2){
			gestureDetected = true;
		}
	}
	return gestureDetected;
}
