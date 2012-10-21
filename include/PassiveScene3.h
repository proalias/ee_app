#ifndef PassiveScene3_H_
#define PassiveScene3_H_

#include "FontRenderer.h"
#include "SceneBase.h"

using namespace std;
using namespace ci;

class PassiveScene3: public SceneBase {
 
public:

	// inherited and overridden
	void setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles );
	void update();
	void draw();

	PassiveScene3(void);
	//~PassiveScene2(void);

 private:
	private:
	CueRef mCue;
	// keyframes
	void showFrame2();
	void showFrame3();
	void showFrame4();
	void showFrame5();
};

#endif /* PASSIVESCENE3_H_ */