#pragma once

#include "cinder/Cinder.h"
#include <boost/signals2.hpp>
#include <iostream>
#include "FontRenderer.h" 
#include "cinder/Cinder.h"

class SceneBase {

public:
	virtual void setup( FontRenderer &thefont )
	{
		font = &thefont;
		font->clear();
		font->addLine( "BASE CLASS ERROR", 2 );
	}
	virtual void update(){}
	virtual void draw(){}
	
	// this typedef creates a simple shorthand, so that ButtonSignal refers to boost::signals2::signal<void( Button* )>
	// If you wanted you could use the long name instead, but its easier to typo
	typedef boost::signals2::signal<void( SceneBase* )> SceneSignal;

	// ACCESSORS
	std::string getId() { return _id; };
	SceneSignal* getSignal() { return &_signal; }; // Notice we return a pointer to the signal

protected:
	FontRenderer * font; // just a pointer to the one on the stage
	
	std::string _id;
	SceneSignal _signal;

private:
//	std::string _id;
//	SceneSignal _signal;
};