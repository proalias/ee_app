#ifndef PassiveScene4_H_
#define PassiveScene4_H_

#include "FontRenderer.h"
#include "SceneBase.h"

using namespace std;
using namespace ci;

class PassiveScene4: public SceneBase {
 
public:

	// inherited and overridden
	void setup( FontRenderer &font );
	void update();
	void draw();

	PassiveScene4(void);
	//~PassiveScene4(void);

 private:
	Timer animationTimer;

	void animateIn();
	void animateOut();

};

#endif /* PASSIVESCENE4_H_ */