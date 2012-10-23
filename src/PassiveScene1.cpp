#include "PassiveScene1.h"
#include "boost/bind.hpp"

PassiveScene1::PassiveScene1()
{
	_id = 1; // for boost signal
}

void PassiveScene1::setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles )
{
	font = &thefont;
	
	iconFactory =  &theIconFactory;

	fgParticles = &thefgParticles;


	//fgParticles->destroy();//mParticles.clear();

	for( int i=0; i<100; i++ )
	{
		ParticleA particle = ParticleA();
		particle.init();
		particle.setBounds( 0,getWindowWidth(),0,getWindowHeight() );
		particle.decays = true;
		//particle.setBounce(-1);
		particle.setMaxSpeed(20);
		particle.setEdgeBehavior("wrap");
		particle.setWander(3);
		particle.setGrav(0);

		particle.respawn();
		
		// (int i=0; i<20; i++){
		//	particle.addRepelClip( repelClips[i],500,200 );
		//}
		
		fgParticles->mParticles.push_back( particle );
	}

	mCue = timeline().add( bind(&PassiveScene1::showFrame2, this), timeline().getCurrentTime() + 25 );
	// http://www.thegrego.com/2012/09/02/flash-to-cinder-timed-event-loops/
}

void PassiveScene1::showFrame2()
{
	// font->addLine( "timer works", 2 );
	font->clear();
	font->setPosition(300.0,100.0);
	font->setColor(Color(1.0,1.0,1.0));

	font->addLine( "WELCOME TO", 2 );
	font->addLine( "THE NEW NETWORK", 2 );
	font->addLine( "          FOR YOUR", 2 );
	font->addLine( "          DIGITAL LIFE", 2 );

	font->animateIn();

	mCue = timeline().add( bind(&PassiveScene1::showFrame3, this), timeline().getCurrentTime() + 8);
}

void PassiveScene1::showFrame3()
{
	font->animateOut();
	mCue = timeline().add( bind(&PassiveScene1::showFrame4, this), timeline().getCurrentTime() + 3 );
	//fgParticles->hide();
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