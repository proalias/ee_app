#include "PassiveScene2.h"
#include "boost/bind.hpp"

PassiveScene2::PassiveScene2()
{
	_id = "PassiveScene2"; // for boost signal
}

void PassiveScene2::setup( FontRenderer &thefont, IconFactory &theIconFactory )
{
	font = &thefont;
	font->clear();

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

	
	mCue = timeline().add( bind(&PassiveScene2::showFrame2, this), timeline().getCurrentTime() + 5 );
}

void PassiveScene2::showFrame2()
{
	font->clear();
	font->addLine( "4GEE IS HERE", 3 );
	font->addLine( "   IS HERE", 4 );
	font->animateIn();

	mCue = timeline().add( bind(&PassiveScene2::showFrame3, this), timeline().getCurrentTime() + 6 );
}

void PassiveScene2::showFrame3()
{
	font->animateOut();
	mCue = timeline().add( bind(&PassiveScene2::showFrame4, this), timeline().getCurrentTime() + 3 );
}

void PassiveScene2::showFrame4()
{
	font->clear();
	// TODO - yellow
	// TODO - get the actual city name from the config
	font->addLine( "LONDON", 3 );
	font->animateIn();
	mCue = timeline().add( bind(&PassiveScene2::showFrame5, this), timeline().getCurrentTime() + 3 );
}

void PassiveScene2::showFrame5()
{
	font->animateOut();
	mCue = timeline().add( bind(&PassiveScene2::showFrame6, this), timeline().getCurrentTime() + 3 );
}

void PassiveScene2::showFrame6()
{
	font->clear();
	font->addLine( "SUPERFAST", 3 );
	font->addLine( "      MOBILE #4GEE", 3 );
	font->addLine( "ONLY ON EE", 3 );
	font->animateIn();
	mCue = timeline().add( bind(&PassiveScene2::showFrame7, this), timeline().getCurrentTime() + 10 );
}

void PassiveScene2::showFrame7()
{
	font->animateOut();
	mCue = timeline().add( bind(&PassiveScene2::showFrame8, this), timeline().getCurrentTime() + 3 );
}

void PassiveScene2::showFrame8()
{
	_signal( this );
}

void PassiveScene2::update()
{
}

void PassiveScene2::draw()
{
	for (int i = 0; i < placeMarks.size(); i++){
		placeMarks[i]->draw();
	}
}