#include "PassiveScene1.h"
#include "boost/bind.hpp"

PassiveScene1::PassiveScene1()
{
	_id = "PassiveScene1"; // for boost signal
}

void PassiveScene1::setup( FontRenderer &thefont, IconFactory &theIconFactory )
{
	font = &thefont;
	font->clear();
	font->addLine( "WELCOME TO", 2 );
	font->addLine( "THE NEW NETWORK", 2 );
	font->addLine( "          FOR YOUR", 2 );
	font->addLine( "          DIGITAL LIFE", 2 );

	iconFactory =  &theIconFactory;

	animateIn(); // TODO - animate in is broken

	//_signal( this );

	//animationTimer.start();
	
	mCue = timeline().add( bind(&PassiveScene1::showFrame2, this), timeline().getCurrentTime() + 5 );
	// http://www.thegrego.com/2012/09/02/flash-to-cinder-timed-event-loops/
}

void PassiveScene1::showFrame2()
{
	font->addLine( "timer works", 2 );
}


void PassiveScene1::update()
{
	if(animationTimer.getSeconds()>15 && animationTimer.getSeconds()>16 ){
		// test dispatching event
		animationTimer.stop();
		animateOut();
		animationTimer = Timer(); // reset the timer
		_signal( this );
	}
}


void PassiveScene1::animateIn(){
	font->animateIn();
}

void PassiveScene1::animateOut(){
	font->animateOut();
}

void PassiveScene1::draw()
{
	font->draw(); // THINK THIS IS DONE BY BASE CLASS ANYWAYS
}