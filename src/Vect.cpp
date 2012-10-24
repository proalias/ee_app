#include "Vect.h"
#include <cinder/CinderMath.h>

Vect::Vect()
{
	x = 0;
	y = 0;
}

Vect::Vect( int xPos, int yPos )
{
	x = xPos;
	y = yPos;
}

void Vect::reset( int xPos, int yPos )
{
	x = xPos;
	y = yPos;
}
	
Vect Vect::clone()
{
	return Vect(x,y);
}
		
void Vect::copyTo(Vect v)
{
	v.x = x;
	v.y = y;
}
			
void Vect::copyFrom(Vect v)
{
	x = v.x;
	y = v.y;
}	

float Vect::magnitude()
{
	//return Math.sqrt((x*x)+(y*y));
	return sqrt((x*x)+(y*y));
}

Vect* Vect::plusEq(Vect v)
{
	x+=v.x;
	y+=v.y;
			
	return this; 
}
		
Vect* Vect::minusEq(Vect v)
{
	x-=v.x;
	y-=v.y;
			
	return this; 
}
	
Vect* Vect::multiplyEq(float scalar)
{
	x*=scalar;
	y*=scalar;
			
	return this; 
}

bool Vect::equals(Vect v)
{
	return ((x==v.x)&&(y==v.y));
}