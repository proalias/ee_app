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
	//font->animateOut();
	
	
	//font->animateIn(); // TODO - animateIn not working on this revision?
	
	//gestureTracker = GestureTracker::getInstance();

	iconFactory =  &theIconFactory;

	fgParticles = &thefgParticles;

	// TODO - TIMEOUT BACK TO NORMAL????
	//mCue = timeline().add( boost::bind(&ActiveScene1::showFrame2, this), timeline().getCurrentTime() + 2 );
	// http://www.thegrego.com/2012/09/02/flash-to-cinder-timed-event-loops/

	showFrame2();

	hand.scale = 0.7;
	//bubbleMan = 	mMovie = qtime::MovieGl( moviePath );
	//	mMovie.setLoop();

	//	mMovie.play();

}

void ActiveScene1::showFrame2(){

	font->clear();
	font->setPosition(300.0,100.0);
	font->setColor(Color(1.0,1.0,1.0));
	font->addLine( "GIVE US", 3 );
	font->addLine( "     A WAVE", 3 );
	font->animateIn();

	mCue = timeline().add( boost::bind(&ActiveScene1::showFrame4, this), timeline().getCurrentTime() + 205 );

	timeline().apply(&hand.rotation,-20.0f, 15.0f, 1.0f,cinder::EaseInOutCubic()).loop(true).pingPong(true);
	timeline().apply(&hand.pos,ci::Vec2f(575.0,500.0), ci::Vec2f(625.0,500.0), 1.0f,cinder::EaseInOutCubic()).loop(true).pingPong(true);


}

void ActiveScene1::showFrame3()
{
	font->animateOut();
	
	showHand = true;
	//hand = IconRenderer();
	hand.setPoints( iconFactory->getPointsForIcon(IconFactory::HAND) ); // TODO - animate in from grid
	hand.pos = Vec2f(600,500);
	hand.animateIn();

	// TODO - cull this cue if interaction happens. OR return in each keyframe
	mCue->removeSelf();
	mCue = timeline().add( boost::bind(&ActiveScene1::showFrame4, this), timeline().getCurrentTime() + 6 );
}

void ActiveScene1::showFrame4()
{
	hand.animateOut();
	mCue->removeSelf();
	mCue = timeline().add( boost::bind(&ActiveScene1::showFrame5, this), timeline().getCurrentTime() + 2 );

}


void ActiveScene1::showFrame5()
{
	//showHand=false;
	mCue->removeSelf();
	_signal( this );
}


void ActiveScene1::exitNow()
{
	if (showHand == true){
		hand.animateOut();
	}
	
	mCue->removeSelf();
	mCue = timeline().add( boost::bind(&ActiveScene1::showFrame5, this), timeline().getCurrentTime() + 2 );

}


void ActiveScene1::update()
{
	//does this ever get called?
}

void ActiveScene1::draw()
{
	if (showHand != true && GestureTracker::getInstance()->lookForGesture(GestureTracker::GESTURE_WAVE)){
		showFrame3();
	}

	if(showHand){
		hand.draw();
	}
}