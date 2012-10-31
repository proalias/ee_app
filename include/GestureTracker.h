#ifndef GestureTracker_h
#define GestureTracker_h
#include "cinder/Cinder.h"
#include "Kinect.h"


class GestureTracker
{
private:
	std::map<int,std::list<ci::Vec3f>> bonePositions;
	int maxFrames;

    static bool instanceFlag;
    static GestureTracker *single;
	
    GestureTracker()
    {

    }

public:
    
	void addPoint(int boneIndex, ci::Vec3f position);
	bool lookForGesture(int gesture);

	static const int GESTURE_WAVE = 0;

	static GestureTracker* getInstance();

    ~GestureTracker()
    {
        instanceFlag = false;
    }
};


#endif