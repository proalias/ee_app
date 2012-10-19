#include "IconFactory.h"

using namespace std;
using namespace cinder;


void IconFactory::init(){
	svgParser = SVGtoParticleParser();

	icons[ICON_FACTORY_WAVE] = std::vector<TweenParticle>();
	icons[ICON_FACTORY_HAND] = std::vector<TweenParticle>();
	icons[ICON_FACTORY_AIR_GUITAR] = std::vector<TweenParticle>();
	icons[ICON_FACTORY_SPEED_DIAL] = std::vector<TweenParticle>();


	
	cinder::XmlTree xmlDoc0( ci::app::loadAsset( "hand.svg" ) );
	svgParser.recursiveParse(xmlDoc0,icons[ICON_FACTORY_WAVE]);
	cinder::XmlTree xmlDoc1( ci::app::loadAsset( "airguitar.svg" ) );
	svgParser.recursiveParse(xmlDoc1,icons[ICON_FACTORY_AIR_GUITAR]);
	
	cinder::XmlTree xmlDoc2( ci::app::loadAsset( "superfast-swoosh.svg" ) );
	svgParser.recursiveParse(xmlDoc2,icons[ICON_FACTORY_SPEED_DIAL]);
	
	cinder::XmlTree xmlDoc3( ci::app::loadAsset( "superfast-dial.svg" ) );
	svgParser.recursiveParse(xmlDoc3,icons[ICON_FACTORY_SPEED_DIAL]);
}

std::vector<TweenParticle> IconFactory::getPointsForIcon(int iconConstant){
	return icons[iconConstant];
}