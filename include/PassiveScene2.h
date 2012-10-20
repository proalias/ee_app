#ifndef PassiveScene2_H_
#define PassiveScene2_H_

#include "FontRenderer.h"
#include "SceneBase.h"

using namespace std;
using namespace ci;

class PassiveScene2: public SceneBase {
 
public:

	// inherited and overridden
	void setup( FontRenderer &font );
	void update();
	void draw();

	void animateIn();
	void animateOut();

	PassiveScene2(void);
	//~PassiveScene2(void);

 private:
	Timer animationTimer;

};

#endif /* PASSIVESCENE2_H_ */