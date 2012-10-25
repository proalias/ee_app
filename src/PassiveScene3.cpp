#include "PassiveScene3.h"
#include "boost/lambda/bind.hpp"

PassiveScene3::PassiveScene3()
{
	_id = 3; // for boost signal

	isFrame2=false;

	alphaValue=0.7;

	leftShift=4;
	
	gridSpeed=1.1;
	gridZ = 0;
}

void PassiveScene3::setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles, std::vector<ParticleA> &thegridLayer )
{
	font = &thefont;
	font->clear();
	font->setPosition(200,100);
	font->setColor(Color(1.0,1.0,1.0));
	font->addLine( "PREPARE TO GO", 3 );
	font->addLine( "         SUPERFAST", 3 );
	font->animateIn();

	iconFactory =  &theIconFactory;

	fgParticles = &thefgParticles;


	//fgParticles->mParticles.clear();

	//if(fgParticles->mParticles.size()<1){
	//	fgParticles->setup( 100 );
	//}
	fgParticles->hide();


	particleTexture = TextureGlobals::getInstance()->getParticleTexture(6);
	otherParticleTexture = TextureGlobals::getInstance()->getParticleTexture(5);
	
	gridLayer = &thegridLayer;

	gridSpeed=0.1;
	particleSpeed=0;

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


	mCue = timeline().add( boost::lambda::bind(&PassiveScene3::showFrame2, this), timeline().getCurrentTime() + 12 );
}

void PassiveScene3::showFrame2(){

	isFrame2=true;
	fgParticles->overrideDrawMethodInScene = true;
	font->animateOut();
	mCue = timeline().add( boost::lambda::bind(&PassiveScene3::showFrame3, this), timeline().getCurrentTime() + 6 );
}

void PassiveScene3::showFrame3(){
	
	isFrame2=false;
	font->clear();
	font->setPosition(300,100);
	font->setColor(Color(1.0,1.0,1.0));

	font->addLine( "WITH SUPERFAST", 2 );
	font->addLine( "      #4GEE AND", 2 );
	font->addLine( "      FIBRE BROADBAND", 2 );
	font->animateIn();

	mCue = timeline().add( boost::lambda::bind(&PassiveScene3::showFrame4, this), timeline().getCurrentTime() + 10 );
}

void PassiveScene3::showFrame4(){
	
	fgParticles->overrideDrawMethodInScene = false;
	fgParticles->show();
	_signal(this);

	font->animateOut();
	mCue = timeline().add( boost::lambda::bind(&PassiveScene3::showFrame5, this), timeline().getCurrentTime() + 5 );
}

void PassiveScene3::showFrame5(){
	//fgParticles.over
	
}

void PassiveScene3::update()
{
	
}

void PassiveScene3::draw()
{
	
	//if(gridSpeed){
	//	alphaValue;
	//}

	if(isFrame2)
	{
		//alphaValue-=0.08;

		// ZOOM THE GRID
		if (gridSpeed < 33.0){
			gridSpeed = gridSpeed * 3.5f;
		}

		gridZ += gridSpeed;
	


		for( int i=0; i<4; i++ ){
			gl::color( 1, 1, 1, 0.7 );
			gl::pushMatrices();
			float speed = int(gridSpeed)%100;
			float tZ = (int(gridZ) % 100) + i*12;
			gl::translate( 0, 0, tZ);
		
			int count=0;

			for( vector<ParticleA>::iterator p = gridLayer->begin(); p != gridLayer->end(); ++p ){

				if( (count<320)||(count>325) )
				{
					float rad = p->width + (p->getVx()+p->getVy())/5;
					Rectf rect = Rectf(p->x - p->width - rad, p->y - p->width - rad,p->x + p->width + rad, p->y + p->width + rad);
					gl::draw( *particleTexture, rect );
				}
				else
				{
					float rad = p->width + (p->getVx()+p->getVy())/5;
					
					Rectf rect = Rectf(p->x - p->width - rad, p->y - p->width - rad,p->x + p->width + rad, p->y + p->width + rad);
					//Rectf rect = Rectf(xpos - rad*2 + xJitter, ypos - rad*2 + yJitter,xpos+rad*2 + xJitter, ypos+rad*2+ yJitter);
					gl::draw(*TextureGlobals::getInstance()->getParticleTexture(0),rect);
				}
				count++;
			}
			gl::popMatrices();
		}
	

		//if(gridSpeed>150)
	//	{
			// ZOOM INDIVIDUAL PARTICLES
			particleSpeed +=10;

			gl::color( 1, 1, 1, 0.4 );
			gl::pushMatrices();
			gl::translate(0,0,particleSpeed);
	
			//if(i==0){
	
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
			
			//gl::translate(0,0,testVar*i);

			for( list<ParticleA>::iterator p = localParticles.begin(); p != localParticles.end(); ++p ){		
				Rectf rect = Rectf(p->x - p->width, p->y - p->width, p->x + p->width, p->y + p->width);
				gl::draw( *otherParticleTexture, rect ); // TODO - change for the foreground texture
				//gl::drawSolidCircle( Vec2f( p->x, p->y ), p->width );
			}

			gl::popMatrices();	
	//	}

	}



}