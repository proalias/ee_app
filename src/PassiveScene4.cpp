#include "PassiveScene4.h"
#include "boost/bind.hpp"

PassiveScene4::PassiveScene4()
{
	_id = "PassiveScene4"; // for boost signal
}

void PassiveScene4::setup( FontRenderer &thefont, IconFactory &theIconFactory )
{
	font = &thefont;
	font->clear();
	font->addLine( " ", 3 );
	font->addLine( "COME IN", 3 );
	font->addLine( "      AND SEE US", 3 );

//	font->animateIn();

	
	iconFactory =  &theIconFactory;

	animationTimer.start();
}

void PassiveScene4::update()
{
	if(animationTimer.getSeconds()>15){ // TODO - find out timings for this screen
		// test dispatching event
		animationTimer.stop();
		animationTimer = Timer(); // reset the timer
		_signal( this );
	}
}


void PassiveScene4::animateIn(){

}

void PassiveScene4::animateOut(){

}


void PassiveScene4::draw()
{
	//font.draw(); // THINK THIS IS DONE BY BASE CLASS ANYWAYS
}