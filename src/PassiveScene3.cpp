#include "PassiveScene3.h"
#include "boost/bind.hpp"

PassiveScene3::PassiveScene3()
{
	_id = 3; // for boost signal
}

void PassiveScene3::setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles )
{
	font = &thefont;
	font->clear();
	font->setPosition(200,100);
	font->setColor(Color(1.0,1.0,1.0));
	//font = FontRenderer();
	font->addLine( "PREPARE TO GO", 3 );
	font->addLine( "              SUPERFAST", 3 );

	// TODO - then clear then says...


	iconFactory =  &theIconFactory;
	//_signal( this );

	mCue = timeline().add( bind(&PassiveScene3::showFrame2, this), timeline().getCurrentTime() );
}

void PassiveScene3::showFrame2(){
	font->animateIn();
	mCue = timeline().add( bind(&PassiveScene3::showFrame3, this), timeline().getCurrentTime() + 10 );

}

void PassiveScene3::showFrame3(){
	font->animateOut();
	mCue = timeline().add( bind(&PassiveScene3::showFrame4, this), timeline().getCurrentTime() + 10 );

}


void PassiveScene3::showFrame4(){
	
	font->clear();
	font->setPosition(200,100);
	font->setColor(Color(1.0,1.0,1.0));

	font->addLine( "WITH SUPERFAST", 2 );
	font->addLine( "      4GEE AND", 2 );
	font->addLine( "      FIBRE BROADBAND", 2 );

	mCue = timeline().add( bind(&PassiveScene3::showFrame5, this), timeline().getCurrentTime() + 10 );



}

void PassiveScene3::showFrame5(){
	_signal(this);
}

void PassiveScene3::update()
{
	
}



void PassiveScene3::draw()
{
	//font.draw(); // THINK THIS IS DONE BY BASE CLASS ANYWAYS
}