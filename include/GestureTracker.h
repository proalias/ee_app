#ifndef GestureTracker_h
#define GestureTracker_h
#include "cinder/Cinder.h"
#include "Kinect.h"

class GestureTracker{
public:
	void addPoint(int boneIndex, ci::Vec3f position);
	bool lookForGesture(int gesture);
private:
	std::map<int,std::list<ci::Vec3f>> bonePositions;
	int maxFrames;
};
#endif