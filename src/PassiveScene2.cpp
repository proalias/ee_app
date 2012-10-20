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
	font->addLine( "4GEE IS HERE", 3 );
	font->addLine( "   IS HERE", 4 );

	//_signal( this );

	animationTimer.start();
}

void PassiveScene2::update()
{
	if(animationTimer.getSeconds()>7){
		// test dispatching event
		animationTimer.stop();
		animationTimer = Timer(); // reset the timer
		//_signal( this );

		font->clear();

		font->addLine( "COOL THEN SCENES ARE SORTED", 3 );
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