#include "PassiveScene4.h"

PassiveScene4::PassiveScene4( const FontRenderer &theFont )
{
	font = theFont; // TODO - check im doing this right? dereferecing properly
	setup();
}

void PassiveScene4::setup()
{
	font.clear();

	//font = FontRenderer();
	font.addLine( "COME IN", 4 );
	font.addLine( "   AND SEE US", 4 );


}


void PassiveScene4::animateIn(){

}

void PassiveScene4::animateOut(){

}


void PassiveScene4::draw()
{
	// TODO - if complete dispatch some kind of complete event so parent can move to next passive scene
}