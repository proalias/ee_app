#include "PassiveScene2.h"
#include "boost/bind.hpp"

PassiveScene2::PassiveScene2()
{
	_id = "PassiveScene2"; // for boost signal
}

void PassiveScene2::setup( FontRenderer &thefont, IconFactory &theIconFactory )
{
	// show pin icons

	font = &thefont;
	font->clear();
	//font->addLine( "4GEE IS HERE", 3 );
	//font->addLine( "   IS HERE", 4 );

	font->addLine( "SUPERFAST", 3 );
	font->addLine( "      MOBILE #4GEE", 3 );
	font->addLine( "ONLY ON EE", 3 );

	//_signal( this );
	iconFactory =  &theIconFactory;

	placeMark1 = IconRenderer();
	placeMark1.setPoints(iconFactory->getPointsForIcon(IconFactory::LOCATION_PIN) );
	placeMark1.xPos = 200;
	placeMark1.yPos = 800;
	placeMark1.xScale = placeMark1.yScale = 2;
	
	placeMarks.push_back(&placeMark1);


	placeMark2 = IconRenderer();
	placeMark2.setPoints(iconFactory->getPointsForIcon(IconFactory::LOCATION_PIN) );
	placeMark2.xPos = 100;
	placeMark2.yPos = 600;
	placeMark2.xScale = placeMark2.yScale = 1;
	
	placeMarks.push_back(&placeMark2);

	
	placeMark3 = IconRenderer();
	placeMark3.setPoints(iconFactory->getPointsForIcon(IconFactory::LOCATION_PIN) );
	placeMark3.xPos = 500;
	placeMark3.yPos = 700;
	placeMark3.xScale = placeMark3.yScale = 0.5;
	
	placeMarks.push_back(&placeMark3);

	
	placeMark4 = IconRenderer();
	placeMark4.setPoints(iconFactory->getPointsForIcon(IconFactory::LOCATION_PIN) );
	placeMark4.xPos = 800;
	placeMark4.yPos = 600;
	placeMark4.xScale = placeMark4.yScale = 1.2;
	
	placeMarks.push_back(&placeMark4);


	// TODO - get the name of the city from the config file
	// font->addLine( "LONDON", 3 );



	phase = 0;

	animationTimer.start();

	
}

void PassiveScene2::update()
{
	if(phase == 0){
		phase = 1;
		font->animateIn();
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
}