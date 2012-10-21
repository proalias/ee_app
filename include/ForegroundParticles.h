#pragma once

#include "cinder/Cinder.h"
#include "cinder/Vector.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/Texture.h"

#include "ParticleA.h"
#include "CinderClip.h"

#include <list>

using namespace ci;
using namespace ci::app;
using namespace std;

using std::list;

class ForegroundParticles {
public:

	void setup();
	void update();
	void draw();
	
	std::list<ParticleA>	mParticles;

	// gl::Texture bgImage; // = TODO potentially have textures on them
	
	// TODO - you can pass in clips that you want to effect our particles. skeleton ones
	std::vector<CinderClip> repelClips;
	void setRepelClips( std::vector<CinderClip> &rclips );

	ForegroundParticles(void);
};