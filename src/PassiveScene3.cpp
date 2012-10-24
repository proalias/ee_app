#include "PassiveScene3.h"
#include "boost/bind.hpp"

PassiveScene3::PassiveScene3()
{
	_id = 3; // for boost signal

	isFrame2=false;
}

void PassiveScene3::setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles, std::vector<ParticleA> &thegridLayer )
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

	fgParticles->overrideDrawMethodInScene = true;

	//fgParticles->mParticles.clear();

	//if(fgParticles->mParticles.size()<1){
	//	fgParticles->setup( 100 );
	//}
	fgParticles->hide();

	particleTexture = TextureGlobals::getInstance()->getParticleTexture(6);
	otherParticleTexture = TextureGlobals::getInstance()->getParticleTexture(5);
	
	gridLayer = &thegridLayer;

	gridSpeed=0;
	particleSpeed=0;

	// create a particle
	ParticleA particle = ParticleA();
	particle.init();
	particle.setBounds( 0,getWindowWidth(),0,getWindowHeight() );
	particle.width = randFloat(3,10);
	particle.x=randFloat(getWindowWidth());
	particle.y=randFloat(getWindowHeight());
	particle.setMaxSpeed(0);
	particle.setEdgeBehavior("wrap");
	particle.setWander(0);
	particle.setGrav(0);
	localParticles.push_back( particle );




	mCue = timeline().add( bind(&PassiveScene3::showFrame2, this), timeline().getCurrentTime() + 5 );
}

void PassiveScene3::showFrame2(){

	isFrame2=true;

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
	fgParticles->overrideDrawMethodInScene = false;
	//fgParticles.over
	_signal(this);
}

void PassiveScene3::update()
{
	
}



void PassiveScene3::draw()
{

	if(isFrame2)
	{
		// ZOOM THE GRID
	
		gridSpeed+=4;
	
		for( int i=0; i<7; i++ ){
			gl::color( 1, 1, 1, 0.7 );
			gl::pushMatrices();
			gl::translate(0,0,gridSpeed*i);
		
			for( vector<ParticleA>::iterator p = gridLayer->begin(); p != gridLayer->end(); ++p ){
				float rad = p->width + (p->getVx()+p->getVy())/5;
				Rectf rect = Rectf(p->x - p->width - rad, p->y - p->width - rad,p->x + p->width + rad, p->y + p->width + rad);
				gl::draw( *particleTexture, rect );
			}
			gl::popMatrices();
		}
	

	
		//if(gridSpeed>150)
	//	{
			// ZOOM INDIVIDUAL PARTICLES
			particleSpeed +=10;

			gl::color( 1, 1, 1, 0.4 );
			gl::pushMatrices();
			gl::translate(0,0,particleSpeed);
	
			//if(i==0){
	
			ParticleA particle = ParticleA();
			particle.init();
			particle.setBounds( 0,getWindowWidth(),0,getWindowHeight() );
			particle.width = randFloat(3,10);
			particle.x=randFloat(getWindowWidth());
			particle.y=randFloat(getWindowHeight());
			particle.setMaxSpeed(0);
			particle.setEdgeBehavior("wrap");
			particle.setWander(0);
			particle.setGrav(0);

			localParticles.push_back( particle );
			
			//gl::translate(0,0,testVar*i);

			for( list<ParticleA>::iterator p = localParticles.begin(); p != localParticles.end(); ++p ){		
				Rectf rect = Rectf(p->x - p->width, p->y - p->width, p->x + p->width, p->y + p->width);
				gl::draw( *otherParticleTexture, rect ); // TODO - change for the foreground texture
				//gl::drawSolidCircle( Vec2f( p->x, p->y ), p->width );
			}

			gl::popMatrices();	
	//	}

	}



}