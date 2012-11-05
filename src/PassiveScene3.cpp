#include "PassiveScene3.h"
#include "boost/bind.hpp"

#include "cinder/ImageIo.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Utilities.h"


using namespace ci;
using namespace app;
using namespace std;

PassiveScene3::PassiveScene3()
{
	_id = 3; // for boost signal

	particleAlpha = 0.4;

	isFrame1=true;
	isFrame2=false;
	isFrame3=false;
	isFrame4=false;

	alphaValue=0.9;

	imageAlpha=0;

	leftShift=0;
	
	gridSpeed=1.1;
	gridZ = 0;

	incrementer=0;
}

void PassiveScene3::setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles, std::vector<ParticleA> &thegridLayer )
{
	font = &thefont;
	font->clear();
	font->setPosition(350,100);
	font->setColor(Color(1.0,1.0,1.0));
	font->addLine( "PREPARE TO GO", 2.5 );
	font->addLine( "      SUPERFAST", 2.5 );
	font->animateIn();

	iconFactory =  &theIconFactory;

	fgParticles = &thefgParticles;
//gParticles->hide();


	// TODO - fit image to screen?... at moment we rely on screen res matching our image yet we draw grid dynamically
	try { bgImage = loadImage( loadAsset("scoopfullhd.png")  ); }
	catch( const std::exception &e ) { console() << "Could not load texture: " << e.what() << std::endl; }


	particleTexture = TextureGlobals::getInstance()->getParticleTexture(6);
	otherParticleTexture = TextureGlobals::getInstance()->getParticleTexture(4);
	
	gridLayer = &thegridLayer;

	gridSpeed=0.1;
	particleSpeed=50;

	/*
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
	*/
	fgParticles->overrideDrawMethodInScene = true;

	mCue = timeline().add( boost::bind(&PassiveScene3::showFrame2, this), timeline().getCurrentTime() + 5 );
}

void PassiveScene3::showFrame2(){

	isFrame1=false;
	isFrame2=true;
	isFrame3=false;

	//fgParticles->overrideDrawMethodInScene = true;
	font->animateOut();
	mCue = timeline().add( boost::bind(&PassiveScene3::showFrame3, this), timeline().getCurrentTime() + 3 );
	//showFrame3();
}

void PassiveScene3::showFrame3(){

	isFrame1=false;
	isFrame2=false;
	isFrame3=true;
	isFrame4=false;

	particleSpeed=0;

	font->clear();
	font->setPosition(350,100);
	font->setColor(Color(1.0,1.0,1.0));

	font->addLine( "WITH SUPERFAST", 2.4 );
	font->addLine( "      <Y>#4GEE</Y> AND", 2.4 );
	font->addLine( "      <Y>FIBRE</Y>", 2.4);
	font->addLine( "      <Y>BROADBAND</Y>", 2.4 );
	//font->animateIn();

	showTerms = true;
	font->animateIn();
	
	mCue = timeline().add( boost::bind(&PassiveScene3::showFrame4, this), timeline().getCurrentTime() + 10 );
}


void PassiveScene3::showFrame4(){
	showTerms = false;	
	isFrame1=false;
	isFrame2=false;
	isFrame3=false;
	isFrame4=true;

//	fgParticles->overrideDrawMethodInScene = false;

	font->animateOut();

	mCue = timeline().add( boost::bind(&PassiveScene3::showFrame5, this), timeline().getCurrentTime() + 2 );
}

void PassiveScene3::showFrame5(){
	fgParticles->overrideDrawMethodInScene = false;
	//font->animateOut();
	mCue->removeSelf();
	_signal(this);
}


void PassiveScene3::exitNow()
{

	font->animateOut();
	
	//timeline().removeTarget (this);
	
	mCue->removeSelf();
	//mCue = timeline().add( boost::bind(&PassiveScene3::showFrame5, this), timeline().getCurrentTime() + 2 );

}


void PassiveScene3::update()
{
	
}

void PassiveScene3::draw()
{
	gl::disableAlphaBlending();
	gl::enableAlphaBlending();
	gl::color( ColorA(1.0f, 1.0f, 1.0f, imageAlpha ) );

	gl::draw( bgImage );

	gl::enableAdditiveBlending();
	

	if(isFrame2)
	{
		imageAlpha+=0.06;

		alphaValue-=0.04;

		if(gridSpeed<30){
			// ZOOM THE GRID
			gridSpeed+=incrementer;
			incrementer++;
		}else
		{
			gridSpeed+=incrementer/2;
		}

		leftShift++;

		for( int i=3; i<20; i++ ){
			gl::color( 1, 1, 1, alphaValue );
			gl::pushMatrices();
			gl::translate( leftShift/2, 0, gridSpeed*i );
	
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
	}

	
	if(!isFrame1 && (particleAlpha>0) ){
	
//		imageAlpha-=0.1;

		//if(particleSpeed>1000){
		//	particleSpeed=50;
		//	localParticles.clear();
		//}

		//particleSpeed +=50;

		gl::color( 1, 1, 1, particleAlpha );
	//	gl::pushMatrices();
	//	gl::translate(0,0,particleSpeed);
	
			//if(i==0){
	for( int i=0; i<2; i++ ){
			ParticleA particle = ParticleA();
			particle.init();
			particle.setBounds( 0,getWindowWidth(),0,getWindowHeight() );
			particle.width = randFloat(3);
			particle.x = (getWindowWidth()/2) + randFloat(-1,1);
			particle.y = (getWindowHeight()/2) + randFloat(-1,1);
			particle.setMaxSpeed(80);
			particle.setEdgeBehavior("remove");
			particle.setWander(0);
			particle.setDamp(2);
			//particle.setGrav(10);

			if(particle.x>getWindowWidth()/2){
				particle.setVx( randFloat(10,80) );
			}else{
				particle.setVx( -randFloat(10,80) );
			}

			if(particle.y>getWindowHeight()/2){
				particle.setVy( randFloat(10,80) );
			}else{
				particle.setVy( -randFloat(10,80) );
			}

			localParticles.push_back( particle );
		}
		//gl::translate(0,0,testVar*i);

		for( list<ParticleA>::iterator p = localParticles.begin(); p != localParticles.end(); ++p )
		{

			p->update();

			p->width+=14;
			p->height+=14;

			if (p->width>300){
				p = localParticles.erase(p); // remove any big ones
			}

			Rectf rect = Rectf(p->x - p->width, p->y - p->width, p->x + p->width, p->y + p->width);
			gl::draw( *otherParticleTexture, rect );
			//gl::drawSolidCircle( Vec2f( p->x, p->y ), p->width );
		}

	//	gl::popMatrices();
	}


	if(isFrame4){
		imageAlpha-=0.06;
		particleAlpha-=0.1;
	}

	gl::color( ColorA(1.0f, 1.0f, 1.0f, 1.0f ) );
	// now image is drawn we can put our additive blend back on for textures.
	//gl::enableAdditiveBlending();
	
	gl::disableAlphaBlending();

	
	if (showTerms==true){
		ci::gl::pushMatrices();
		ci::gl::translate(0,800-142,0);
		ci::gl::enableAlphaBlending();
		ci::gl::draw(*TextureGlobals::getInstance()->getParticleTexture(9));
		ci::gl::disableAlphaBlending();
		ci::gl::popMatrices();
	}
}