#include "PassiveScene2.h"

PassiveScene2::PassiveScene2( const FontRenderer &theFont )
{
	font = theFont; // TODO - check im doing this right? dereferecing properly
	setup();
}

void PassiveScene2::setup()
{
	font.clear();

	//font = FontRenderer();
	font.addLine( "4GEE IS HERE", 3 );
	font.addLine( "   IS HERE", 4 );


	// TODO - then clear then says...

	//
	// TODO - font animate out. clear on complete maybe?
	font.clear();
	font.addLine( "SUPERFAST", 4 );
	font.addLine( "   MOBILE #4GEE", 4 );
	font.addLine( "   ONLY ON EE", 2 );

}


void PassiveScene2::animateIn(){

}

void PassiveScene2::animateOut(){

}


void PassiveScene2::draw()
{
	font.draw();
	// TODO - if complete dispatch some kind of complete event so parent can move to next passive scene
}