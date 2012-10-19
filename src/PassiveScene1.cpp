#include "PassiveScene1.h"

PassiveScene1::PassiveScene1( const FontRenderer &theFont )
{
	font = theFont; // TODO - check im doing this right? dereferecing properly
	setup();
}

void PassiveScene1::setup()
{
	font.clear();

	//font = FontRenderer();
	font.addLine( "WELCOME TO", 2 );
	font.addLine( "THE NEW NETWORK", 2 );
	font.addLine( "          FOR YOUR", 2 );
	font.addLine( "          DIGITAL LIFE", 2 );	

}


void PassiveScene1::animateIn(){

}

void PassiveScene1::animateOut(){

}


void PassiveScene1::draw()
{
	font.draw();

	// TODO - if complete dispatch some kind of complete event so parent can move to next passive scene

}