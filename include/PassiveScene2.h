#ifndef PassiveScene2_H_
#define PassiveScene2_H_

#include "SceneBase.h"

using namespace std;
using namespace ci;

class PassiveScene2: public SceneBase {
 
public:

	// inherited and overridden
	void setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles, std::vector<ParticleA> &thegridLayer1 );
	void update();
	void draw();

	PassiveScene2(void);
	//~PassiveScene2(void);

 private:

	std::vector<IconRenderer*> placeMarks;
	IconRenderer placeMark1, placeMark2, placeMark3, placeMark4, placeMark5, placeMark6;

	CueRef mCue;
	// keyframes
	void showFrame2();
	void showFrame3();
	void showFrame4();
	void showFrame5();
	void showFrame6();
	void showFrame7();
	void showFrame8();

};

#endif /* PASSIVESCENE2_H_ */