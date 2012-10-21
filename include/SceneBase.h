#pragma once

#include "cinder/Cinder.h"
#include <boost/signals2.hpp>
#include <iostream>

#include "FontRenderer.h" 
#include "IconFactory.h"
#include "IconRenderer.h"
#include "ForegroundParticles.h"

class SceneBase {

public:
	virtual void setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles )
	{
		font = &thefont;
		font->clear();
		font->setPosition(0.0,0.0);
		font->addLine( "BASE CLASS ERROR - OVERRIDE SETUP", 2 );

		iconFactory =  &theIconFactory;

		fgParticles = &thefgParticles;
	}
	virtual void update(Timeline &timeline){}
	virtual void draw(){}
	
	// this typedef creates a simple shorthand, so that ButtonSignal refers to boost::signals2::signal<void( Button* )>
	// If you wanted you could use the long name instead, but its easier to typo
	typedef boost::signals2::signal<void( SceneBase* )> SceneSignal;

	// ACCESSORS
	int getId() { return _id; };
	SceneSignal* getSignal() { return &_signal; }; // Notice we return a pointer to the signal

protected:

	// these are just pointers to the instances on main
	FontRenderer * font;
	IconFactory * iconFactory;
	ForegroundParticles * fgParticles;

	// signal stuff
	int _id;
	SceneSignal _signal;

};