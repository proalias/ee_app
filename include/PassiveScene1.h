#ifndef PassiveScene1_H_
#define PassiveScene1_H_

#include "FontRenderer.h"
#include "SceneBase.h"

using namespace std;
using namespace ci;

class PassiveScene1: public SceneBase {
 
public:

	// inherited and overridden
	void setup( FontRenderer &thefont, IconFactory &theIconFactory);
	void update();
	void draw();

	PassiveScene1(void);
	//~PassiveScene1(void);

 private:
	Timer animationTimer;

	void animateIn();
	void animateOut();

};

#endif /* PASSIVESCENE1_H_ */