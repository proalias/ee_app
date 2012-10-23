#pragma once

class Vect {

public:
	
	float x;
	float y;
	
	void draw();
	
	void reset( int xPos, int yPos );

	Vect clone(void);

	void copyTo(Vect v);
		
	void copyFrom(Vect v);

	float magnitude();

	Vect* plusEq(Vect v);
		
	Vect* minusEq(Vect v);
	
	Vect* multiplyEq(float scalar);

	bool equals(Vect v);

	Vect(void);
	//~Vect(void);

	Vect(int xPos,int yPos);

};