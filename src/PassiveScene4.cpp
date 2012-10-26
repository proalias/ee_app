#include "PassiveScene4.h"
#include "boost/lambda/bind.hpp"

PassiveScene4::PassiveScene4()
{
	_id = 4; // for boost signal
}

void PassiveScene4::setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles, std::vector<ParticleA> &thegridLayer )
{
	font = &thefont;

	font->clear();
	font->setPosition(300,100);
	font->setColor(Color(1.0,1.0,1.0));

	font->addLine( "COME IN", 4 );
	font->addLine( "    AND SEE US", 4 );
	font->animateIn();
	
	iconFactory =  &theIconFactory;

	fgParticles = &thefgParticles;
	//fgParticles->destroy(); // TODO - call hide not destroy
	fgParticles->show();

	arrow1 = IconRenderer();
	arrow1.setPoints(iconFactory->getPointsForIcon(IconFactory::ARROW) );
	arrow1.pos = Vec2f(1600,450);
	arrow1.scale = 2;
	
	arrows.push_back(&arrow1);


	arrow2 = IconRenderer();
	arrow2.setPoints(iconFactory->getPointsForIcon(IconFactory::ARROW) );
	arrow2.pos = Vec2f(1600,600);
	arrow2.scale = 1;
	
	arrows.push_back(&arrow2);

	
	arrow3 = IconRenderer();
	arrow3.setPoints(iconFactory->getPointsForIcon(IconFactory::ARROW) );
	arrow3.pos = Vec2f(1600,700);
	arrow3.scale = 0.5;
	
	arrows.push_back(&arrow3);

	
	arrow4 = IconRenderer();
	arrow4.setPoints(iconFactory->getPointsForIcon(IconFactory::ARROW) );
	arrow4.pos = Vec2f(1600,600);
	arrow4.scale = 1.2;
	
	arrows.push_back(&arrow4);
	
	
	arrow5 = IconRenderer();
	arrow5.setPoints(iconFactory->getPointsForIcon(IconFactory::ARROW) );
	arrow5.pos = Vec2f(1600,50);
	arrow5.scale = 1.0;
	
	arrows.push_back(&arrow5);

	cinder::app::timeline().apply(&arrow1.pos,Vec2f(1600,450),ci::Vec2f(-300.0,arrow1.pos.value().y), 6.0f ,cinder::EaseInExpo()).loop(true);
	cinder::app::timeline().apply(&arrow2.pos,Vec2f(1600,600),ci::Vec2f(-300.0,arrow2.pos.value().y), 4.0f ,cinder::EaseInExpo()).loop(true);
	cinder::app::timeline().apply(&arrow3.pos,Vec2f(1600,700),ci::Vec2f(-300.0,arrow3.pos.value().y), 8.0f ,cinder::EaseInExpo()).loop(true);
	cinder::app::timeline().apply(&arrow4.pos,Vec2f(1600,600),ci::Vec2f(-300.0,arrow4.pos.value().y), 16.0f ,cinder::EaseInExpo()).loop(true);
	cinder::app::timeline().apply(&arrow5.pos,Vec2f(1600,50),ci::Vec2f(-300.0,arrow5.pos.value().y), 10.0f ,cinder::EaseInExpo()).loop(true);

	mCue = timeline().add( boost::lambda::bind(&PassiveScene4::showFrame2, this), timeline().getCurrentTime() + 15 );
}

void PassiveScene4::showFrame2(){
	font->animateOut();
	mCue = timeline().add( boost::lambda::bind(&PassiveScene4::showFrame3, this), timeline().getCurrentTime() + 7 );
	
	for (int i = 0; i < arrows.size(); i++){
		arrows[i]->disperseParticles();
	}

}

void PassiveScene4::showFrame3(){
	_signal( this );
}

void PassiveScene4::showFrame4(){
	//_signal( this );
}



void PassiveScene4::draw(){

	bool doorOnRight = ShopConfig::getInstance()->doorOnRight;
	//some stores have doors on the left, so we need to reverse the direction of the arrows.
	//todo - read orientation from config
	if(doorOnRight == true){
		gl::pushMatrices();
	
		gl::scale( Vec3f(-1, 1, 1) );
		
		gl::translate( Vec2f(-ci::app::getWindowWidth(), 0 ) );
		gl::translate( Vec3f(-1, 1, 1) );
	}
	
	for (int i = 0; i < arrows.size(); i++){
		arrows[i]->draw();
	}

	if(doorOnRight == true){
		gl::popMatrices();
	}

}