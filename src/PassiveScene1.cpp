#include "PassiveScene1.h"
#include "boost/bind.hpp"

PassiveScene1::PassiveScene1()
{
	_id = "PassiveScene1"; // for boost signal
}

void PassiveScene1::setup( FontRenderer &thefont )
{
	font = &thefont;
	font->clear();
	font->addLine( "WELCOME TO", 2 );
	font->addLine( "THE NEW NETWORK", 2 );
	font->addLine( "          FOR YOUR", 2 );
	font->addLine( "          DIGITAL LIFE", 2 );

	//font->animateIn(); // TODO - animate in is broken

	//_signal( this );

	animationTimer.start();
	
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
	//font.draw(); // THINK THIS IS DONE BY BASE CLASS ANYWAYS
}