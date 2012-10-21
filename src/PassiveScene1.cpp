#include "PassiveScene1.h"
#include "boost/bind.hpp"

PassiveScene1::PassiveScene1()
{
	_id = 1; // for boost signal
}

void PassiveScene1::setup( FontRenderer &thefont, IconFactory &theIconFactory )
{
	font = &thefont;

	iconFactory =  &theIconFactory;

	mCue = timeline().add( bind(&PassiveScene1::showFrame2, this), timeline().getCurrentTime() + 10 );
	// http://www.thegrego.com/2012/09/02/flash-to-cinder-timed-event-loops/
}

void PassiveScene1::showFrame2()
{
	// font->addLine( "timer works", 2 );
	font->clear();
	font->setPosition(200.0,100.0);
	font->setColor(Color(1.0,1.0,1.0));

	font->addLine( "WELCOME TO", 2 );
	font->addLine( "THE NEW NETWORK", 2 );
	font->addLine( "          FOR YOUR", 2 );
	font->addLine( "          DIGITAL LIFE", 2 );

	font->animateIn();

	mCue = timeline().add( bind(&PassiveScene1::showFrame3, this), timeline().getCurrentTime() + 12 );
}

void PassiveScene1::showFrame3()
{
	font->animateOut();
	mCue = timeline().add( bind(&PassiveScene1::showFrame4, this), timeline().getCurrentTime() + 6 );
}

void PassiveScene1::showFrame4()
{
	_signal( this );
}

void PassiveScene1::update()
{
}

void PassiveScene1::draw()
{
}