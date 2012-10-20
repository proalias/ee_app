#include "PassiveScene5.h"
#include "boost/bind.hpp"

PassiveScene5::PassiveScene5()
{
	_id = "PassiveScene5"; // for boost signal
}

void PassiveScene5::setup( FontRenderer &thefont, ci::Timeline &timeline, IconFactory &iconFactory)
{

	font = &thefont;
	font->clear();
	font->addLine( "WELCOME TO", 2 );
	font->addLine( "THE NEW NETWORK", 2 );
	font->addLine( "          FOR YOUR", 2 );
	font->addLine( "          DIGITAL LIFE", 2 );

	std::vector<TweenParticle> airGuitarPoints = iconFactory.getPointsForIcon(IconFactory::AIR_GUITAR);
	IconRenderer airGuitarRenderer = IconRenderer(airGuitarPoints);
	airGuitarRenderer.xPos = 400;
	airGuitarRenderer.yPos = 300;
	airGuitarRenderer.xScale = airGuitarRenderer.yScale = 0.5;

	icons.push_back(airGuitarRenderer);

	animationTimer.start();


	
}

void PassiveScene5::update()
{
	if(animationTimer.getSeconds()>10){
		// test dispatching event
		animationTimer.stop();
		animationTimer = Timer(); // reset the timer
		_signal( this );
	}
}


void PassiveScene5::animateIn(ci::Timeline &timeline){
	font->animateIn();
	icons.back().tweenTo(timeline,1000.0,1000.0,10.0);
}

void PassiveScene5::animateOut(ci::Timeline &timeline){
	font->animateOut();
	icons.back().tweenTo(timeline,30.0,30.0,10.0);
}


void PassiveScene5::draw()
{
	//font.draw(); // THINK THIS IS DONE BY BASE CLASS ANYWAYS

	for (std::vector<IconRenderer>::iterator icon = icons.begin(); icon < icons.end(); icon++){
	
		icon->draw();
	}
}