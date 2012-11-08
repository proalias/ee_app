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
    
	
	static const int NO_GESTURE = 0;
	static const int GESTURE_WAVE = 1;
	static const int GESTURE_RUN = 2;
	static const int GESTURE_AIR_GUITAR_STRUM = 3;


	void addPoint(int boneIndex, ci::Vec3f position);
	bool lookForGesture(int gesture);

	bool lookForWaveLeft();
	bool lookForWaveRight();
	float lookForRunningOnTheSpot();

	static GestureTracker* getInstance();

    ~GestureTracker()
    {
        instanceFlag = false;
    }
};


#endif