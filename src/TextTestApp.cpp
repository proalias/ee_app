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
};



void TextTestApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 1280, 800 );
	//settings->setWindowSize( 1280, 800 );
	//settings->setFrameRate( 30.0f );
	//settings->setFullScreen( true );
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
	myFont.addLine( "ALIAS IS COOL", 10 ); // TODO - parameter needs to be font size
	// myFont.addLine( "some test", 10 ); TODO - addline increments y position by previous text height
	// TODO - text needs to centre align
}

void TextTestApp::update()
{

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
}

// This line tells Cinder to actually create the application
CINDER_APP_NATIVE( TextTestApp, RendererGl )