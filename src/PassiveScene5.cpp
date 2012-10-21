#include "PassiveScene5.h"

PassiveScene5::PassiveScene5()
{
	_id = "PassiveScene5"; // for boost signal
}

void PassiveScene5::setup( FontRenderer &thefont, IconFactory &theIconFactory)
{
	font = &thefont;
	font->clear();
	font->addLine( "WELCOME TO", 2 );
	font->addLine( "THE NEW NETWORK", 2 );
	font->addLine( "          FOR YOUR", 2 );
	font->addLine( "          DIGITAL LIFE", 2 );

	iconFactory =  &theIconFactory;

	airGuitar = IconRenderer();
	airGuitar.setPoints(iconFactory->getPointsForIcon(IconFactory::AIR_GUITAR));
	airGuitar.xPos = 400;
	airGuitar.yPos = 300;
	airGuitar.xScale = airGuitar.yScale = 0.5;

	arrow = IconRenderer();
	arrow.setPoints(iconFactory->getPointsForIcon(IconFactory::ARROW) );
	arrow.xPos = 400;
	arrow.yPos = 600;
	
	arrow.xScale = arrow.yScale = 0.5;

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
	airGuitar.tweenTo(timeline,100.0,600.0,10.0);
}

void PassiveScene5::animateOut(ci::Timeline &timeline){
	font->animateOut();
	airGuitar.tweenTo(timeline,30.0,30.0,10.0);
}

void PassiveScene5::draw()
{
	//font.draw(); // THINK THIS IS DONE BY BASE CLASS ANYWAYS

	airGuitar.draw();
	arrow.draw();
}