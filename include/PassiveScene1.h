#ifndef PassiveScene1_H_
#define PassiveScene1_H_

#include "FontRenderer.h"
//#include "cinder/Vector.h"
//#include <vector>

#include "cinder/Cinder.h"
#include <boost/signals2.hpp>
#include <iostream>

using namespace std;
using namespace ci;

class PassiveScene1 {
 public:

	void setup( FontRenderer &font );
	void update();
	void draw();

	void animateIn();
	void animateOut();
	
	//std::vector<Vec2f> refToParticlesMaybe?;

	FontRenderer * font; // just a pointer to the one on the stage
	
	PassiveScene1(void);
	//~PassiveScene1(void);

	// this typedef creates a simple shorthand, so that ButtonSignal refers to boost::signals2::signal<void( Button* )>
	// If you wanted you could use the long name instead, but its easier to typo
	typedef boost::signals2::signal<void( PassiveScene1* )> PassiveSignal;

	// ACCESSORS
	std::string getId() { return _id; };
	PassiveSignal* getSignal() { return &_signal; }; // Notice we return a pointer to the signal

 private:
	std::string _id;
	PassiveSignal    _signal;

	Timer animationTimer;

};

#endif /* PASSIVESCENE1_H_ */