#ifndef ActiveScene1_H_
#define ActiveScene1_H_

#include "FontRenderer.h"
#include "SceneBase.h"

#include "cinder/Timeline.h"
#include "boost/bind.hpp"

#include "TextureGlobals.h"
#include "GestureTracker.h"

class ActiveScene1: public SceneBase {


public:

	// inherited and overridden
	void setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles, std::vector<ParticleA> &thegridLayer1 );
	void update();
	void draw();

	ActiveScene1(void);
	//~ActiveScene1(void);

 private:
	ci::CueRef mCue;
	// keyframes
	void showFrame2();
	void showFrame3();
	void showFrame4();

	bool showHand;

	
	
	IconRenderer hand;
};

#endif /* ActiveScene1_H_ */