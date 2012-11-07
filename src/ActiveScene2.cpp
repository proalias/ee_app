#include "ActiveScene2.h"

using namespace ci;
using namespace app;
using namespace std;

ActiveScene2::ActiveScene2()
{
	_id = 102; // for boost signal. ACTIVE SCENES START FROM 101. due to passive and no strings etc
	showSuperfast=false;
}

void ActiveScene2::setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles, std::vector<ParticleA> &thegridLayer1 )
{
	font = &thefont;
	//font->animateOut();
	
	runningSpeed = 0;

	//font->animateIn(); // TODO - animateIn not working on this revision?
	
	//gestureTracker = GestureTracker::getInstance();

	iconFactory =  &theIconFactory;

	fgParticles = &thefgParticles;


	showFrame2();

	//bubbleMan = 	mMovie = qtime::MovieGl( moviePath );
	//	mMovie.setLoop();

	//	mMovie.play();

}

void ActiveScene2::showFrame2(){

	font->clear();
	font->setPosition(300.0,100.0);
	font->setColor(Color(1.0,1.0,1.0));
	font->addLine( "<Y>RUN ON THE SPOT</Y>", 3 );
	font->addLine( "  TO GO GO GO", 2 );
	font->animateIn();

	mCue = timeline().add( boost::bind(&ActiveScene2::showFrame4, this), timeline().getCurrentTime() + 205 );

	speedDialSwoosh.setPoints( iconFactory->getPointsForIcon(IconFactory::SWOOSH) ); // TODO - animate in from grid
	speedDialSwoosh.pos = Vec2f(600,600);
	speedDialSwoosh.animateIn();

	speedDialNeedle.setPoints( iconFactory->getPointsForIcon(IconFactory::DIAL) ); // TODO - animate in from grid
	speedDialNeedle.pos = Vec2f(600,600);
	speedDialNeedle.animateIn();

}

void ActiveScene2::showFrame3()
{
	font->animateOut();
	
	//hand = IconRenderer();
	
	

	// TODO - cull this cue if interaction happens. OR return in each keyframe
	mCue->removeSelf();
	mCue = timeline().add( boost::bind(&ActiveScene2::showFrame4, this), timeline().getCurrentTime() + 8 );
}

void ActiveScene2::showFrame4()
{
	speedDialSwoosh.animateOut();
	speedDialNeedle.animateOut();
	mCue->removeSelf();
	mCue = timeline().add( boost::bind(&ActiveScene2::showFrame5, this), timeline().getCurrentTime() + 2 );

}


void ActiveScene2::showFrame5()
{
	mCue->removeSelf();
	_signal( this );
}


void ActiveScene2::exitNow()
{
	speedDialNeedle.animateOut();
	speedDialSwoosh.animateOut();
	
	
	mCue->removeSelf();
	mCue = timeline().add( boost::bind(&ActiveScene2::showFrame5, this), timeline().getCurrentTime() + 2 );

}


void ActiveScene2::update()
{
	//does this ever get called?
}

void ActiveScene2::draw()
{
	runningSpeed += GestureTracker::getInstance()->lookForRunningOnTheSpot();

	runningSpeed = runningSpeed * 0.9;

	/*
	gl::color(Color(1.0,0.0,0.0));
	Rectf powerBar = ci::Rectf(100,100,100+(10*runningSpeed),200);
	gl::drawSolidRect(powerBar);
	gl::color(Color(1.0,1.0,1.0));
	*/


	float dialAngle = 40 * runningSpeed;
	if (dialAngle > 180){
		dialAngle = 180;
	}

	if (runningSpeed > 5){
		showFrame5();
	}

	speedDialNeedle.rotation = dialAngle;


	speedDialSwoosh.draw();
	speedDialNeedle.draw();
}

