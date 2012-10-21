#ifndef PassiveScene3_H_
#define PassiveScene3_H_

#include "FontRenderer.h"
#include "SceneBase.h"

using namespace std;
using namespace ci;

class PassiveScene3: public SceneBase {
 
public:

	// inherited and overridden
	void setup( FontRenderer &thefont, IconFactory &theIconFactory );
	void update(ci::Timeline &timeline);
	void draw();

	PassiveScene3(void);
	//~PassiveScene2(void);

 private:
	Timer animationTimer;

	void animateIn();
	void animateOut();
	int phase;
};

#endif /* PASSIVESCENE3_H_ */