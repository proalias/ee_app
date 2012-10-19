#include "SVGtoParticleParser.h"
#include "cinder/Cinder.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Vector.h"
#include "Particle.h"

#include <stdio.h>
#include <stdarg.h>
#include <map>

class IconFactory{
public:
	std::vector<TweenParticle> getPointsForIcon(int iconConstant);
	void init();

	static const int HAND = 0;
	static const int AIR_GUITAR = 1;
	static const int SWOOSH = 2;
	static const int DIAL = 3;

	// TODO - these are missing ones
	static const int LOCATION_PIN = 4;// TODO - can not be strings for debugging?
	static const int ARROW = 5;
	static const int BUTTON = 6;
	static const int ROCKET = 7;

private:
	SVGtoParticleParser svgParser;
	std::map<int, std::vector<TweenParticle>> icons;

};