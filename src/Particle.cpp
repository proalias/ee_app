#include "Particle.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"

using namespace ci;

Particle::Particle()
{
}

Particle::Particle(  Vec2f loc, float size )
{
	sLoc	= loc;
	mLoc	= loc;
	mDir	= Rand::randVec2f();
	mVel	= Rand::randFloat( 5.0f );
	mRadius	= size*2.5;
}

void Particle::update()
{
	mLoc += mDir * mVel;
}

void Particle::draw()
{
	gl::drawSolidCircle( mLoc, mRadius );
}
