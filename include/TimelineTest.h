#include "cinder/Cinder.h"
#include "cinder/Timeline.h"
#include "cinder/gl/gl.h"

class TimelineTest{
public:
	void draw();

	ci::Anim<float> x;
	ci::Anim<float> y;

	TimelineTest(float x, float y);
};
