#include "Background.h"

#include "cinder/ImageIo.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Utilities.h"

#include <list>

using namespace ci;
using namespace ci::app;
using namespace std;

using std::list;

Background::Background(){}

void Background::setRepelClips( std::vector<CinderClip> &rclips ) // TODO - if were storing repel clips make this param const
{
	repelClips = rclips;
}

void Background::setup()
{
	//console() << "scoopfullhd.png lives at: " << getAssetPath( "scoopfullhd.png" ) << std::endl;

	// TODO - fit iamge to screen?... at moment we rely on screen res matching our image yet we draw grid dynamically
	try { bgImage = loadImage( loadAsset("scoopfullhd.png")  ); }
	catch( const std::exception &e ) { console() << "Could not load texture: " << e.what() << std::endl; }

	Background::drawGrid( gridLayer1, 0 );
	Background::drawGrid( gridLayer2, -2 );
	Background::drawGrid( gridLayer3, 2 );
}


void Background::update()
{
	for( vector<ParticleA>::iterator gp = gridLayer1.begin(); gp != gridLayer1.end(); ++gp ){
		gp->update();
	}
	for( vector<ParticleA>::iterator gp2 = gridLayer2.begin(); gp2 != gridLayer2.end(); ++gp2 ){
		gp2->update();
	}
	for( vector<ParticleA>::iterator gp3 = gridLayer3.begin(); gp3 != gridLayer3.end(); ++gp3 ){
		gp3->update();
	}
}


void Background::drawGrid( std::vector<ParticleA> &fieldLayerContainer, int offset )
{
	int SPACING = 40;

	float COLUMNS = cinder::app::getWindowWidth()/SPACING;
	float ROWS = cinder::app::getWindowHeight()/SPACING;
	
	//fieldLayerContainer.clear();

	for( int j=0; j<ROWS; j++ ){
		for( int i=0; i<COLUMNS; i++ ){

			ParticleA particle = ParticleA();
			particle.init();
			particle.setBounds( 0, getWindowWidth(), 0, getWindowHeight() );
			particle.width = 2;//andFloat(2,6);
	
			particle.x = ( i*SPACING ) + offset;
			particle.y = ( j*SPACING ) + offset;

			//particle.setBounce(-1);
			particle.setMaxSpeed(10);
			//particle.setEdgeBehavior("wrap");

			//particle.setWander(3);
			particle.setGrav(0);
			particle.addSpringPoint( particle.x, particle.y, 0.01 ); // FORCES THE PARTICLE INTO POSITION

			for (int i=0; i<repelClips.size(); i++){

				if(i==3){
					particle.addRepelClip( repelClips[i], 175, 175 );
				}else{
					particle.addRepelClip( repelClips[i], 50, 70 );
				}
			}

			fieldLayerContainer.push_back( particle );
		}
	}

}


void Background::draw()
{
	// this pair of lines is the standard way to clear the screen in OpenGL
	glClearColor( 0,0,0,1 );
	glClear( GL_COLOR_BUFFER_BIT );

	//gl::setMatricesWindow( getWindowSize() );

	gl::draw( bgImage );

	gl::enableAlphaBlending();

	gl::color( 1, 1, 1, 0.6 );

	for( vector<ParticleA>::iterator p = gridLayer1.begin(); p != gridLayer1.end(); ++p ){
		gl::drawSolidCircle( Vec2f( p->x, p->y ), p->width + (p->getVx()+p->getVy())/5 );
	}

	gl::color( 1, 1, 1, 0.5 );
	
	gl::pushMatrices();
	gl::translate(0,0,-10);
	for( vector<ParticleA>::iterator p2 = gridLayer2.begin(); p2 != gridLayer2.end(); ++p2 ){
		gl::drawSolidCircle( Vec2f( p2->x+2, p2->y+2 ), p2->width + (p2->getVx()+p2->getVy())/5);
	}
	gl::popMatrices();

	gl::color( 1, 1, 1, 0.4 );

	gl::pushMatrices();
	gl::translate(0,0,-20);
	for( vector<ParticleA>::iterator p3 = gridLayer3.begin(); p3 != gridLayer3.end(); ++p3 ){
		gl::drawSolidCircle( Vec2f( p3->x-2, p3->y-2 ), p3->width + (p3->getVx()+p3->getVy())/5 );
	}

	gl::popMatrices();
}