#include "PassiveScene3.h"

PassiveScene3::PassiveScene3( const FontRenderer &theFont )
{
	font = theFont; // TODO - check im doing this right? dereferecing properly
	setup();
}

void PassiveScene3::setup()
{
	font.clear();

	//font = FontRenderer();
	font.addLine( "PREPARE TO GO", 3 );
	font.addLine( "   SUPERFAST", 5 );


	// TODO - then clear then says...

	//
	// TODO - font animate out. clear on complete maybe?
	font.clear();
	font.addLine( "WITH SUPERFASY", 3 );
	font.addLine( "   4GEE AND", 3 );
	font.addLine( "   FIBRE BROADBAND", 3 );

	
}


void PassiveScene3::animateIn(){

}

void PassiveScene3::animateOut(){

}


void PassiveScene3::draw()
{

	font.draw(); // check does this handle itself now animate so needed here?

	// TODO - if complete dispatch some kind of complete event so parent can move to next passive scene
}