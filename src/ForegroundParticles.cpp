#include "ForegroundParticles.h"

#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "cinder/params/Params.h"
#include "cinder/Utilities.h"
#include "cinder/gl/gl.h"
#include "cinder/Vector.h"
#include "cinder/Rand.h"

#include "Particle.h"
#include "CinderClip.h"
#include "ParticleA.h"
//#include "TweenParticle.h"
//#include "IconFactory.h"
//#include "IconRenderer.h"

#include "cinder/app/AppBasic.h"
#include "cinder/Timeline.h"

#include <list>

using namespace ci;
using namespace ci::app;
using namespace std;

using std::list;

ForegroundParticles::ForegroundParticles(void)
{
	overrideDrawMethodInScene = false;

	particlesAlpha=1;
}



void ForegroundParticles::setRepelClips( std::vector<CinderClip> &rclips )
{
	repelClips = &rclips;

	// loop into each grid and make its clips repellers
	for( list<ParticleA>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
		for (int i=0; i<repelClips->size(); i++){
			p->addRepelClip( repelClips->at(i), 100, 100 );
			///	gp->addGravClip( repelClips->at(i), 200 );
		}
	}
}


/*

void ForegroundParticles::init(){
		mParticles.clear();

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
		
		mParticles.push_back( particle );
	}
}
*/

void ForegroundParticles::hide() // TODO - create show function too
{
	//mParticles.clear();
	// fade out the particles

	//for( list<ParticleA>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
		//p->update();

	//	mTimeline = Timeline::create();
	//	mTimeline->setDefaultAutoRemove( false );

		//mTimeline->apply();//->apply( p, p->width, 0, 1.0f );
		//mTimeline->apply( &mBoxPos2, Vec2f( 300, 50 ), Vec2f( 300, 200 ), 2.0f ).delay( 1.0f ).pingPong( true );

		//cinder::app::timeline().apply( &p, p->width, 0, 0, 1.0f );
		//cinder::app::timeline().apply( p->width, Vec2f(1400,600), ci::Vec2f(-300.0,arrow2.pos.value().y ), 2.0f , cinder::EaseInExpo() );

		//cinder::app::timeline().apply( p->width, 1.0, 1.0, 5.0f ,cinder::EaseInExpo());
	//}

	for( list<ParticleA>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
		p->die();
		//cinder::app::timeline().apply(&p->width,p->width.value(),0, 5.0f ,cinder::EaseInExpo());
	}

}


void ForegroundParticles::show() // TODO - create show function too
{
	//mParticles.clear();
	// fade out the particles

	for( list<ParticleA>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
		p->respawn();
		//cinder::app::timeline().apply(&p->width,p->width.value(),0, 5.0f ,cinder::EaseInExpo());
	}

}
/*
void ForegroundParticles::destroy()
{
	mParticles.clear();
}
*/
void ForegroundParticles::setup( int howMany )
{
	//particleImg = loadImage(loadAsset( "particle.png" ) ); // TODO - can we use image? - or sequence

	/*- Leave this for now, textures can be added to the particle later.
	//load particle textures
	pTextures.init();
	gl::Texture texture1 = loadImage(loadAsset( "ParticleFullON.png") );
	pTextures.addTexture(texture1);
	gl::Texture texture2 = loadImage(loadAsset( "ParticlePatial01.png") );
	pTextures.addTexture(texture2);
	gl::Texture texture3 = loadImage(loadAsset( "ParticlePatial02.png") );
	pTextures.addTexture(texture3);
	gl::Texture texture4 = loadImage(loadAsset( "ParticlePatial03.png") );
	pTextures.addTexture(texture4);
	gl::Texture texture5 = loadImage(loadAsset( "ParticlePatial04.png") );
	pTextures.addTexture(texture5);
	gl::Texture texture6 = loadImage(loadAsset( "ParticlePatial05.png") );
	pTextures.addTexture(texture6);
	
	*/

	// iconFactory.init(); // = maybe put one in here ? ... or a drawIcon method?

	// destroy all the old ones
	
	mParticles.clear();

	for( int i=0; i<howMany; i++ )
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
		
		mParticles.push_back( particle );
	}

}

void ForegroundParticles::update()
{
	for( list<ParticleA>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
		p->update();
	}
}

void ForegroundParticles::draw()
{

	
	//{
		gl::enableAdditiveBlending();
		gl::enableAlphaBlending();

		gl::color( ColorA(1.0f, 1.0f, 1.0f, particlesAlpha ) );

		// fade scene in or out
		if(!overrideDrawMethodInScene) // used to override now just hides here
		{
			if(particlesAlpha<1){
				particlesAlpha+=0.1;
			}
		}else
		{
			if(particlesAlpha>0){
				particlesAlpha-=0.1;
			}
		}

		if(particlesAlpha>0) // dont bother drawing if they're not visible
		{

		for( list<ParticleA>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
			//gl::drawSolidCircle( Vec2f( p->x, p->y ), p->width );		
			Rectf rect = Rectf(p->x - p->width*2, p->y - p->width*2, p->x + p->width*2, p->y + p->width*2);
			gl::draw(*p->particleTexture,rect);
		}

		}

		gl::disableAlphaBlending();
	//}

}