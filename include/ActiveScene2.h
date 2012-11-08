#ifndef ActiveScene2_H_
#define ActiveScene2_H_

#include "FontRenderer.h"
#include "SceneBase.h"

#include "cinder/Timeline.h"
#include "boost/bind.hpp"

#include "TextureGlobals.h"
#include "GestureTracker.h"


#include "cinder/gl/Texture.h"
#include "cinder/Easing.h"

class ActiveScene2: public SceneBase {


public:

	// inherited and overridden
	void setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles, std::vector<ParticleA> &thegridLayer1 );
	void update();
	void draw();
	void exitNow();
		
	ActiveScene2(void);
	//~ActiveScene2(void);
	

 private:

	
	cinder::gl::Texture					mFrameTexture, mInfoTexture;
	SpriteSheet* bubbleManRun;

	cinder::CueRef mCue;
	
	// keyframes
	void showFrame2();
	void showFrame3();
	void showFrame4();
	void showFrame5();

	bool showSuperfast;

	float runningSpeed;
	
	IconRenderer speedDialSwoosh;
	IconRenderer speedDialNeedle;
};

#endif /* ActiveScene2_H_ */