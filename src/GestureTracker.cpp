#include "GestureTracker.h"



void GestureTracker::addPoint(int boneIndex, ci::Vec3f position){
	
	maxFrames = 30;

	if (bonePositions[boneIndex].size() == maxFrames){
		bonePositions[boneIndex].pop_front();
	}
	bonePositions[boneIndex].push_back(position);
}

bool GestureTracker::lookForGesture(int gestureId){
	//TODO - call appropriate gesture recognition method, return result.
	return false;
}