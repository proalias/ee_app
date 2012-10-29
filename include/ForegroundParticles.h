#pragma once

#include "cinder/Cinder.h"
#include "cinder/Vector.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/Texture.h"

#include "ParticleA.h"
#include "CinderClip.h"

#include "cinder/app/AppBasic.h"
#include "cinder/Timeline.h"

#include <list>

using namespace ci;
using namespace ci::app;
using namespace std;

using std::list;

class ForegroundParticles {
public:

	void setup( int howMany );
	void update();
	void draw();
	
	//void init();

	//void destroy(); // destroy all the particles
	void hide(); // make them all invisible
	void show(); // make them all invisible

	
	std::list<ParticleA> mParticles; // TODO - getter?... really be fine to just get the whole array and change behaviours from scenes.

	// gl::Texture bgImage; // = TODO potentially have textures on them
	
	// TODO - you can pass in clips that you want to effect our particles. skeleton ones
	std::vector<CinderClip> * repelClips;
	void setRepelClips( std::vector<CinderClip> &rclips );


	//TimelineRef mTimeline;

	// if this is set then the scene is reponsible for the draw method
	//YOU MUST CANCEL THIS AT THE END OF THE SCENE
	bool overrideDrawMethodInScene;

	float particlesAlpha; // so we can hide them




	ForegroundParticles(void);
};