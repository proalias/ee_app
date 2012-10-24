#ifndef ActiveScene1_H_
#define ActiveScene1_H_

#include "FontRenderer.h"
#include "SceneBase.h"
#include "cinder/Timeline.h"

using namespace std;
using namespace ci;

class ActiveScene1: public SceneBase {
 
public:

	// inherited and overridden
	void setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles, std::vector<ParticleA> &thegridLayer1 );
	void update();
	void draw();

	ActiveScene1(void);
	//~ActiveScene1(void);

 private:
	CueRef mCue;
	// keyframes
	void showFrame2();
	void showFrame3();

	bool showHand;

	IconRenderer hand;
};

#endif /* ActiveScene1_H_ */