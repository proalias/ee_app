#ifndef PassiveScene2_H_
#define PassiveScene2_H_

#include "SceneBase.h"

using namespace std;
using namespace ci;

class PassiveScene2: public SceneBase {
 
public:

	// inherited and overridden
	void setup( FontRenderer &thefont, IconFactory &theIconFactory);
	void update(ci::Timeline &timeline);
	void draw();

	PassiveScene2(void);
	//~PassiveScene2(void);

 private:

	std::vector<IconRenderer*> placeMarks;
	IconRenderer placeMark1, placeMark2, placeMark3, placeMark4;
	Timer animationTimer;
	FontRenderer locationLabel;
	void animateIn();
	void animateOut();

};

#endif /* PASSIVESCENE2_H_ */