#ifndef PassiveScene4_H_
#define PassiveScene4_H_

#include "FontRenderer.h"
#include "SceneBase.h"
#include "ShopConfig.h"


using namespace std;
using namespace ci;

class PassiveScene4: public SceneBase {
 
public:

	// inherited and overridden
	void setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles,std::vector<ParticleA> &thegridLayer1 );
	void update();
	void draw();

	PassiveScene4(void);
	//~PassiveScene4(void);

 private:

	IconRenderer arrow1, arrow2, arrow3, arrow4, arrow5;

	std::vector<IconRenderer*> arrows;

	CueRef mCue;
	// keyframes
	void showFrame2();
	void showFrame3();
	void showFrame4();

};

#endif /* PASSIVESCENE4_H_ */