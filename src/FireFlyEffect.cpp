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
	
	int a[] = {2,3};
	waveStartScheme.push_back( FireFlyWaveScheme( "01", std::vector<int>( a, a+(sizeof(a)/sizeof(a[0])) )) );
	
	int b[] = {2,3};
	waveStartScheme.push_back( FireFlyWaveScheme( "10", std::vector<int>( b, b+(sizeof(b)/sizeof(b[0])) )) );

	int c[] = {0,1};
	waveStartScheme.push_back( FireFlyWaveScheme( "23", std::vector<int>( c, c+(sizeof(c)/sizeof(c[0])) )) );

	int d[] = {0,1};
	waveStartScheme.push_back( FireFlyWaveScheme( "32", std::vector<int>( d, d+(sizeof(d)/sizeof(d[0])) )) );
	
	int e[] = {1,3,7};
	waveStartScheme.push_back( FireFlyWaveScheme( "02", std::vector<int>( e, e+(sizeof(e)/sizeof(e[0])) )) );

	int f[] = {1,3,7};
	waveStartScheme.push_back( FireFlyWaveScheme( "20", std::vector<int>( f, f+(sizeof(f)/sizeof(f[0])) )) );

	int g[] = {1,2,5};
	waveStartScheme.push_back( FireFlyWaveScheme( "03", std::vector<int>( g, g+(sizeof(g)/sizeof(g[0])) )) );

	int h[] = {1,2,5};
	waveStartScheme.push_back( FireFlyWaveScheme( "30", std::vector<int>( h, h+(sizeof(h)/sizeof(h[0])) )) );

	int i[] = {0,2,4};
	waveStartScheme.push_back( FireFlyWaveScheme( "31", std::vector<int>( i, i+(sizeof(i)/sizeof(i[0])) )) );

	int j[] = {0,2,4};
	waveStartScheme.push_back( FireFlyWaveScheme( "13", std::vector<int>( j, j+(sizeof(j)/sizeof(j[0])) )) );

	int k[] = {0,3,6};
	waveStartScheme.push_back( FireFlyWaveScheme( "12", std::vector<int>( k, k+(sizeof(k)/sizeof(k[0])) )) );

	int l[] = {0,3,6};
	waveStartScheme.push_back( FireFlyWaveScheme( "21", std::vector<int>( l, l+(sizeof(l)/sizeof(l[0])) )) );

	int m[] = {1, 2, 3, 5, 7};
	waveStartScheme.push_back( FireFlyWaveScheme( "0-1", std::vector<int>( m, m+(sizeof(m)/sizeof(m[0])) )) );

	int n[] = { 0, 2, 3, 4, 6 };
	waveStartScheme.push_back( FireFlyWaveScheme( "1-1", std::vector<int>( n, n+(sizeof(n)/sizeof(n[0])) )) );

	int o[] = { 0, 1, 3, 6, 7 };
	waveStartScheme.push_back( FireFlyWaveScheme( "2-1", std::vector<int>( o, o+(sizeof(o)/sizeof(o[0])) )) );

	int p[] = { 0, 1, 2, 4, 5 };
	waveStartScheme.push_back( FireFlyWaveScheme( "3-1", std::vector<int>( p, p+(sizeof(p)/sizeof(p[0])) )) );

	/*
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

	int ROWS = cinder::app::getWindowHeight()/SPACING; // TODO - make global and pass to firefly
	int COLUMNS = cinder::app::getWindowWidth()/SPACING;

	
	int count = 0;		
	for( int j=0; j<ROWS; j++ ) {
		for( int i=0; i<COLUMNS; i++ ) {
			FireFlyParticleController ff = FireFlyParticleController( i, j, Vect( i*SPACING, j*SPACING), count, ROWS, COLUMNS ) ;
			particles.push_back( ff );	
			count++;
		}
	}

	// add all the refs
	for( vector<FireFlyParticleController>::iterator ffp = particles.begin(); ffp != particles.end(); ++ffp ){
		ffp->setParticles( particles );
		ffp->setActiveParticles( activeParticles );
		ffp->setWaveParticles( waveParticles );
	}

}


void FireFlyEffect::update()
{

	int i = 0; 
	int j = 0; 
			
	//FireFlyParticle particle;
			
	for (i = particles.size()-1; i >= 0; i--)
	{
		FireFlyParticleController controller = particles[i];
		FireFlyParticle particle = controller.particle;

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
		
		for (j = activeParticles.size()-1; j >=0; j--){
			if (controller.index == activeParticles[j].index) {	
				activeParticles[0].checkPath();
				activeParticles.erase(activeParticles.begin());
				break;
			}
		}
				
		for (j = waveParticles.size()-1; j >=0; j--){
			if (controller.index == waveParticles[j].index) {
				waveParticles[0].checkPath();
				waveParticles.erase(activeParticles.begin());
				break;						
			}
		}


		particle.update();			
	}
			

	
	if( _delayNewFireFly > 100 )
	{
		_delayNewFireFly=0;
		// create a random trail if one is finished
			
		int len = particles.size();
			
		if ( (_count < _maxCount) && len) {						
			FireFlyParticleController randomParticle = particles[floor(Rand::randFloat(len))];

			if (!randomParticle.isActive && !randomParticle.particle.isWave && randomParticle.isOccupied && !randomParticle.particle.isActive) {
				randomParticle.startShuffle();							
			}	
		}
	}
			
	_delayNewFireFly++;
	
}

void FireFlyEffect::increment(){
	if (_count < _maxCount) {
		_count++;
	}
}
		
void FireFlyEffect::decrement(){
	if (_count > 0) {
		_count--;
	}
}

void FireFlyEffect::draw()
{
	for( vector<FireFlyParticleController>::iterator p = particles.begin(); p != particles.end(); ++p ){
		//gl::drawSolidCircle( Vec2f( p->x*20, p->y*20 ), 3 );
		p->particle.draw();
	}
}