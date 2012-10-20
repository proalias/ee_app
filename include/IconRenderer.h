#include "cinder/Cinder.h"
#include "cinder/Timeline.h"
#include <stdio.h>
#include "TweenParticle.h"

class IconRenderer{
public :
	IconRenderer( std::vector<TweenParticle> &points);

	void draw();
	void update();
	void	tweenTo( ci::Timeline &timeline,  float xPosDest, float yPosDest, float duration );
	
	ci::Anim<float> xPos;
	ci::Anim<float> yPos;
	ci::Anim<float> xScale;
	ci::Anim<float> yScale;

	std::vector<TweenParticle> mPoints;
};
