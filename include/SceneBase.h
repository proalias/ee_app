#pragma once

//#include "cinder/Cinder.h"
#include <boost/signals2.hpp>
#include <iostream>
#include "FontRenderer.h" 
#include "IconFactory.h"
#include "IconRenderer.h"
#include "cinder/Cinder.h"

class SceneBase {

public:
	virtual void setup( FontRenderer &thefont, IconFactory &theIconFactory )
	{
		font = &thefont;
		font->clear();
		font->addLine( "BASE CLASS ERROR", 2 );

		iconFactory =  &theIconFactory;
	}
	virtual void update(){}
	virtual void draw(){}
	
	virtual void animateIn(ci::Timeline &Timeline){}
	virtual void animateOut(ci::Timeline &Timeline){}

	// this typedef creates a simple shorthand, so that ButtonSignal refers to boost::signals2::signal<void( Button* )>
	// If you wanted you could use the long name instead, but its easier to typo
	typedef boost::signals2::signal<void( SceneBase* )> SceneSignal;

	// ACCESSORS
	std::string getId() { return _id; };
	SceneSignal* getSignal() { return &_signal; }; // Notice we return a pointer to the signal

protected:
	FontRenderer * font; // just a pointer to the one on the stage
	IconFactory * iconFactory; // just a pointer to the one in the main app
	std::string _id;
	SceneSignal _signal;
	int phase;

private:
//	std::string _id;
//	SceneSignal _signal;
};