#include "GestureTracker.h"

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
	
	maxFrames = 30;

	if (bonePositions[boneIndex].size() == maxFrames){
		bonePositions[boneIndex].pop_front();
	}
	bonePositions[boneIndex].push_back(position);
}


bool GestureTracker::lookForGesture(int gestureId){
	//TODO - call appropriate gesture recognition method, return result.
	switch(gestureId){
		case GESTURE_WAVE : 
				break;

	}

	return false;
}