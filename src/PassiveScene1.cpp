#include "PassiveScene1.h"
#include "boost/bind.hpp"

PassiveScene1::PassiveScene1()
{
	_id = "PassiveScene1"; // for boost signal
}

void PassiveScene1::setup( FontRenderer &thefont )
{
	font = &thefont;
//	font = thefont*;
	font->clear();
	//font = FontRenderer();
	font->addLine( "WELCOME TO", 2 );
	font->addLine( "THE NEW NETWORK", 2 );
	font->addLine( "          FOR YOUR", 2 );
	font->addLine( "          DIGITAL LIFE", 2 );

	// test dispatching event
	_signal( this );
}


void PassiveScene1::animateIn(){

}

void PassiveScene1::animateOut(){

}


void PassiveScene1::draw()
{
	//font.draw(); // THINK THIS IS DONE BY BASE CLASS ANYWAYS
}