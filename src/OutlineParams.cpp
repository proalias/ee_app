#include "OutlineParams.h"

bool OutlineParams::instanceFlag = false;
OutlineParams* OutlineParams::single = NULL;

OutlineParams* OutlineParams::getInstance()
{
    if(! instanceFlag)
    {
        single = new OutlineParams();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}

void OutlineParams::init(){

		 showForces = false;

		 float forceDefault = 50;
		 NUI_SKELETON_POSITION_HIP_CENTER_force = 100;
		 NUI_SKELETON_POSITION_SPINE_force = 50;
		 NUI_SKELETON_POSITION_SHOULDER_CENTER_force = 50;
		 NUI_SKELETON_POSITION_HEAD_force = 100;
		 NUI_SKELETON_POSITION_SHOULDER_LEFT_force = 50;
		 NUI_SKELETON_POSITION_ELBOW_LEFT_force = 100;
		 NUI_SKELETON_POSITION_WRIST_LEFT_force = 100;
		 NUI_SKELETON_POSITION_HAND_LEFT_force = 150;
		 NUI_SKELETON_POSITION_SHOULDER_RIGHT_force = 50;
		 NUI_SKELETON_POSITION_ELBOW_RIGHT_force = 100;
		 NUI_SKELETON_POSITION_WRIST_RIGHT_force = 100;
		 NUI_SKELETON_POSITION_HAND_RIGHT_force = 150;
		 NUI_SKELETON_POSITION_HIP_LEFT_force = 50;
		 NUI_SKELETON_POSITION_KNEE_LEFT_force = 50;
		 NUI_SKELETON_POSITION_ANKLE_LEFT_force = 50;
		 NUI_SKELETON_POSITION_FOOT_LEFT_force = 50;
		 NUI_SKELETON_POSITION_HIP_RIGHT_force = 50;
		 NUI_SKELETON_POSITION_KNEE_RIGHT_force = 50;
		 NUI_SKELETON_POSITION_ANKLE_RIGHT_force = 50;
		 NUI_SKELETON_POSITION_FOOT_RIGHT_force = 50;


		 float distanceDefault = 10;
		 NUI_SKELETON_POSITION_HIP_CENTER_distance = 30;
		 NUI_SKELETON_POSITION_SPINE_distance = 50;
		 NUI_SKELETON_POSITION_SHOULDER_CENTER_distance = 60;
		 NUI_SKELETON_POSITION_HEAD_distance = 50;
		 NUI_SKELETON_POSITION_SHOULDER_LEFT_distance = 50;
		 NUI_SKELETON_POSITION_ELBOW_LEFT_distance = 35;
		 NUI_SKELETON_POSITION_WRIST_LEFT_distance = 30;
		 NUI_SKELETON_POSITION_HAND_LEFT_distance = 40;
		 NUI_SKELETON_POSITION_SHOULDER_RIGHT_distance = 40;
		 NUI_SKELETON_POSITION_ELBOW_RIGHT_distance = 35;
		 NUI_SKELETON_POSITION_WRIST_RIGHT_distance = 30;
		 NUI_SKELETON_POSITION_HAND_RIGHT_distance = 40;
		 NUI_SKELETON_POSITION_HIP_LEFT_distance = 20;
		 NUI_SKELETON_POSITION_KNEE_LEFT_distance = 50;
		 NUI_SKELETON_POSITION_ANKLE_LEFT_distance = 40;
		 NUI_SKELETON_POSITION_FOOT_LEFT_distance = 50;
		 NUI_SKELETON_POSITION_HIP_RIGHT_distance = 50;
		 NUI_SKELETON_POSITION_KNEE_RIGHT_distance = 50;
		 NUI_SKELETON_POSITION_ANKLE_RIGHT_distance = 40;
		 NUI_SKELETON_POSITION_FOOT_RIGHT_distance = 50;

	mParams = params::InterfaceGl( "Parameters", ci::Vec2i( 200, 500 ) );
	mParams.addSeparator();
	mParams.addText( "ATTRACTOR FORCE" );
	mParams.addParam( "HIP_CENTER_force",			&NUI_SKELETON_POSITION_HIP_CENTER_force, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "SPINE_force",				&NUI_SKELETON_POSITION_SPINE_force, 										"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "SHOULDER_CENTER_force",		&NUI_SKELETON_POSITION_SHOULDER_CENTER_force, 								"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "HEAD_force",					&NUI_SKELETON_POSITION_HEAD_force, 											"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "SHOULDER_LEFT_force",		&NUI_SKELETON_POSITION_SHOULDER_LEFT_force, 								"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "ELBOW_LEFT_force",			&NUI_SKELETON_POSITION_ELBOW_LEFT_force, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "WRIST_LEFT_force",			&NUI_SKELETON_POSITION_WRIST_LEFT_force, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "HAND_LEFT_force",			&NUI_SKELETON_POSITION_HAND_LEFT_force, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "SHOULDER_RIGHT_force",		&NUI_SKELETON_POSITION_SHOULDER_RIGHT_force, 								"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "ELBOW_RIGHT_force",			&NUI_SKELETON_POSITION_ELBOW_RIGHT_force, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "WRIST_RIGHT_force",			&NUI_SKELETON_POSITION_WRIST_RIGHT_force, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "HAND_RIGHT_force",			&NUI_SKELETON_POSITION_HAND_RIGHT_force, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "HIP_LEFT_force",				&NUI_SKELETON_POSITION_HIP_LEFT_force, 										"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "KNEE_LEFT_force",			&NUI_SKELETON_POSITION_KNEE_LEFT_force, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "ANKLE_LEFT_force",			&NUI_SKELETON_POSITION_ANKLE_LEFT_force, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "FOOT_LEFT_force",			&NUI_SKELETON_POSITION_FOOT_LEFT_force, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "HIP_RIGHT_force",			&NUI_SKELETON_POSITION_HIP_RIGHT_force, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "KNEE_RIGHT_force",			&NUI_SKELETON_POSITION_KNEE_RIGHT_force, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "ANKLE_RIGHT_force",			&NUI_SKELETON_POSITION_ANKLE_RIGHT_force, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "FOOT_RIGHT_force",			&NUI_SKELETON_POSITION_FOOT_RIGHT_force, 									"min=0.0 max=2000.0 step=5.0", false);

	
	mParams.addSeparator();
	mParams.addText( "ATTRACTOR DISTANCE" );

	mParams.addParam( "HIP_CENTER_distance",			&NUI_SKELETON_POSITION_HIP_CENTER_distance, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "SPINE_distance",			&NUI_SKELETON_POSITION_SPINE_distance, 													"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "SHOULDER_CENTER_distance",			&NUI_SKELETON_POSITION_SHOULDER_CENTER_distance, 							"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "HEAD_distance",			&NUI_SKELETON_POSITION_HEAD_distance, 													"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "SHOULDER_LEFT_distance",			&NUI_SKELETON_POSITION_SHOULDER_LEFT_distance, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "ELBOW_LEFT_distance",			&NUI_SKELETON_POSITION_ELBOW_LEFT_distance, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "WRIST_LEFT_distance",			&NUI_SKELETON_POSITION_WRIST_LEFT_distance, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "HAND_LEFT_distance",			&NUI_SKELETON_POSITION_HAND_LEFT_distance, 											"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "SHOULDER_RIGHT_distance",			&NUI_SKELETON_POSITION_SHOULDER_RIGHT_distance, 							"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "ELBOW_RIGHT_distance",			&NUI_SKELETON_POSITION_ELBOW_RIGHT_distance, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "WRIST_RIGHT_distance",			&NUI_SKELETON_POSITION_WRIST_RIGHT_distance, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "HAND_RIGHT_distance",			&NUI_SKELETON_POSITION_HAND_RIGHT_distance, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "HIP_LEFT_distance",			&NUI_SKELETON_POSITION_HIP_LEFT_distance, 											"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "KNEE_LEFT_distance",			&NUI_SKELETON_POSITION_KNEE_LEFT_distance, 											"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "ANKLE_LEFT_distance",			&NUI_SKELETON_POSITION_ANKLE_LEFT_distance, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "FOOT_LEFT_distance",			&NUI_SKELETON_POSITION_FOOT_LEFT_distance, 											"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "HIP_RIGHT_distance",			&NUI_SKELETON_POSITION_HIP_RIGHT_distance, 											"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "KNEE_RIGHT_distance",			&NUI_SKELETON_POSITION_KNEE_RIGHT_distance, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "ANKLE_RIGHT_distance",			&NUI_SKELETON_POSITION_ANKLE_RIGHT_distance, 									"min=0.0 max=2000.0 step=5.0", false);
	mParams.addParam( "FOOT_RIGHT_distance",			&NUI_SKELETON_POSITION_FOOT_RIGHT_distance, 									"min=0.0 max=2000.0 step=5.0", false);


	mParams.addParam( "SHOW FORCES",			&showForces,"", false);

}

void OutlineParams::draw(){
	params::InterfaceGl::draw();
}

float OutlineParams::getForceForIndex(int index)
{
	float force = 50;//default to 50
	switch(index)
	{
		case NUI_SKELETON_POSITION_HIP_CENTER:
			//draw hip center
			force = NUI_SKELETON_POSITION_HIP_CENTER_force;
			break;
					 
		case NUI_SKELETON_POSITION_SPINE:
			//draw spine
			force = NUI_SKELETON_POSITION_SPINE_force;
			break;
		case NUI_SKELETON_POSITION_SHOULDER_CENTER:
			//draw shoulder center
			force = NUI_SKELETON_POSITION_SHOULDER_CENTER_force;
			break;
		case NUI_SKELETON_POSITION_HEAD:
			//draw head
			force = NUI_SKELETON_POSITION_HEAD_force;
			break;
		case NUI_SKELETON_POSITION_SHOULDER_LEFT:
			//draw left shoulder
			force = NUI_SKELETON_POSITION_SHOULDER_LEFT_force;
			break;		 
		case NUI_SKELETON_POSITION_ELBOW_LEFT:
			//draw left elbow
			force = NUI_SKELETON_POSITION_ELBOW_LEFT_force;
			break;				 
		case NUI_SKELETON_POSITION_WRIST_LEFT:
			//draw left wrist
			force = NUI_SKELETON_POSITION_WRIST_LEFT_force;
			break;				 
		case NUI_SKELETON_POSITION_HAND_LEFT:
			//draw left hand
			force = NUI_SKELETON_POSITION_HAND_LEFT_force;
			break;				 
		case NUI_SKELETON_POSITION_SHOULDER_RIGHT:
			//draw right shoulder
			force = NUI_SKELETON_POSITION_SHOULDER_RIGHT_force;
			break;				 
		case NUI_SKELETON_POSITION_ELBOW_RIGHT:
			//draw right elbow
			force = NUI_SKELETON_POSITION_ELBOW_RIGHT_force;
			break;				 
		case NUI_SKELETON_POSITION_WRIST_RIGHT:
			//draw right wrist
			force = NUI_SKELETON_POSITION_WRIST_RIGHT_force;
			break;				 
		case NUI_SKELETON_POSITION_HAND_RIGHT:
			//draw right hand
			force = NUI_SKELETON_POSITION_HAND_RIGHT_force;
			break;
		case NUI_SKELETON_POSITION_HIP_LEFT:
			//draw left hip
			force = NUI_SKELETON_POSITION_HIP_LEFT_force;
			break;
		case NUI_SKELETON_POSITION_KNEE_LEFT:
			//draw left knee
			force = NUI_SKELETON_POSITION_KNEE_LEFT_force;
			break;				 
		case NUI_SKELETON_POSITION_ANKLE_LEFT:
			//draw left ankle
			force = NUI_SKELETON_POSITION_ANKLE_LEFT_force;
			break;
		case NUI_SKELETON_POSITION_FOOT_LEFT:
			//draw left foot
			force = NUI_SKELETON_POSITION_FOOT_LEFT_force;
			break;
		case NUI_SKELETON_POSITION_HIP_RIGHT:
			//draw right hip
			force = NUI_SKELETON_POSITION_HIP_RIGHT_force;
			break;
		case NUI_SKELETON_POSITION_KNEE_RIGHT:
			//draw right knee
			force = NUI_SKELETON_POSITION_KNEE_RIGHT_force;
			break;
		case NUI_SKELETON_POSITION_ANKLE_RIGHT:
			//draw right ankle
			force = NUI_SKELETON_POSITION_ANKLE_RIGHT_force;
			break;
		case NUI_SKELETON_POSITION_FOOT_RIGHT:
			//draw right foot
			force = NUI_SKELETON_POSITION_FOOT_RIGHT_force;
			break;
		default:
			force = 100.0;
		}
	
	return force;
}

float OutlineParams::getMinDistForIndex(int index)
{
	float minDist = 50;//default to 50
	switch(index)
	{
		case NUI_SKELETON_POSITION_HIP_CENTER:
			//draw hip center
			minDist =  NUI_SKELETON_POSITION_HIP_CENTER_distance;
			break;
		case NUI_SKELETON_POSITION_SPINE:
			//draw spine
			minDist =  NUI_SKELETON_POSITION_SPINE_distance;
			break;
		case NUI_SKELETON_POSITION_SHOULDER_CENTER:
			//draw shoulder center
			minDist =  NUI_SKELETON_POSITION_SHOULDER_CENTER_distance;
			break;
		case NUI_SKELETON_POSITION_HEAD:
			//draw head
			minDist =  NUI_SKELETON_POSITION_HEAD_distance;
			break;
		case NUI_SKELETON_POSITION_SHOULDER_LEFT:
			//draw left shoulder
			minDist =  NUI_SKELETON_POSITION_SHOULDER_LEFT_distance;
			break;		 
		case NUI_SKELETON_POSITION_ELBOW_LEFT:
			//draw left elbow
			minDist =  NUI_SKELETON_POSITION_ELBOW_LEFT_distance;
			break;				 
		case NUI_SKELETON_POSITION_WRIST_LEFT:
			//draw left wrist
			minDist =  NUI_SKELETON_POSITION_WRIST_LEFT_distance;
			break;				 
		case NUI_SKELETON_POSITION_HAND_LEFT:
			//draw left hand
			minDist =  NUI_SKELETON_POSITION_HAND_LEFT_distance;
			break;				 
		case NUI_SKELETON_POSITION_SHOULDER_RIGHT:
			//draw right shoulder
			minDist =  NUI_SKELETON_POSITION_SHOULDER_RIGHT_distance;
			break;				 
		case NUI_SKELETON_POSITION_ELBOW_RIGHT:
			//draw right elbow
			minDist =  NUI_SKELETON_POSITION_ELBOW_RIGHT_distance;
			break;				 
		case NUI_SKELETON_POSITION_WRIST_RIGHT:
			//draw right wrist
			minDist =  NUI_SKELETON_POSITION_WRIST_RIGHT_distance;
			break;				 
		case NUI_SKELETON_POSITION_HAND_RIGHT:
			//draw right hand
			minDist =  NUI_SKELETON_POSITION_HAND_RIGHT_distance;
			break;
		case NUI_SKELETON_POSITION_HIP_LEFT:
			//draw left hip
			minDist =  NUI_SKELETON_POSITION_HIP_LEFT_distance;
			break;
		case NUI_SKELETON_POSITION_KNEE_LEFT:
			//draw left knee
			minDist =  NUI_SKELETON_POSITION_KNEE_LEFT_distance;
			break;				 
		case NUI_SKELETON_POSITION_ANKLE_LEFT:
			//draw left ankle
			minDist =  NUI_SKELETON_POSITION_ANKLE_LEFT_distance;
			break;
		case NUI_SKELETON_POSITION_FOOT_LEFT:
			//draw left foot
			minDist =  NUI_SKELETON_POSITION_FOOT_LEFT_distance;
			break;
		case NUI_SKELETON_POSITION_HIP_RIGHT:
			//draw right hip
			minDist =  NUI_SKELETON_POSITION_HIP_RIGHT_distance;
			break;
		case NUI_SKELETON_POSITION_KNEE_RIGHT:
			//draw right knee
			minDist =  NUI_SKELETON_POSITION_KNEE_RIGHT_distance;
			break;
		case NUI_SKELETON_POSITION_ANKLE_RIGHT:
			//draw right ankle
			minDist =  NUI_SKELETON_POSITION_ANKLE_RIGHT_distance;
			break;
		case NUI_SKELETON_POSITION_FOOT_RIGHT:
			//draw right foot
			minDist =  NUI_SKELETON_POSITION_FOOT_RIGHT_distance;
			break;
		default:
			minDist = 100;
		}
	return minDist;
}