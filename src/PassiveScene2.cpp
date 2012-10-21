#include "PassiveScene2.h"
#include "boost/bind.hpp"
#include "cinder/Timeline.h"
#include "cinder/Tween.h"
#include "cinder/Easing.h"

PassiveScene2::PassiveScene2()
{
	_id = "PassiveScene2"; // for boost signal
}

void PassiveScene2::setup( FontRenderer &thefont, IconFactory &theIconFactory )
{
	
	font = &thefont;
	font->clear();
	//font->addLine( "4GEE IS HERE", 3 );
	//font->addLine( "   IS HERE", 4 );

	font->addLine( "SUPERFAST", 3 );
	font->addLine( "      MOBILE #4GEE", 3 );
	font->addLine( "ONLY ON EE", 3 );

	//_signal( this );
	iconFactory =  &theIconFactory;


	// show pin icons
	placeMark1 = IconRenderer();
	placeMark1.setPoints(iconFactory->getPointsForIcon(IconFactory::LOCATION_PIN) );
	placeMark1.pos = Vec2f(150.0,-200);
	placeMark1.scale  = 2;
	
	placeMarks.push_back(&placeMark1);


	placeMark2 = IconRenderer();
	placeMark2.setPoints(iconFactory->getPointsForIcon(IconFactory::LOCATION_PIN) );
	placeMark2.pos = Vec2f(400.0,-200);
	placeMark2.scale = 1;
	
	placeMarks.push_back(&placeMark2);

	
	placeMark3 = IconRenderer();
	placeMark3.setPoints(iconFactory->getPointsForIcon(IconFactory::LOCATION_PIN) );
	placeMark3.pos = Vec2f(750.0,-200.0);
	placeMark3.scale = 0.5;
	
	placeMarks.push_back(&placeMark3);

	
	placeMark4 = IconRenderer();
	placeMark4.setPoints(iconFactory->getPointsForIcon(IconFactory::LOCATION_PIN) );
	placeMark4.pos = Vec2f(900,-200);
	placeMark4.scale = 1.2;
	
	placeMarks.push_back(&placeMark4);


	// TODO - get the name of the city from the config file
	FontRenderer locationLabel =  FontRenderer();
	locationLabel.addLine("LONDON",3);
	// font->addLine( "LONDON", 3 );



	phase = 0;

	animationTimer.start();

	
}

void PassiveScene2::update(Timeline &timeline)
{
	if(phase == 0){
		phase = 1;
		font->animateIn();

		
		cinder::app::timeline().apply(&placeMark1.pos,ci::Vec2f(placeMark1.pos.value().x,604.0), 3.0f ,cinder::EaseOutBounce());
		cinder::app::timeline().apply(&placeMark2.pos,ci::Vec2f(placeMark2.pos.value().x,500.0), 2.0f ,cinder::EaseOutBounce());
		cinder::app::timeline().apply(&placeMark3.pos,ci::Vec2f(placeMark3.pos.value().x,550.0), 4.5f ,cinder::EaseOutBounce());
		cinder::app::timeline().apply(&placeMark4.pos,ci::Vec2f(placeMark4.pos.value().x,600.0), 5.0f ,cinder::EaseOutBounce());

	} 

	if(animationTimer.getSeconds()>20 && phase == 1){
		phase = 2;
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


void PassiveScene2::animateIn(){

}

void PassiveScene2::animateOut(){

}


void PassiveScene2::draw()
{
	for (int i = 0; i < placeMarks.size(); i++){
		placeMarks[i]->draw();
	}
	locationLabel.draw();
}