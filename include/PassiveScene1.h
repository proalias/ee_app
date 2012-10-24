#ifndef PassiveScene1_H_
#define PassiveScene1_H_

#include "FontRenderer.h"
#include "SceneBase.h"
#include "cinder/Timeline.h"

using namespace std;
using namespace ci;

class PassiveScene1: public SceneBase {
 
public:

	// inherited and overridden
	void setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles, std::vector<ParticleA> &thegridLayer1 );
	void update();
	void draw();

	PassiveScene1(void);
	//~PassiveScene1(void);

 private:
	CueRef mCue;
	// keyframes
	void showFrame2();
	void showFrame3();
	void showFrame4();
};

#endif /* PASSIVESCENE1_H_ */