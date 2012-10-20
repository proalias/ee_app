#ifndef PassiveScene1_H_
#define PassiveScene1_H_

#include "FontRenderer.h"
#include "SceneBase.h"

using namespace std;
using namespace ci;

class PassiveScene1: public SceneBase {
 
public:

	// inherited and overridden
	void setup( FontRenderer &font );
	void update();
	void draw();

	void animateIn();
	void animateOut();

	PassiveScene1(void);
	//~PassiveScene1(void);

 private:
	Timer animationTimer;

};

#endif /* PASSIVESCENE1_H_ */