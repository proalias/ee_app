#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "ParticleA.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#include <list>
using std::list;


class KParticlesApp : public AppBasic {
  public:
	 
	std::list<ParticleA>	mParticles;

	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void KParticlesApp::setup()
{
	//myFont = FontRenderer();
	//myFont.addLine( "4GEE IS HERE AV av avo wv", 10 );	

	for( int i=0; i<1000; i++ )
	{
			//float x = //character[i][0]+xPosition;
			//float y = //character[i][1]+yPosition;

		ParticleA particle = ParticleA();
		particle.init();

		particle.setBounds( 0,500,0,500 );

		particle.width = randFloat(5);
	
		particle.x=randFloat(500);
		particle.y=randFloat(500);

		//particle.setBounce(-1);
		particle.setMaxSpeed(2);

		//particle.setEdgeBehavior("wrap");

		particle.setEdgeBehavior("bounce");

		particle.setWander(3);
		particle.setGrav(0);

		particle.addRepelPoint( 200,300,100,100 );

		mParticles.push_back( particle );
	}

}

void KParticlesApp::mouseDown( MouseEvent event )
{
}

void KParticlesApp::update()
{
	for( list<ParticleA>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
		p->update();
	}

}

void KParticlesApp::draw()
{
	// clear out the window with RED
	gl::clear( Color( 1, 0, 0 ) ); 

	gl::color( Color( 1, 1, 1 ) );

	for( list<ParticleA>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
	//	p->mLoc+=( Rand::randFloat( 0.2f ) - Rand::randFloat( 0.2f ) );
	//	p->draw();

		gl::drawSolidCircle( Vec2f( p->x, p->y ), p->width );

	}

}

CINDER_APP_BASIC( KParticlesApp, RendererGl )