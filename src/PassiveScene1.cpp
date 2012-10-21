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

	//font->animateIn(); // TODO - animate in is broken

	//_signal( this );

	phase = 0;

	animationTimer.start();

}

void PassiveScene1::update()
{

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