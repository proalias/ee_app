#ifndef PassiveScene5_H_
#define PassiveScene5_H_

#include "FontRenderer.h"
#include "IconFactory.h"
#include "IconRenderer.h"


#include "cinder/Cinder.h"
#include "cinder/Timeline.h"


#include <boost/signals2.hpp>
#include <iostream>

using namespace std;
using namespace ci;

class PassiveScene5 {
 public:

	void setup( FontRenderer &font, Timeline &timeline, IconFactory &iconFactory );
	void update();
	void draw();

	void animateIn(ci::Timeline &timeline);
	void animateOut(ci::Timeline &timeline);
	
	//std::vector<Vec2f> refToParticlesMaybe?;

	FontRenderer * font; // just a pointer to the one on the stage
	
	PassiveScene5(void);
	//~PassiveScene5(void);

	// this typedef creates a simple shorthand, so that ButtonSignal refers to boost::signals2::signal<void( Button* )>
	// If you wanted you could use the long name instead, but its easier to typo
	typedef boost::signals2::signal<void( PassiveScene5* )> PassiveSignal;

	// ACCESSORS
	std::string getId() { return _id; };
	PassiveSignal* getSignal() { return &_signal; }; // Notice we return a pointer to the signal

	IconFactory iconFactory;

	std::vector<IconRenderer> icons;

 private:
	std::string _id;
	PassiveSignal    _signal;

	Timer animationTimer;



};

#endif /* PassiveScene5_H_ */