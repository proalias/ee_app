#include "ActiveScene1.h"

using namespace ci;
using namespace app;
using namespace std;

ActiveScene1::ActiveScene1()
{
	_id = 101; // for boost signal. ACTIVE SCENES START FROM 101. due to passive and no strings etc
	showHand=false;
}

void ActiveScene1::setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles, std::vector<ParticleA> &thegridLayer1 )
{
	font = &thefont;
	font->animateOut();
	
	//font->animateIn(); // TODO - animateIn not wokring on this revision?
	
	//gestureTracker = GestureTracker::getInstance();

	iconFactory =  &theIconFactory;

	fgParticles = &thefgParticles;

	// TODO - TIMEOUT BACK TO NORMAL????
	mCue = timeline().add( boost::bind(&ActiveScene1::showFrame2, this), timeline().getCurrentTime() + 10 );
	// http://www.thegrego.com/2012/09/02/flash-to-cinder-timed-event-loops/


}

void ActiveScene1::showFrame2(){
	font->setPosition(300.0,100.0);
	font->setColor(Color(1.0,1.0,1.0));
	font->addLine( "GIVE US", 3 );
	font->addLine( "     A WAVE", 3 );
	font->animateIn();
	mCue = timeline().add( boost::bind(&ActiveScene1::showFrame3, this), timeline().getCurrentTime() + 5 );

}

void ActiveScene1::showFrame3()
{
	font->animateOut();

	//hand = IconRenderer();
	hand.setPoints( iconFactory->getPointsForIcon(IconFactory::HAND) ); // TODO - animate in from grid
	hand.pos = Vec2f(600,500);
	hand.scale = 0.7;
	showHand=true;

	// TODO - timeout
	// TODO - cull this cue if interaction happens. OR return in each keyframe
	mCue = timeline().add( boost::bind(&ActiveScene1::showFrame4, this), timeline().getCurrentTime() + 5 );
}

void ActiveScene1::showFrame4()
{
	_signal( this );
}

void ActiveScene1::update()
{
	GestureTracker::getInstance()->lookForGesture(1);
}

void ActiveScene1::draw()
{
	if(showHand){
		hand.draw();
	}
}