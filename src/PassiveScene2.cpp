#include "PassiveScene2.h"
#include "boost/bind.hpp"

PassiveScene2::PassiveScene2()
{
	_id = "PassiveScene2"; // for boost signal
}

void PassiveScene2::setup( FontRenderer &thefont, IconFactory &theIconFactory )
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
	iconFactory =  &theIconFactory;

	// TODO - get the name of the city from the config file
	// font->addLine( "LONDON", 3 );

	animationTimer.start();
}

void PassiveScene2::update()
{
	if(animationTimer.getSeconds()>5 && phase != 1){
		phase = 1;
		font->animateIn();
	}

	if(animationTimer.getSeconds()>20 && phase != 2){
		phase = 2;
		// test dispatching event
		//_signal( this );
		font->animateOut();
		//font->clear();
		//font->addLine( "end scene 3", 3 );
	}
	if(animationTimer.getSeconds()>30 && phase !=3){
		phase = 3;
		animationTimer.stop();
		animationTimer = Timer(); // reset the timer
		
		_signal( this );
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