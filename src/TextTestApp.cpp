#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Text.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/Utilities.h"
#include "cinder/Font.h"
#include "cinder/Rand.h"
#include "Resources.h"
#include "cinder/app/AppBasic.h"
#include "Particle.h"
#include "ColorConstants.h"
#include "FontRenderer.h"
#include "ParticleA.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#include <list>
using std::list;

static const bool PREMULT = false;

class TextTestApp : public AppNative {
 public:

	void prepareSettings( Settings *settings ); // TODO - whats this wheres it get called?

	void setup();
	void update();
	void draw();

	gl::Texture bgImage;
	
	gl::Texture mSimpleTexture;

	FontRenderer myFont;

	 public:
	 
	std::list<ParticleA>	mParticles;

};



void TextTestApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 1280, 800 );
	//settings->setWindowSize( 1280, 800 );
	//settings->setFrameRate( 30.0f );
	settings->setFullScreen( true );
}


void TextTestApp::setup()
{
	//console() << "scoopfullhd.png lives at: " << getAssetPath( "scoopfullhd.png" ) << std::endl;

	// TODO - fit to screen?...
	bgImage = loadImage( loadAsset( "scoopfullhd.png" ) );
	
	// TODO - might be used for rubrik font later.. so leave here

	// Create a custom font by loading it from a resource
	//	Font customFont( Font( loadResource( RES_CUSTOM_FONT ), 72 ) );
	//console() << "This font is called " << customFont.getFullName() << std::endl;
	//TextLayout simple;
	//simple.setFont( customFont );
	//simple.setColor( Color( 1, 1, 1 ) );
	//simple.setColor( ColorConstants::TEAL );
	//simple.addLine( "4GEE IS HERE" );
	//simple.addLine( "SIMPLE TEXT TEST 1" );
	//mSimpleTexture = gl::Texture( simple.render( true, PREMULT ) );

	myFont = FontRenderer();
	myFont.addLine( "WELCOME TO", 10 ); // TODO - parameter needs to be font size
	myFont.addLine( "THE NEW NETWORK", 10 ); // TODO - parameter needs to be font size
	myFont.addLine( "FOR YOUR", 10 ); // TODO - parameter needs to be font size
	myFont.addLine( "DIGITAL LIFE", 10 ); // TODO - parameter needs to be font size

	// myFont.addLine( "some test", 10 ); TODO - addline increments y position by previous text height
	// TODO - text needs to centre align
	for( int i=0; i<1000; i++ )
	{
			//float x = //character[i][0]+xPosition;
			//float y = //character[i][1]+yPosition;

		ParticleA particle = ParticleA();
		particle.init();

		particle.setBounds( 0,getWindowWidth(),0,getWindowHeight() );

		particle.width = randFloat(5);
	
		particle.x=randFloat(getWindowWidth());
		particle.y=randFloat(getWindowHeight());

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

void TextTestApp::update()
{
	for( list<ParticleA>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
		p->update();
	}
}

void TextTestApp::draw()
{
	// this pair of lines is the standard way to clear the screen in OpenGL
	glClearColor( 0,0,0,1 );
	glClear( GL_COLOR_BUFFER_BIT );
	
	//gl::setMatricesWindow( getWindowSize() );

	gl::draw( bgImage );

//	gl::enableAlphaBlending( PREMULT );

	gl::color( Color::white() );
	//gl::draw( mSimpleTexture, Vec2f( 10, getWindowHeight() - mSimpleTexture.getHeight() - 5 ) );
	//gl::draw( mSimpleTexture, Vec2f( 10, 10 ) );

	//TODO - dont think i have to keep calling this.
	// tell the font to draw?
	myFont.draw();

	gl::color( Color( 1, 1, 1 ) );

	for( list<ParticleA>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
	//	p->mLoc+=( Rand::randFloat( 0.2f ) - Rand::randFloat( 0.2f ) );
	//	p->draw();

		gl::drawSolidCircle( Vec2f( p->x, p->y ), p->width );

	}

}

// This line tells Cinder to actually create the application
CINDER_APP_NATIVE( TextTestApp, RendererGl )