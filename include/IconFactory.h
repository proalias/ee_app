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

	static const int ICON_FACTORY_WAVE = 0;
	static const int ICON_FACTORY_HAND = 1;
	static const int ICON_FACTORY_AIR_GUITAR = 2;
	static const int ICON_FACTORY_SPEED_DIAL = 3;

private:
	SVGtoParticleParser svgParser;
	std::map<int, std::vector<TweenParticle>> icons;

};