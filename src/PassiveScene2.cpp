#include "PassiveScene2.h"
#include "boost/bind.hpp"
#include "cinder/Timeline.h"
#include "cinder/Tween.h"
#include "cinder/Easing.h"
#include "ColorConstants.h"

PassiveScene2::PassiveScene2()
{
	_id = 2; // for boost signal
}

void PassiveScene2::setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles )
{
	font = &thefont;
	iconFactory =  &theIconFactory;
	fgParticles = &thefgParticles;

	fgParticles->destroy();//hide();


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


	
	placeMark5 = IconRenderer();
	placeMark5.setPoints(iconFactory->getPointsForIcon(IconFactory::LOCATION_PIN) );
	placeMark5.pos = Vec2f(700,-200);
	placeMark5.scale = 1.2;
	
	placeMarks.push_back(&placeMark5);

	placeMark6 = IconRenderer();
	placeMark6.setPoints(iconFactory->getPointsForIcon(IconFactory::LOCATION_PIN) );
	placeMark6.pos = Vec2f(300,-200);
	placeMark6.scale = 1.2;
	
	placeMarks.push_back(&placeMark6);

	mCue = timeline().add( bind(&PassiveScene2::showFrame2, this), timeline().getCurrentTime() + 5 );
}

void PassiveScene2::showFrame2()
{
	font->clear();
	font->setPosition(200.0,100.0);
	font->setColor(Color(1.0,1.0,1.0));
	font->addLine( "4GEE IS HERE", 3 );
	font->addLine( "   IS HERE", 4 );
	font->animateIn();

	cinder::app::timeline().apply(&placeMark1.pos,ci::Vec2f(placeMark1.pos.value().x,554.0), 3.0f ,cinder::EaseOutBounce());
	cinder::app::timeline().apply(&placeMark2.pos,ci::Vec2f(placeMark2.pos.value().x,450.0), 2.0f ,cinder::EaseOutBounce());
	cinder::app::timeline().apply(&placeMark3.pos,ci::Vec2f(placeMark3.pos.value().x,500.0), 4.5f ,cinder::EaseOutBounce());
	cinder::app::timeline().apply(&placeMark4.pos,ci::Vec2f(placeMark4.pos.value().x,550.0), 5.0f ,cinder::EaseOutBounce());
	cinder::app::timeline().apply(&placeMark5.pos,ci::Vec2f(placeMark5.pos.value().x,400.0), 5.0f ,cinder::EaseOutBounce());
	cinder::app::timeline().apply(&placeMark6.pos,ci::Vec2f(placeMark6.pos.value().x,350.0), 5.0f ,cinder::EaseOutBounce());

	
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
	font->setPosition(400.0,400.0);
	font->setColor(Color(ColorConstants::PRIMARY_YELLOW.r,ColorConstants::PRIMARY_YELLOW.g, ColorConstants::PRIMARY_YELLOW.b));
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
	font->setPosition(200.0,100.0);
	font->setColor(Color(1.0,1.0,1.0));
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
	//locationLabel.draw();
}