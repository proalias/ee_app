#include "PassiveScene2.h"
#include "boost/bind.hpp"

PassiveScene2::PassiveScene2()
{
	_id = "PassiveScene2"; // for boost signal
}

void PassiveScene2::setup( FontRenderer &thefont )
{
	// show pin icons

	font = &thefont;
	font->clear();
	//font->addLine( "4GEE IS HERE", 3 );
	//font->addLine( "   IS HERE", 4 );

	font->addLine( "SUPERFAST", 3 );
	font->addLine( "      MOBILE #4GEE", 3 );
	font->addLine( "ONLY ON EE", 3 );

	//_signal( this );

	// TODO - get the name of the city from the config file
	// font->addLine( "LONDON", 3 );

	animationTimer.start();
}

void PassiveScene2::update()
{
	if(animationTimer.getSeconds()>15){
		// test dispatching event
		animationTimer.stop();
		animationTimer = Timer(); // reset the timer
		//_signal( this );

		font->clear();
		font->addLine( "send signal to end scene2", 3 );
	}
}


void PassiveScene2::animateIn(){

}

void PassiveScene2::animateOut(){

}


void PassiveScene2::draw()
{
	//font.draw(); // THINK THIS IS DONE BY BASE CLASS ANYWAYS
}