#ifndef OutlineParams_h
#define OutlineParams_h

#include "cinder/cinder.h"
#include "cinder/Vector.h"
#include "cinder/params/Params.h"
#include "Kinect.h"

using namespace cinder;

class OutlineParams {
private:
    static bool instanceFlag;
    static OutlineParams *single;
	
    OutlineParams()
    {
        //private constructor
    }
public:
    static OutlineParams* getInstance();
	
    ~OutlineParams()
    {
        instanceFlag = false;
    }

	void init();
	void draw();
	float getForceForIndex(int index);
	float getMinDistForIndex(int index);
	float getMidpointForIndex(int index);
	
	float midpointDefaultDistance;
	float midpointDefaultForce;

	ci::params::InterfaceGl				mParams;

	float NUI_SKELETON_POSITION_HIP_CENTER_force;
	float NUI_SKELETON_POSITION_SPINE_force;
	float NUI_SKELETON_POSITION_SHOULDER_CENTER_force;
	float NUI_SKELETON_POSITION_HEAD_force;
	float NUI_SKELETON_POSITION_SHOULDER_LEFT_force;
	float NUI_SKELETON_POSITION_ELBOW_LEFT_force;
	float NUI_SKELETON_POSITION_WRIST_LEFT_force;
	float NUI_SKELETON_POSITION_HAND_LEFT_force;
	float NUI_SKELETON_POSITION_SHOULDER_RIGHT_force;
	float NUI_SKELETON_POSITION_ELBOW_RIGHT_force;
	float NUI_SKELETON_POSITION_WRIST_RIGHT_force;
	float NUI_SKELETON_POSITION_HAND_RIGHT_force;
	float NUI_SKELETON_POSITION_HIP_LEFT_force;
	float NUI_SKELETON_POSITION_KNEE_LEFT_force;
	float NUI_SKELETON_POSITION_ANKLE_LEFT_force;
	float NUI_SKELETON_POSITION_FOOT_LEFT_force;
	float NUI_SKELETON_POSITION_HIP_RIGHT_force;
	float NUI_SKELETON_POSITION_KNEE_RIGHT_force;
	float NUI_SKELETON_POSITION_ANKLE_RIGHT_force;
	float NUI_SKELETON_POSITION_FOOT_RIGHT_force;



	float NUI_SKELETON_POSITION_HIP_CENTER_distance;
	float NUI_SKELETON_POSITION_SPINE_distance;

	float NUI_SKELETON_POSITION_SHOULDER_CENTER_distance;
	float NUI_SKELETON_POSITION_HEAD_distance;
	float NUI_SKELETON_POSITION_SHOULDER_LEFT_distance;
	float NUI_SKELETON_POSITION_ELBOW_LEFT_distance;
	float NUI_SKELETON_POSITION_WRIST_LEFT_distance;
	float NUI_SKELETON_POSITION_HAND_LEFT_distance;
	float NUI_SKELETON_POSITION_SHOULDER_RIGHT_distance;
	float NUI_SKELETON_POSITION_ELBOW_RIGHT_distance;
	float NUI_SKELETON_POSITION_WRIST_RIGHT_distance;
	float NUI_SKELETON_POSITION_HAND_RIGHT_distance;
	float NUI_SKELETON_POSITION_HIP_LEFT_distance;
	float NUI_SKELETON_POSITION_KNEE_LEFT_distance;
	float NUI_SKELETON_POSITION_ANKLE_LEFT_distance;
	float NUI_SKELETON_POSITION_FOOT_LEFT_distance;
	float NUI_SKELETON_POSITION_HIP_RIGHT_distance;
	float NUI_SKELETON_POSITION_KNEE_RIGHT_distance;
	float NUI_SKELETON_POSITION_ANKLE_RIGHT_distance;
	float NUI_SKELETON_POSITION_FOOT_RIGHT_distance;

	float NUI_SKELETON_POSITION_HIP_CENTER_midpoint;
	float NUI_SKELETON_POSITION_SPINE_midpoint;
	float NUI_SKELETON_POSITION_SHOULDER_CENTER_midpoint;
	float NUI_SKELETON_POSITION_HEAD_midpoint;
	float NUI_SKELETON_POSITION_SHOULDER_LEFT_midpoint;
	float NUI_SKELETON_POSITION_ELBOW_LEFT_midpoint;
	float NUI_SKELETON_POSITION_WRIST_LEFT_midpoint;
	float NUI_SKELETON_POSITION_HAND_LEFT_midpoint;
	float NUI_SKELETON_POSITION_SHOULDER_RIGHT_midpoint;
	float NUI_SKELETON_POSITION_ELBOW_RIGHT_midpoint;
	float NUI_SKELETON_POSITION_WRIST_RIGHT_midpoint;
	float NUI_SKELETON_POSITION_HAND_RIGHT_midpoint;
	float NUI_SKELETON_POSITION_HIP_LEFT_midpoint;
	float NUI_SKELETON_POSITION_KNEE_LEFT_midpoint;
	float NUI_SKELETON_POSITION_ANKLE_LEFT_midpoint;
	float NUI_SKELETON_POSITION_FOOT_LEFT_midpoint;
	float NUI_SKELETON_POSITION_HIP_RIGHT_midpoint;
	float NUI_SKELETON_POSITION_KNEE_RIGHT_midpoint;
	float NUI_SKELETON_POSITION_ANKLE_RIGHT_midpoint;
	float NUI_SKELETON_POSITION_FOOT_RIGHT_midpoint;

	bool showForces;

};

#endif