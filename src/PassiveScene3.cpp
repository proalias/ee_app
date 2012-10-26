#include "PassiveScene3.h"
#include "boost/lambda/bind.hpp"

#include "cinder/ImageIo.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Utilities.h"

PassiveScene3::PassiveScene3()
{
	_id = 3; // for boost signal

	isFrame1=true;
	isFrame2=false;
	isFrame3=false;
	isFrame4=false;

	alphaValue=0.9;

	imageAlpha=0;

	leftShift=4;
	
	gridSpeed=1.1;
	gridZ = 0;
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


	//fgParticles->mParticles.clear();

	//if(fgParticles->mParticles.size()<1){
	//	fgParticles->setup( 100 );
	//}
	fgParticles->hide();


	// TODO - fit image to screen?... at moment we rely on screen res matching our image yet we draw grid dynamically
	try { bgImage = loadImage( loadAsset("scoopfullhd.png")  ); }
	catch( const std::exception &e ) { console() << "Could not load texture: " << e.what() << std::endl; }



	particleTexture = TextureGlobals::getInstance()->getParticleTexture(6);
	otherParticleTexture = TextureGlobals::getInstance()->getParticleTexture(5);
	
	gridLayer = &thegridLayer;

	gridSpeed=0.1;
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

	mCue = timeline().add( boost::lambda::bind(&PassiveScene3::showFrame2, this), timeline().getCurrentTime() + 5 );
}

void PassiveScene3::showFrame2(){

	isFrame1=false;
	isFrame2=true;
	isFrame3=false;

	fgParticles->overrideDrawMethodInScene = false;
	font->animateOut();
	mCue = timeline().add( boost::lambda::bind(&PassiveScene3::showFrame3, this), timeline().getCurrentTime() + 3 );
	//showFrame3();
}

void PassiveScene3::showFrame3(){

	isFrame1=false;
	isFrame2=false;
	isFrame3=true;
	isFrame4=false;

	particleSpeed=0;


	font->clear();
	font->setPosition(300,100);
	font->setColor(Color(1.0,1.0,1.0));

	font->addLine( "WITH SUPERFAST", 2.7 );
	font->addLine( "      #4GEE AND", 2.7 );
	font->addLine( "      FIBRE", 2.7);
	font->addLine( "      BROADBAND", 2.7 );
	font->animateIn();

	mCue = timeline().add( boost::lambda::bind(&PassiveScene3::showFrame4, this), timeline().getCurrentTime() + 15 );
}

void PassiveScene3::showFrame4(){
	
	isFrame1=false;
	isFrame2=false;
	isFrame3=false;
	isFrame4=true;

	fgParticles->overrideDrawMethodInScene = false;
	fgParticles->show();

	font->animateOut();


	mCue = timeline().add( boost::lambda::bind(&PassiveScene3::showFrame5, this), timeline().getCurrentTime() + 3 );
}

void PassiveScene3::showFrame5(){
	fgParticles->overrideDrawMethodInScene = false;
	fgParticles->show();
	//font->animateOut();
	_signal(this);
}

void PassiveScene3::update()
{
	
}

void PassiveScene3::draw()
{
	gl::disableAlphaBlending();
	
	gl::draw( bgImage );
	gl::enableAdditiveBlending();
	
	gl::enableAlphaBlending();
	gl::color( ColorA(1.0f, 1.0f, 1.0f, imageAlpha ) );

	if(isFrame2)
	{
		imageAlpha+=0.06;

		

		alphaValue-=0.01;

		// ZOOM THE GRID
		gridSpeed+=12;
	
		for( int i=1; i<6; i++ ){
			gl::color( 1, 1, 1, alphaValue );
			gl::pushMatrices();
			gl::translate( 0, 0, gridSpeed*i );
	
			int count=0;

			for( vector<ParticleA>::iterator p = gridLayer->begin(); p != gridLayer->end(); ++p ){

				if( (count<333)||(count>338) )
				{
					float rad = p->width + (p->getVx()+p->getVy())/5;
					Rectf rect = Rectf(p->x - p->width - rad, p->y - p->width - rad,p->x + p->width + rad, p->y + p->width + rad);
					gl::draw( *particleTexture, rect );
				}
				else
				{
					//gl::drawSolidCircle( Vec2f(p->x,p->y), 20 );

				}
				count++;
			}
			gl::popMatrices();
		}
	/*
		
		//if(gridSpeed>150)
	//	{
			// ZOOM INDIVIDUAL PARTICLES
		if(particleSpeed>450){
			particleSpeed=0;
			localParticles.clear();
		}

		particleSpeed +=25;

		gl::color( 1, 1, 1, 0.6 );
		gl::pushMatrices();
		gl::translate(0,0,particleSpeed);
	
		//if(i==0){
		for( int i=0; i<14; i++ ){
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
		}
		//gl::translate(0,0,testVar*i);

		for( list<ParticleA>::iterator p = localParticles.begin(); p != localParticles.end(); ++p ){		
			Rectf rect = Rectf(p->x - p->width, p->y - p->width, p->x + p->width, p->y + p->width);
			gl::draw( *otherParticleTexture, rect ); // TODO - change for the foreground texture
			//gl::drawSolidCircle( Vec2f( p->x, p->y ), p->width );
		}

			gl::popMatrices();	
	//	}

	*/
	}

	
	if(isFrame3){
	
//		imageAlpha-=0.1;

		if(particleSpeed>600){
			particleSpeed=0;
			localParticles.clear();
		}

		particleSpeed +=30;

		gl::color( 1, 1, 1, 0.6 );
		gl::pushMatrices();
		gl::translate(0,0,particleSpeed);
	
		//if(i==0){
	for( int i=0; i<14; i++ ){
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
	}
		//gl::translate(0,0,testVar*i);

		for( list<ParticleA>::iterator p = localParticles.begin(); p != localParticles.end(); ++p ){		
			Rectf rect = Rectf(p->x - p->width, p->y - p->width, p->x + p->width, p->y + p->width);
			gl::draw( *otherParticleTexture, rect ); // TODO - change for the foreground texture
			//gl::drawSolidCircle( Vec2f( p->x, p->y ), p->width );
		}

		gl::popMatrices();
	}


	if(isFrame4){
		imageAlpha-=0.06;
	}

	gl::color( ColorA(1.0f, 1.0f, 1.0f, 1.0f ) );
	// now image is drawn we can put our additive blend back on for textures.
	//gl::enableAdditiveBlending();
	
	gl::disableAlphaBlending();
}