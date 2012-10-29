#include "PassiveScene2.h"
#include "boost/lambda/bind.hpp"
#include "cinder/Timeline.h"
#include "cinder/Tween.h"
#include "cinder/Easing.h"
#include "ColorConstants.h"
#include "ShopConfig.h"
#include "cinder\gl\gl.h"

PassiveScene2::PassiveScene2()
{
	_id = 2; // for boost signal
}

void PassiveScene2::setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles, std::vector<ParticleA> &thegridLayer1 )
{
	font = &thefont;
	iconFactory =  &theIconFactory;
	fgParticles = &thefgParticles;

	//fgParticles->destroy();//hide();


	// show pin icons
	placeMark1 = IconRenderer();
	placeMark1.setPoints(iconFactory->getPointsForIcon(IconFactory::LOCATION_PIN) );
	placeMark1.pos = Vec2f(350.0,-200);
	placeMark1.scale  = 2;
	
	placeMarks.push_back(&placeMark1);


	placeMark2 = IconRenderer();
	placeMark2.setPoints(iconFactory->getPointsForIcon(IconFactory::LOCATION_PIN) );
	placeMark2.pos = Vec2f(150.0,-200);
	placeMark2.scale = 0.45;
	
	placeMarks.push_back(&placeMark2);

	/*
	placeMark3 = IconRenderer();
	placeMark3.setPoints(iconFactory->getPointsForIcon(IconFactory::LOCATION_PIN) );
	placeMark3.pos = Vec2f(950.0,-200.0);
	placeMark3.scale = 0.5;
	
	//placeMarks.push_back(&placeMark3);

	
	placeMark4 = IconRenderer();
	placeMark4.setPoints(iconFactory->getPointsForIcon(IconFactory::LOCATION_PIN) );
	placeMark4.pos = Vec2f(700,-200);
	placeMark4.scale = 0.5;
	
	//placeMarks.push_back(&placeMark4);
	*/

	
	placeMark5 = IconRenderer();
	placeMark5.setPoints(iconFactory->getPointsForIcon(IconFactory::LOCATION_PIN) );
	placeMark5.pos = Vec2f(850,-200);
	placeMark5.scale = 0.8;
	
	placeMarks.push_back(&placeMark5);

	placeMark6 = IconRenderer();
	placeMark6.setPoints(iconFactory->getPointsForIcon(IconFactory::LOCATION_PIN) );
	placeMark6.pos = Vec2f(920,-200);
	placeMark6.scale = 0.5;
	
	placeMarks.push_back(&placeMark6);
	
	mCue = timeline().add( boost::lambda::bind(&PassiveScene2::showFrame2, this), timeline().getCurrentTime() + 1 );
}

void PassiveScene2::showFrame2()
{
	font->clear();
	font->setPosition(340.0,200.0);
	font->setColor(Color(1.0,1.0,1.0));
	font->addLine( "4GEE IS HERE", 3 );
	font->animateIn();

	cinder::app::timeline().apply(&placeMark2.pos,ci::Vec2f(placeMark2.pos.value().x,150.0), 2.0f ,cinder::EaseOutBounce(0.4));
	//cinder::app::timeline().apply(&placeMark3.pos,ci::Vec2f(placeMark3.pos.value().x,400.0), 4.5f ,cinder::EaseOutBounce(0.8));
	//cinder::app::timeline().apply(&placeMark4.pos,ci::Vec2f(placeMark4.pos.value().x,750.0), 5.0f ,cinder::EaseOutBounce(0.8));
	cinder::app::timeline().apply(&placeMark5.pos,ci::Vec2f(placeMark5.pos.value().x,460.0), 4.0f ,cinder::EaseOutBounce(0.4));
	cinder::app::timeline().apply(&placeMark6.pos,ci::Vec2f(placeMark6.pos.value().x,150.0), 5.0f ,cinder::EaseOutBounce(0.4));


	mCue = timeline().add( boost::lambda::bind(&PassiveScene2::showFrame3, this), timeline().getCurrentTime() + 6 );
}

void PassiveScene2::showFrame3()
{
	font->animateOut();
	mCue = timeline().add( boost::lambda::bind(&PassiveScene2::showFrame4, this), timeline().getCurrentTime() + 0.2 );
	
}

void PassiveScene2::showFrame4()
{
	font->clear();
	font->setPosition(480.0,520.0);
	font->setColor(Color(ColorConstants::PRIMARY_YELLOW.r,ColorConstants::PRIMARY_YELLOW.g, ColorConstants::PRIMARY_YELLOW.b));
	font->addLine( ShopConfig::getInstance()->location, 2 );
	font->animateIn();
	mCue = timeline().add( bind(&PassiveScene2::showFrame5, this), timeline().getCurrentTime() + 10 );
	cinder::app::timeline().apply(&placeMark1.pos,ci::Vec2f(placeMark1.pos.value().x,630.0), 3.0f ,cinder::EaseOutBounce(0.4));
}

void PassiveScene2::showFrame5()
{
	font->animateOut();
	mCue = timeline().add( boost::lambda::bind(&PassiveScene2::showFrame6, this), timeline().getCurrentTime() + 1 );
}

void PassiveScene2::showFrame6()
{
	font->clear();
	font->setPosition(350.0,100.0);
	font->setColor(Color(1.0,1.0,1.0));
	font->addLine( "SUPERFAST", 2.5 );
	font->addLine( "      MOBILE #4GEE", 2.5 );
	font->addLine( "       ONLY ON EE", 2.0 );
	font->animateIn();
	mCue = timeline().add( boost::lambda::bind(&PassiveScene2::showFrame7, this), timeline().getCurrentTime() + 8 );
	showTerms = true;
}

void PassiveScene2::showFrame7()
{
	showTerms = false;
	font->animateOut();

	for (int i = 0; i < placeMarks.size(); i++){
		placeMarks[i]->disperseParticles();
	}

	mCue = timeline().add( boost::lambda::bind(&PassiveScene2::showFrame8, this), timeline().getCurrentTime() + 3 );
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

	if (showTerms==true){
		ci::gl::pushMatrices();
		ci::gl::translate(0,800-142,0);
		ci::gl::enableAlphaBlending();
		ci::gl::draw(*TextureGlobals::getInstance()->getParticleTexture(8));
		
		ci::gl::disableAlphaBlending();
		ci::gl::popMatrices();
	}
	//locationLabel.draw();
}