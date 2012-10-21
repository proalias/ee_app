#include "PassiveScene4.h"
#include "boost/bind.hpp"

PassiveScene4::PassiveScene4()
{
	_id = "PassiveScene4"; // for boost signal
}

void PassiveScene4::setup( FontRenderer &thefont, IconFactory &theIconFactory )
{
	font = &thefont;
	font->clear();
	font->addLine( " ", 3 );
	font->addLine( "COME IN", 3 );
	font->addLine( "      AND SEE US", 3 );

	
	iconFactory =  &theIconFactory;

	arrow1 = IconRenderer();
	arrow1.setPoints(iconFactory->getPointsForIcon(IconFactory::ARROW) );
	arrow1.pos = Vec2f(1400,400);
	arrow1.scale = 2;
	
	arrows.push_back(&arrow1);


	arrow2 = IconRenderer();
	arrow2.setPoints(iconFactory->getPointsForIcon(IconFactory::ARROW) );
	arrow2.pos = Vec2f(1400,600);
	arrow2.scale = 1;
	
	arrows.push_back(&arrow2);

	
	arrow3 = IconRenderer();
	arrow3.setPoints(iconFactory->getPointsForIcon(IconFactory::ARROW) );
	arrow3.pos = Vec2f(1200,700);
	arrow3.scale = 0.5;
	
	arrows.push_back(&arrow3);

	
	arrow4 = IconRenderer();
	arrow4.setPoints(iconFactory->getPointsForIcon(IconFactory::ARROW) );
	arrow4.pos = Vec2f(1600,600);
	arrow4.scale = 1.2;
	
	arrows.push_back(&arrow4);



	phase = 0;
	animationTimer.start();
}

void PassiveScene4::update(ci::Timeline &timeline)
{
	if(phase == 0){
		phase = 1;
		font->animateIn();
		
	
		cinder::app::timeline().apply(&arrow1.pos,Vec2f(1400,400),ci::Vec2f(-300.0,arrow1.pos.value().y), 3.0f ,cinder::EaseInExpo());
		cinder::app::timeline().apply(&arrow2.pos,Vec2f(1400,600),ci::Vec2f(-300.0,arrow2.pos.value().y), 2.0f ,cinder::EaseInExpo());
		cinder::app::timeline().apply(&arrow3.pos,Vec2f(1200,700),ci::Vec2f(-300.0,arrow3.pos.value().y), 4.0f ,cinder::EaseInExpo());
		cinder::app::timeline().apply(&arrow4.pos,Vec2f(1600,600),ci::Vec2f(-300.0,arrow4.pos.value().y), 5.0f ,cinder::EaseInExpo());
	}

	if(animationTimer.getSeconds()>20 && phase == 1){
		phase = 2;

		cinder::app::timeline().apply(&arrow1.pos,Vec2f(1400,400),ci::Vec2f(-300.0,arrow1.pos.value().y), 3.0f ,cinder::EaseInExpo());
		cinder::app::timeline().apply(&arrow2.pos,Vec2f(1400,600),ci::Vec2f(-300.0,arrow2.pos.value().y), 2.0f ,cinder::EaseInExpo());
		cinder::app::timeline().apply(&arrow3.pos,Vec2f(1200,700),ci::Vec2f(-300.0,arrow3.pos.value().y), 4.0f ,cinder::EaseInExpo());
		cinder::app::timeline().apply(&arrow4.pos,Vec2f(1600,600),ci::Vec2f(-300.0,arrow4.pos.value().y), 5.0f ,cinder::EaseInExpo());


		// test dispatching event
		//_signal( this );
		font->animateOut();
		//font->clear();
		//font->addLine( "end scene 3", 3 );
	}
	if(animationTimer.getSeconds()>25 && phase ==2){
		phase = 3;
		animationTimer.stop();
		animationTimer = Timer(); // reset the timer
		
		_signal( this );
	}
}


void PassiveScene4::animateIn(){

}

void PassiveScene4::animateOut(){

}


void PassiveScene4::draw()
{
	for (int i = 0; i < arrows.size(); i++){
		arrows[i]->draw();
	}
}