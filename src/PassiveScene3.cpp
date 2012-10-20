#include "PassiveScene3.h"
#include "boost/bind.hpp"

PassiveScene3::PassiveScene3()
{
	_id = "PassiveScene3"; // for boost signal
}

void PassiveScene3::setup( FontRenderer &thefont )
{
	font = &thefont;
	font->clear();

	//font = FontRenderer();
	font->addLine( "PREPARE TO GO", 3 );
	font->addLine( "              SUPERFAST", 3 );

	// TODO - then clear then says...

	//
	// TODO - font animate out. clear on complete maybe?
	//font->clear();
	//font->addLine( "WITH SUPERFAST", 2 );
	//font->addLine( "      4GEE AND", 2 );
	//font->addLine( "      FIBRE BROADBAND", 2 );

	//_signal( this );

	animationTimer.start();
}

void PassiveScene3::update()
{
	//font->clear();
	//font->addLine( "UPDATE RUNS SCENE 2", 2 );

	if(animationTimer.getSeconds()>20){
		// test dispatching event
		animationTimer.stop();
		animationTimer = Timer(); // reset the timer
		//_signal( this );

		font->clear();
		font->addLine( "end scene 3", 3 );
	}
}


void PassiveScene3::animateIn(){

}

void PassiveScene3::animateOut(){

}


void PassiveScene3::draw()
{
	//font.draw(); // THINK THIS IS DONE BY BASE CLASS ANYWAYS
}