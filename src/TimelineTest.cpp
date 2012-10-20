#include "TimelineTest.h"

using namespace ci;

TimelineTest::TimelineTest(float x, float y)
{
	this->x = x;
	this->y = y;
}

void TimelineTest::draw()
{
	gl::drawSolidCircle( x, y, 20 );
}
