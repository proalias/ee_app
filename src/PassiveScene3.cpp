#include "PassiveScene3.h"
#include "boost/bind.hpp"

PassiveScene3::PassiveScene3()
{
	_id = 3; // for boost signal
}

void PassiveScene3::setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles, std::vector<ParticleA> &thegridLayer1 )
{
	font = &thefont;
	font->clear();
	font->setPosition(200,100);
	font->setColor(Color(1.0,1.0,1.0));
	font->addLine( "PREPARE TO GO", 3 );
	font->addLine( "         SUPERFAST", 3 );
	font->animateIn();

	iconFactory =  &theIconFactory;

	fgParticles = &thefgParticles;

	fgParticles->mParticles.clear();
	
	/*
	for( int i=0; i<50; i++ )
	{
		ParticleA particle = ParticleA();
		particle.init();
		particle.setBounds( 0,getWindowWidth(),0,getWindowHeight() );
		particle.width = randFloat(3,10);
		particle.x=randFloat(getWindowWidth());
		particle.y=randFloat(getWindowHeight());
		//particle.setBounce(-1);
		particle.setMaxSpeed(300);
		particle.setEdgeBehavior("wrap");
		particle.setWander(30);
		particle.setGrav(0);
		
		// (int i=0; i<20; i++){
		//	particle.addRepelClip( repelClips[i],500,200 );
		//}
		
		fgParticles->mParticles.push_back( particle );
	}
	*/

	mCue = timeline().add( bind(&PassiveScene3::showFrame2, this), timeline().getCurrentTime() + 5 );
}

void PassiveScene3::showFrame2(){
	font->animateOut();
	mCue = timeline().add( bind(&PassiveScene3::showFrame3, this), timeline().getCurrentTime() + 2 );
}

void PassiveScene3::showFrame3(){
	
	font->clear();
	font->setPosition(300,100);
	font->setColor(Color(1.0,1.0,1.0));

	font->addLine( "WITH SUPERFAST", 2 );
	font->addLine( "      #4GEE AND", 2 );
	font->addLine( "      FIBRE BROADBAND", 2 );
	font->animateIn();

	mCue = timeline().add( bind(&PassiveScene3::showFrame4, this), timeline().getCurrentTime() + 10 );
}

void PassiveScene3::showFrame4(){
	font->animateOut();
	mCue = timeline().add( bind(&PassiveScene3::showFrame5, this), timeline().getCurrentTime() + 5 );
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