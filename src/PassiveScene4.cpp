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
	arrow1.xPos = 300;
	arrow1.yPos = 400;
	arrow1.xScale = arrow1.yScale = 2;
	
	arrows.push_back(&arrow1);


	arrow2 = IconRenderer();
	arrow2.setPoints(iconFactory->getPointsForIcon(IconFactory::ARROW) );
	arrow2.xPos = 100;
	arrow2.yPos = 600;
	arrow2.xScale = arrow2.yScale = 1;
	
	arrows.push_back(&arrow2);

	
	arrow3 = IconRenderer();
	arrow3.setPoints(iconFactory->getPointsForIcon(IconFactory::ARROW) );
	arrow3.xPos = 500;
	arrow3.yPos = 700;
	arrow3.xScale = arrow3.yScale = 0.5;
	
	arrows.push_back(&arrow3);

	
	arrow4 = IconRenderer();
	arrow4.setPoints(iconFactory->getPointsForIcon(IconFactory::ARROW) );
	arrow4.xPos = ci::app::getWindowWidth() + 100;
	arrow4.yPos = 600;
	arrow4.xScale = arrow4.yScale = 1.2;
	
	arrows.push_back(&arrow4);



	phase = 0;
	animationTimer.start();
}

void PassiveScene4::update()
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