#pragma once

#include "cinder/Cinder.h"
#include "cinder/Vector.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/Texture.h"

#include "Kinect.h"

#include "ParticleA.h"
#include "CinderClip.h"

//#include "FireFlyEffect.h"


#include <list>

using namespace ci;
using namespace ci::app;
using namespace std;

using std::list;

class Background{
public:

	void setup();
	void update();
	void draw();
	
	gl::Texture bgImage;
	gl::Texture* particleTexture;
	
	std::vector<ParticleA>	gridLayer1;
	std::vector<ParticleA>	gridLayer2;
	std::vector<ParticleA>	gridLayer3;

	void drawGrid( std::vector<ParticleA> &fieldLayerContainer, int, float );

	// TODO - maybe force these in the constuctor?
	std::vector<CinderClip> * repelClips;
	void setRepelClips( std::vector<CinderClip> &rclips );

	float Background::getForceForIndex(int index);
	float Background::getMinDistForIndex(int index);

	Background(void);

	//FireFlyEffect ff;
};