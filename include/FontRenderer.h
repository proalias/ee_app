#include "cinder/Color.h"
#include "cinder/Vector.h"
#include <vector>
#pragma once

#include "Particle.h"
#include "NobleeBold.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/Rand.h"

#include "TweenParticle.h"


#include <list>


class FontRenderer {
 
public:

	// TODO - pass in one of the 3 noblees to use
	// void setFont();
	// TODO - for now using one font. should be able to use any of the weights
	NobleeBold font;

//	std::vector<TweenParticle> points;
	
    std::vector<std::vector<TweenParticle>> lines;
	//void setColor( Color );

	// pass in a string you want to display and a size
	void addLine( const std::string &line, int );

	void setup();
	void draw();
	void clear();
	ci::Vec2f getNextPointOnGrid();
	ci::Vec2f getRandomPointOnGrid();
	void animateIn();
	void animateOut();
	void setPosition(float x, float y);
	void tick(int lineIndex);
	

	// TODO - this one should actually be private
	// TODO - also for now its a massive switch, I read can do some kind of hash map to function pointers instead
	// essentially you pass in a string and it will give you the points for that character
	std::vector<ci::Vec2f> getCharacter(char);

	float getCharWidth( char, char );

	float getLineWidth( float ); // gets the width of a line by index
	float getLineHeight( float ); // gets the height of a line by index
	
	ci::Vec2f FontRenderer::getLineVerticalBounds( float index );

	void animateWhiteToYellow();

	FontRenderer(void);
	//~FontRenderer(void);

	void setColor(ci::Color);

	bool animationInProgress;
	float lineHeight;
private:
	int particleCount;
	void populateGridPoints();
	int mGridPointInc;
	std::vector<ci::Vec2f> gridPoints;

	ci::CueRef tickingCue;
	bool tickCued;
	ci::Color currentColor;
	int tickCounter;

	float layoutXPos;
	float layoutYPos;
};