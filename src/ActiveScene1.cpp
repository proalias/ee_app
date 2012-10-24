#include "ActiveScene1.h"
#include "boost/bind.hpp"

ActiveScene1::ActiveScene1()
{
	_id = 101; // for boost signal. ACTIVE SCENES START FROM 101. due to passive and no strings etc
	showHand=false;
}

void ActiveScene1::setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles )
{
	font = &thefont;
	font->clear();
	font->setPosition(300.0,100.0);
	font->setColor(Color(1.0,1.0,1.0));
	font->addLine( "GIVE US", 3 );
	font->addLine( "     A WAVE", 3 );
	
	//font->animateIn(); // TODO - animateIn not wokring on this revision?
	
	iconFactory =  &theIconFactory;

	fgParticles = &thefgParticles;

	// TODO - TIMEOUT BACK TO NORMAL????
	mCue = timeline().add( bind(&ActiveScene1::showFrame2, this), timeline().getCurrentTime() + 10 );
	// http://www.thegrego.com/2012/09/02/flash-to-cinder-timed-event-loops/
}

void ActiveScene1::showFrame2()
{
	font->animateOut();

	//hand = IconRenderer();
	hand.setPoints( iconFactory->getPointsForIcon(IconFactory::HAND) ); // TODO - animate in from grid
	hand.pos = Vec2f(600,500);
	hand.scale = .7;
	showHand=true;

	// TODO - timeout
	// TODO - cull this cue if interaction happens. OR return in each keyframe
	mCue = timeline().add( bind(&ActiveScene1::showFrame2, this), timeline().getCurrentTime() + 5 );
}

void ActiveScene1::showFrame3()
{
	_signal( this );
}

void ActiveScene1::update()
{
}

void ActiveScene1::draw()
{
	if(showHand){
		hand.draw();
	}
}