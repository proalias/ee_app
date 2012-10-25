#include "Background.h"
#include "cinder/ImageIo.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Utilities.h"
#include "OutlineParams.h"
#include <list>

using namespace ci;
using namespace ci::app;
using namespace std;

using std::list;

Background::Background(){
	outlineParams = OutlineParams::getInstance();
}

void Background::setRepelClips( std::vector<CinderClip> &rclips ) // TODO - if were storing repel clips make this param const
{
	repelClips = &rclips;

	// loop into each grid and make its clips repellers
	for( vector<ParticleA>::iterator gp = gridLayer1.begin(); gp != gridLayer1.end(); ++gp ){
		for (int i=0; i<repelClips->size(); i++){
			gp->addRepelClip( repelClips->at(i), outlineParams->getForceForIndex(i), outlineParams->getMinDistForIndex(i) );
			///	gp->addGravClip( repelClips->at(i), 200 );
		}
	}
	
	for( vector<ParticleA>::iterator gp2 = gridLayer2.begin(); gp2 != gridLayer2.end(); ++gp2 ){
		for (int i=0; i<repelClips->size(); i++){
			gp2->addRepelClip( repelClips->at(i), outlineParams->getForceForIndex(i), outlineParams->getMinDistForIndex(i) );
			///	gp2->addGravClip( repelClips->at(i), 200 );
		}
	}

	for( vector<ParticleA>::iterator gp3 = gridLayer3.begin(); gp3 != gridLayer3.end(); ++gp3 ){
		for (int i=0; i<repelClips->size(); i++){
			gp3->addRepelClip( repelClips->at(i), outlineParams->getForceForIndex(i), outlineParams->getMinDistForIndex(i) );
			// gp3->addGravClip( repelClips->at(i), 200 );
		}
	}
	
}

void Background::setup()
{
	//console() << "scoopfullhd.png lives at: " << getAssetPath( "scoopfullhd.png" ) << std::endl;
	particleTexture = TextureGlobals::getInstance()->getParticleTexture(6);

	// TODO - fit image to screen?... at moment we rely on screen res matching our image yet we draw grid dynamically
	try { bgImage = loadImage( loadAsset("scoopfullhd.png")  ); }
	catch( const std::exception &e ) { console() << "Could not load texture: " << e.what() << std::endl; }

	Background::drawGrid( gridLayer1, 0, 1 );
	Background::drawGrid( gridLayer2, -2, 1.3 );
	Background::drawGrid( gridLayer3, 2, 1.6 );

	//ff.createGrid();
}


void Background::update()
{
	//ff.update();

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


void Background::drawGrid( std::vector<ParticleA> &fieldLayerContainer, int offset, float size )
{
	int SPACING = 40;

	int COLUMNS = (cinder::app::getWindowWidth() / SPACING) + 2;
	int ROWS = (cinder::app::getWindowHeight()  / SPACING) + 2;

	
	//fieldLayerContainer.clear();

	for( int j=0; j<ROWS; j++ ){
		for( int i=0; i<COLUMNS; i++ ){

			ParticleA particle = ParticleA();
			particle.init();
			particle.setBounds( 0, getWindowWidth(), 0, getWindowHeight() );
			particle.width = size;//1.5;//andFloat(2,6);
	
			particle.x = ( i*SPACING ) + offset;
			particle.y = ( j*SPACING ) + offset;

			//particle.setBounce(-1);
			particle.setMaxSpeed(10);
			//particle.setEdgeBehavior("wrap");

			//particle.setWander(3);
			particle.setGrav(0);
			particle.addSpringPoint( particle.x, particle.y, 0.01 ); // FORCES THE PARTICLE INTO POSITION

			/*
			for (int i=0; i<repelClips.size(); i++){

				if(i==3){
					particle.addRepelClip( repelClips[i], 175, 175 );
				}else{
					particle.addRepelClip( repelClips[i], 50, 70 );
				}
			}
			*/
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


	// draw the firefly
	// ff.draw();


	gl::enableAlphaBlending();
	gl::color( 1, 1, 1, 0.8 );

	for( vector<ParticleA>::iterator p3 = gridLayer3.begin(); p3 != gridLayer3.end(); ++p3 ){
		float rad = p3->width + (p3->getVx()+p3->getVy())/5 * 2;
		Rectf rect = Rectf(p3->x-2 - p3->width - rad, p3->y-2 - p3->width - rad,p3->x-2 + p3->width + rad, p3->y-2 + p3->width + rad);
		gl::draw(*particleTexture,rect);
	}


	gl::color( 1, 1, 1, 0.7 );
	gl::pushMatrices();
	gl::translate(0,0,-15);
	
	for( vector<ParticleA>::iterator p2 = gridLayer2.begin(); p2 != gridLayer2.end(); ++p2 ){
		float rad = p2->width + (p2->getVx()+p2->getVy())/5 * 4;
		Rectf rect = Rectf(p2->x+2 - p2->width - rad, p2->y+2 - p2->width - rad,p2->x+2 + p2->width + rad, p2->y+2 + p2->width + rad);
		gl::draw(*particleTexture,rect);
	}
	gl::popMatrices();

	
	gl::color( 1, 1, 1, 0.6 );
	gl::pushMatrices();
	gl::translate(0,0,-30);
	
	for( vector<ParticleA>::iterator p = gridLayer1.begin(); p != gridLayer1.end(); ++p ){
		float rad = p->width + (p->getVx()+p->getVy())/5;
		Rectf rect = Rectf(p->x - p->width - rad, p->y - p->width - rad,p->x + p->width + rad, p->y + p->width + rad);
		gl::draw(*particleTexture,rect);
	}

	gl::popMatrices();
}
