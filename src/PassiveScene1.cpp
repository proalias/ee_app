#include "PassiveScene1.h"
#include "boost/bind.hpp"


using namespace cinder;
using namespace app;
using namespace std;

PassiveScene1::PassiveScene1()
{
	_id = 1; // for boost signal
}

void PassiveScene1::setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles,std::vector<ParticleA> &thegridLayer )
{

	font = &thefont;
	
	iconFactory =  &theIconFactory;

	fgParticles = &thefgParticles;

//	if(fgParticles->mParticles.size()<1){
//		fgParticles->setup( 100 );
//	}
	mCue = timeline().add( boost::bind(&PassiveScene1::showFrame2, this), timeline().getCurrentTime() + 25 );
	// http://www.thegrego.com/2012/09/02/flash-to-cinder-timed-event-loops/
}


void PassiveScene1::exitNow()
{
	font->animateOut();
	
	timeline().removeTarget (this);

}


void PassiveScene1::showFrame2()
{
	// font->addLine( "timer works", 2 );
	font->clear();
	font->setPosition(350.0,100.0);
	font->setColor(Color(1.0,1.0,1.0));

	font->addLine( "WELCOME TO", 2 );
	font->addLine( "THE NEW NETWORK", 2 );
	font->addLine( "          FOR YOUR", 2 );
	font->addLine( "          DIGITAL LIFE", 2 );

	font->animateIn();

	mCue->removeSelf();
	mCue = timeline().add( boost::bind(&PassiveScene1::showFrame3, this), timeline().getCurrentTime() + 8);
}

void PassiveScene1::showFrame3()
{
	font->animateOut();
	mCue->removeSelf();
	mCue = timeline().add( boost::bind(&PassiveScene1::showFrame4, this), timeline().getCurrentTime() + 3 );
	//fgParticles->hide();
}

void PassiveScene1::showFrame4()
{
	mCue->removeSelf();
	_signal( this );
}

void PassiveScene1::update()
{
}

void PassiveScene1::draw()
{
}