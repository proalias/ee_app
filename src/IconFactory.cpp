#include "IconFactory.h"

using namespace std;
using namespace cinder;


void IconFactory::init(){
	svgParser = SVGtoParticleParser();

	// no need to instantiate right?

	//icons[LOCATION_PIN] = std::vector<TweenParticle>();
	//icons[ARROW] = std::vector<TweenParticle>();

	//icons[WAVE] = std::vector<TweenParticle>();
	//icons[HAND] = std::vector<TweenParticle>();
	//icons[AIR_GUITAR] = std::vector<TweenParticle>();
	//icons[SPEED_DIAL] = std::vector<TweenParticle>();


	
	cinder::XmlTree xmlDoc0( ci::app::loadAsset( "hand.svg" ) );
	svgParser.recursiveParse(xmlDoc0,icons[HAND]);

	cinder::XmlTree xmlDoc1( ci::app::loadAsset( "airguitar.svg" ) );
	svgParser.recursiveParse(xmlDoc1,icons[AIR_GUITAR]);
	
	cinder::XmlTree xmlDoc2( ci::app::loadAsset( "superfast-swoosh.svg" ) );
	svgParser.recursiveParse(xmlDoc2,icons[SWOOSH]);
	
	cinder::XmlTree xmlDoc3( ci::app::loadAsset( "superfast-dial.svg" ) );
	svgParser.recursiveParse(xmlDoc3,icons[DIAL]);
}

std::vector<TweenParticle> IconFactory::getPointsForIcon(int iconConstant){
	return icons[iconConstant];
}