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
	arrow.xPos = ci::app::getWindowWidth() + 100;
	arrow.yPos = 600;
	
	arrow.xScale = arrow.yScale = 1;
	

	

	animationTimer.start();


	phase = 0;
}

void PassiveScene5::update()
{
	if(animationTimer.getSeconds()>5 && phase == 0){
		phase = 1;
		font->animateIn();
	}

	if(animationTimer.getSeconds()>20 && phase == 1){
		phase = 2;
		// test dispatching event
		//_signal( this );
		font->animateOut();
		//font->clear();
		//font->addLine( "end scene 3", 3 );
	}
	if(animationTimer.getSeconds()>25 && phase ==2){
		phase = 3;
		animationTimer.stop();
		animationTimer = Timer(); // reset the timer
		
		_signal( this );
	}
}


void PassiveScene5::animateIn(ci::Timeline &timeline){
	font->animateIn();
	arrow.tweenTo(timeline,-100.0,600.0,10.0);
}

void PassiveScene5::animateOut(ci::Timeline &timeline){
	font->animateOut();
	arrow.tweenTo(timeline,-100.0,600.0,10.0);
}


void PassiveScene5::draw()
{
	//font.draw(); // THINK THIS IS DONE BY BASE CLASS ANYWAYS

		airGuitar.draw();
		arrow.draw();
}