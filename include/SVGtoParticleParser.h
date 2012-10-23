#ifndef SVGtoParticleParser_h
#define SVGtoParticleParser_h

#include "cinder/Xml.h"
#include "TweenParticle.h"


#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

#include <stdio.h>
#include <string.h>
#include <vector>

using namespace cinder;
using namespace std;

class SVGtoParticleParser{
	public:

	void recursiveParse(cinder::XmlTree node, std::vector<TweenParticle> &pointsContainer);
};
#endif