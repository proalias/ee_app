#include "FireFlyEffect.h"

#include "cinder/app/AppBasic.h"
#include "cinder/Utilities.h"
#include "cinder/Rand.h"

#include "Vect.h"
#include "FireFlyParticleController.h"

#include <math.h>

using namespace ci;
using namespace ci::app;
using namespace std;


FireFlyEffect::FireFlyEffect()
{
	// init vars
	/*
	waveStartScheme.push_back( FireFlyWaveScheme( "01" , {2, 3} ) );
	waveStartScheme.push_back( FireFlyWaveScheme( "01", std::vector<int>( 2, 3 ) ) );
	waveStartScheme.push_back( FireFlyWaveScheme( "10", std::vector<int>( 2, 3 ) ) );
	waveStartScheme.push_back( FireFlyWaveScheme( "23", std::vector<int>( 0, 1 ) ) );
	waveStartScheme.push_back( FireFlyWaveScheme( "32", std::vector<int>( 0, 1 ) ) );
	waveStartScheme.push_back( FireFlyWaveScheme( "02", std::vector<int>( 1, 3, 7 ) ) );
	waveStartScheme.push_back( FireFlyWaveScheme( "20", std::vector<int>( 1, 3, 7 ) ) );
	waveStartScheme.push_back( FireFlyWaveScheme( "03", std::vector<int>( 1, 2, 5 ) ) );
	waveStartScheme.push_back( FireFlyWaveScheme( "30", std::vector<int>( 1, 2, 5 ) ) );
	waveStartScheme.push_back( FireFlyWaveScheme( "31", std::vector<int>( 0, 2, 4 ) ) );
	waveStartScheme.push_back( FireFlyWaveScheme( "13", std::vector<int>(  0, 2, 4 ) ) );
	waveStartScheme.push_back( FireFlyWaveScheme( "12", std::vector<int>(  0, 3, 6 ) ) );
	waveStartScheme.push_back( FireFlyWaveScheme( "21", std::vector<int>(  0, 3, 6 ) ) );
	waveStartScheme.push_back( FireFlyWaveScheme( "0-1", std::vector<int>(  1, 2, 3, 5, 7 ) ) );
	waveStartScheme.push_back( FireFlyWaveScheme( "1-1", std::vector<int>(  0, 2, 3, 4, 6 ) ) );
	waveStartScheme.push_back( FireFlyWaveScheme( "2-1", std::vector<int>(  0, 1, 3, 6, 7 ) ) );
	waveStartScheme.push_back( FireFlyWaveScheme( "3-1", std::vector<int>(  0, 1, 2, 4, 5 ) ) );

	waveScheme = [[0],[1],[2],[3],[0,2,4],[1,2,5],[0,3,6],[1,3,7]];	
	neighborOrder = [1,0,3,2,7,6,5,4];
	*/

	_spriteScale = 1;
	_delayNewFireFly = 0;
	_count = 0;
	_maxCount = 5;

	// TODO - no need for listeners as we have a reference and vice versa
	//this.addEventListener(FireFlyParticleController.FIREFLY_ENTERED, increment);
	//this.addEventListener(FireFlyParticleController.FIREFLY_LEFT, decrement);
}


void FireFlyEffect::createGrid()
{
	int SPACING = 40;

	int COLUMNS = cinder::app::getWindowWidth()/SPACING;
	int ROWS = cinder::app::getWindowHeight()/SPACING; // TODO - make global and pass to firefly
	
	int count = 0;		
	for( int j=0; j<COLUMNS; j++ ) {
		for( int i=0; i<ROWS; i++ ) {
			FireFlyParticleController ff = FireFlyParticleController( i, j, Vect( i*SPACING, j*SPACING), count, ROWS, COLUMNS ) ;
			particles.push_back( ff );	
			count++;
		}
	}

	// add all the refs
	for( vector<FireFlyParticleController>::iterator ffp = particles.begin(); ffp != particles.end(); ++ffp ){
		ffp->setParticles( particles );
	}

}


void FireFlyEffect::update()
{

	int i = 0; 
	int j = 0; 
			
	FireFlyParticle particle;
			
	for (i = particles.size()-1; i >= 0; i--)
	{
		FireFlyParticleController controller  = particles[i];
		particle = controller.particle;
				
		controller.applyFade();
				
		if (!controller.isOccupied) {
			controller.setParticleFollow();
		}					
				
		if (particle.isActive) {
			particle.applyShuffle();						
		}
				
		controller.repel();
		if (!controller.isRepelling) {
			controller.resetGrid();	
		}
			
		/*
		for (j = activeParticles.size()-1; j >=0; j--)
		{
			if (controller.index == activeParticles[j]->index) {	
				//activeParticles.shift().checkPath();	// TODO - replacement for shift
				break;
			}
		}
				
		for (j = waveParticles.size()-1; j >=0; j--)
		{
			if (controller.index == waveParticles[j]->index) {
				//waveParticles.shift().makeWave(); TODO -
				break;						
			}
		}
		*/

		particle.update();			
	}
			

	
	if( _delayNewFireFly > 100 )
	{
		_delayNewFireFly=0;
		// create a random trail if one is finished
			
		int len = particles.size();; 
			
		if ( (_count < _maxCount) && len) {						
			FireFlyParticleController randomParticle = particles[floor(Rand::randFloat(len))];
					
			if (!randomParticle.isActive && !randomParticle.particle.isWave && randomParticle.isOccupied && !randomParticle.particle.isActive) {
				randomParticle.startShuffle();							
			}	
		}
	}
			
	_delayNewFireFly++;
}

void FireFlyEffect::increment()
{
	if (_count < _maxCount) {
		_count++;
	}
}
		
void FireFlyEffect::decrement()
{
	if (_count > 0) {
		_count--;
	}
}

void FireFlyEffect::draw()
{
	// loop through and draw
//	for( int i = particles.size()-1; i >= 0; i--)
//	{
//		FireFlyParticleController controller  = particles[i];
//		controller.draw();
//	}

		// TODO - may be passing foreground particles into scenes. but still probs drawn here
	for( vector<FireFlyParticleController>::iterator p = particles.begin(); p != particles.end(); ++p ){
		gl::drawSolidCircle( Vec2f( p->x, p->y ), 2 );
	}
}