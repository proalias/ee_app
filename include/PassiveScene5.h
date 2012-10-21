#ifndef PassiveScene5_H_
#define PassiveScene5_H_

#include "SceneBase.h"

using namespace std;
using namespace ci;

class PassiveScene5: public SceneBase {
 
public:

	// inherited and overridden
	void setup( FontRenderer &thefont, IconFactory &theIconFactory);
	void update();
	void draw();

	PassiveScene5(void);
	//~PassiveScene4(void);

	
	std::map<string,IconRenderer> icons;

	//icon renderers
	IconRenderer airGuitar;
	IconRenderer arrow;



 private:
	Timer animationTimer;

	void animateIn(ci::Timeline &timeline);
	void animateOut(ci::Timeline &timeline);

};

#endif /* PASSIVESCENE4_H_ */