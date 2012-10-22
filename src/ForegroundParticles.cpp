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

}

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
}


void ForegroundParticles::destroy()
{
	mParticles.clear();
}

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

		particle.width = randFloat(3,10);
	
		particle.x=randFloat(getWindowWidth());
		particle.y=randFloat(getWindowHeight());

		//particle.setBounce(-1);
		particle.setMaxSpeed(5);

		//particle.setEdgeBehavior("wrap");

		particle.setWander(3);
		particle.setGrav(0);
		
		// (int i=0; i<20; i++){
		//	particle.addRepelClip( repelClips[i],500,200 );
		//}
		

		// TODO REPELLER FOR FONT. TO BE ABLE TO SHOW /HIDE
		// particle.addRepelClip( repelClips[i],500,200 );

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
	//gl::enableAdditiveBlending();

	// Turns on additive blending so we can draw a bunch of glowing images without
	// needing to do any depth testing.
	//glDepthMask( GL_FALSE );
	//glDisable( GL_DEPTH_TEST );
	//glEnable( GL_BLEND );
	//glBlendFunc( GL_SRC_ALPHA, GL_ONE );

	gl::enableAlphaBlending();
	gl::color( Color( 1, 1, 1 ) );

	// TODO - may be passing foreground particles into scenes. but still probs drawn here
	for( list<ParticleA>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
		gl::drawSolidCircle( Vec2f( p->x, p->y ), p->width );
	}


}