#include "PassiveScene3.h"
#include "boost/bind.hpp"

PassiveScene3::PassiveScene3()
{
	_id = "PassiveScene3"; // for boost signal
}

void PassiveScene3::setup( FontRenderer &thefont, IconFactory &theIconFactory )
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

	iconFactory =  &theIconFactory;
	//_signal( this );

	
	phase = 0;

	animationTimer.start();
}

void PassiveScene3::update()
{
	//font->clear();
	//font->addLine( "UPDATE RUNS SCENE 2", 2 );


	if(phase == 0){
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


void PassiveScene3::animateIn(){

}

void PassiveScene3::animateOut(){

}


void PassiveScene3::draw()
{
	//font.draw(); // THINK THIS IS DONE BY BASE CLASS ANYWAYS
}