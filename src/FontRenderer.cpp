#include "FontRenderer.h"

FontRenderer::FontRenderer(void)
{
	font = NobleeBold();
	animationInProgress = false;
	mGridPointInc = 0;
}

// goes through all points and gets the widest
float FontRenderer::getLineWidth( float index )
{
	std::vector<TweenParticle> line = lines[index];
	float widestPoint = 0.0;
	float pointLength = line.size();
	for( int i=0; i<pointLength; i++ ){
		if(line[i].xpos>widestPoint){
			widestPoint = line[i].xpos;
		}
	}
	return widestPoint;
}


// goes through all points and gets the highest
float FontRenderer::getLineHeight( float index )
{
	std::vector<TweenParticle> line = lines[index];
	float longestPoint = 0.0;
	float pointLength = line.size();
	for( int i=0; i<pointLength; i++ ){
		if(line[i].ypos>longestPoint){
			longestPoint = line[i].ypos;
		}
	}
	return longestPoint;
}


// sorts the leading per character
float FontRenderer::getCharWidth( char char1, char char2 )
{
	// FIRST GET THE WIDEST POINT FOR THAT CHARACTER

	std::vector<Vec2f> character = FontRenderer::getCharacter( char1 );
		
	float widestPoint = 0.0;

	float pointLength = character.size();

	for( int i=0; i<pointLength; i++ )
	{
		if(character[i][0]>widestPoint){
			widestPoint = character[i][0];
		}
	}


	// PART TO DOES SOME SPECIFIC LEADING BETWEEN SPECIFIC CHARACTERS

	float totalWidth = widestPoint;
			
	if (char1 == *"A" || char1 == *"T" || char1 == *"V" || char1 == *"W" || char1 == *"Y" || char1 == *"Y")
	{
		if (char1 == *"V" && char2 == *"A")
		{
			totalWidth -= 4; 
		}
		else if (char1 != *"A" && char2 == *"A")
		{
			totalWidth -= 3; 
		}
		else if (char1 != *"Y" && char2 == *"Y")
		{
			totalWidth -= 4; 
		}				
		else if (char2 == *"C" || char2 == *"G" || char2 == *"O" || char2 == *"Q")
		{
			totalWidth -= 2; 
		}
	}
	else if (char1 == *"F" && char2 == *"A")
	{
		totalWidth -= 2;
	}
	else if (char1 == *"C" || char1 == *"G" || char1 == *"O" || char1 == *"Q")
	{
		if (char2 == *"A")
		{
			totalWidth -= 2; 
		}
		else if (char2 == *"T" || char2 == *"V" || char2 == *"W" || char2 == *"Y")
		{
			totalWidth -= 2;
		}
	}
	else if (char1 == *"L")
	{
		if (char2 == *"Y" || char2 == *"V")
		{
			totalWidth -= 4; 
		}
	}

	return totalWidth;
}

// TODO - get someone to look at this cos i dont really know what im doing with the pointer crap
// on strings like this. I just did it and it semeed to work : /
// TODO - also switch this or make a hash map of some type / lookup table
std::vector<Vec2f> FontRenderer::getCharacter( char character )
{
	std::vector<Vec2f> points;

	if( character == *"A" || character == *"a" ){
		points = font.A;
	}else if( character == *"B" || character == *"b" ){
		points = font.B;
	}else if( character == *"C" || character == *"c" ){
		points = font.C;
	}else if( character == *"D" || character == *"d" ){
		points = font.D;
	}else if( character == *"E" || character == *"e" ){
		points = font.E;
	}else if( character == *"F" || character == *"f" ){
		points = font.F;
	}else if( character == *"G" || character == *"g" ){
		points = font.G;
	}else if( character == *"H" || character == *"h" ){
		points = font.H;
	}else if( character == *"I" || character == *"i" ){
		points = font.I;
	}else if( character == *"J" || character == *"j" ){
		points = font.J;
	}else if( character == *"K" || character == *"k" ){
		points = font.K;
	}else if( character == *"L" || character == *"l" ){
		points = font.L;
	}else if( character == *"M" || character == *"m" ){
		points = font.M;
	}else if( character == *"N" || character == *"n" ){
		points = font.N;
	}else if( character == *"O" || character == *"o" ){
		points = font.O;
	}else if( character == *"P" || character == *"p" ){
		points = font.P;
	}else if( character == *"Q" || character == *"q" ){
		points = font.Q;
	}else if( character == *"R" || character == *"r" ){
		points = font.R;
	}else if( character == *"S" || character == *"s" ){
		points = font.S;
	}else if( character == *"T" || character == *"t" ){
		points = font.T;
	}else if( character == *"U" || character == *"u" ){
		points = font.U;
	}else if( character == *"V" || character == *"v" ){
		points = font.V;
	}else if( character == *"W" || character == *"w" ){
		points = font.W;
	}else if( character == *"X" || character == *"x" ){
		points = font.X;
	}else if( character == *"Y" || character == *"y" ){
		points = font.Y;
	}else if( character == *"Z" || character == *"z" ){
		points = font.Z;
	}else if( character == *"0" ){
		points = font.ZERO;
	}else if( character == *"1" ){
		points = font.ONE;
	}else if( character == *"2" ){
		points = font.TWO;
	}else if( character == *"3" ){
		points = font.THREE;
	}else if( character == *"4" ){
		points = font.FOUR;
	}else if( character == *"5" ){
		points = font.FIVE;
	}else if( character == *"6" ){
		points = font.SIX;
	}else if( character == *"7" ){
		points = font.SEVEN;
	}else if( character == *"8" ){
		points = font.EIGHT;
	}else if( character == *"9" ){
		points = font.NINE;
	}else if( character == *"." ){
		points = font.FULL_STOP;
	}else if( character == *">" ){
		points = font.GREATER_THAN;
	}else if( character == *"<" ){
		points = font.LESS_THAN;
	}else if( character == *"?" ){
		points = font.QUESTION_MARK;
	}else if( character == *"!" ){
		points = font.EXCLAMATION_MARK;
	}else if( character == *"£" ){
		points = font.POUND;
	}else if( character == *"€" ){
		points = font.EURO;
	}else if( character == *"%" ){
		points = font.PERCENTAGE;
	}else if( character == *"&" ){
		points = font.AMPERSAND;
	}else if( character == *"^" ){
		points = font.CIRCUMFLEX;
	}else if( character == *"@" ){
		points = font.AT_SYMBOL;
	}else if( character == *"(" ){
		points = font.OPEN_BRACKET;
	}else if( character == *")" ){
		points = font.CLOSE_BRACKET;
	}else if( character == *"+" ){
		points = font.PLUS;
	}else if( character == *"=" ){
		points = font.EQUALS;
	}else if( character == *"-" ){
		points = font.DASH;
	}else if( character == *"_" ){
		points = font.UNDERSCORE;
	}else if( character == *"/" ){
		points = font.FORWARD_SLASH;
	}else if( character == *"\"" ){
		points = font.DOUBLE_QUOTE;
	}else if( character == *"\'" ){
		points = font.SINGLE_QUOTE;
	}else if( character == *":" ){
		points = font.COLON;
	}else if( character == *";" ){
		points = font.SEMI_COLON;
	}else if( character == *"," ){
		points = font.COMMA;
	}

	return points;
}

// TODO - pass in an init position for x and y
void FontRenderer::addLine( const std::string &copy, int size )
{
	std::vector<TweenParticle> newline = vector<TweenParticle>();

	// current characters postition 
	int xPosition = 0;
	//int yPosition = 0;
	
	for( int i=0; i<copy.length(); i++ )
	{
		char theChar = copy[i];

		std::vector<Vec2f> character = FontRenderer::getCharacter( theChar );
		
		float pointLength = character.size();

		for( int i=0; i<pointLength; i++ )
		{
			float x = character[i][0]+xPosition;
			float y = character[i][1];//+yPosition;
			newline.push_back( TweenParticle(  x*size, y*size , size*2.5 ) );
			
		}

		char theNextChar = *"";
		if(i<copy.length()-1){
			theNextChar = copy[i+1];
		}

		xPosition += FontRenderer::getCharWidth( theChar, theNextChar );//20;

		// TODO - add leading var . for now its this
		xPosition += 2;//1.5;

		// if it was a space
		if(pointLength<1){
			xPosition += 5;
		}

	}
	
	lines.push_back(newline);
	


}

void FontRenderer::animateIn(){
	//if (animationInProgress == false){
		animationInProgress = true;
		float t = 0;

		for (int j=0;j<lines.size();j++){
			for( vector<TweenParticle>::iterator p = lines[j].begin(); p != lines[j].end(); ++p , t+=0.005){
				//p->mLoc+=( Rand::randFloat( 0.2f ) - Rand::randFloat( 0.2f ) );
				p->animateTo(ci::Vec2f(p->xpos,p->ypos),getRandomPointOnGrid(),3.0,getElapsedSeconds()+t,p->rad);
				p->rad = 0;
			}
		}
	//}
}

void FontRenderer::animateOut(){
	//if (animationInProgress == false){
	//	animationInProgress = true;
		for (int j=0;j<lines.size();j++){

			for( vector<TweenParticle>::iterator p = lines[j].begin(); p != lines[j].end(); ++p ){
				//p->mLoc+=( Rand::randFloat( 0.2f ) - Rand::randFloat( 0.2f ) );
				p->animateTo(getRandomPointOnGrid(), ci::Vec2f(p->xpos,p->ypos),3.0,getElapsedSeconds(),2);
			}
		}
	//}
}



ci::Vec2f FontRenderer::getRandomPointOnGrid(){
	
	int SPACING = 40;

	float COLUMNS = cinder::app::getWindowWidth()/SPACING;
	float ROWS = cinder::app::getWindowHeight()/SPACING;
	
	//fieldLayerContainer.clear();

	float pX = randInt(-COLUMNS, COLUMNS)*SPACING;
	float pY = randInt(-ROWS, ROWS)*SPACING;
	return ci::Vec2f(pX,pY);

	/*
	mGridPointInc += 1;

	for( int j=0; j<ROWS; j++ ){
		for( int i=0; i<COLUMNS; i++ ){
			if (i+j*ROWS == mGridPointInc){
				return ci::Vec2f(i*SPACING,j*SPACING);
			}
		}
	}*/

	
}




void FontRenderer::draw()
{
	// DO NOT REMOVE THIS CODE
	// IT CENTRES TEXT AND WE MAY NEED TO ROLL IT BACK LATER

	/*
	float yPos = 100;
	float xPos = 0;//(getWindowWidth()/2);

	for (int j=0;j<lines.size();j++){

		gl::pushMatrices();

		xPos = (getWindowWidth()/2) - (getLineWidth(j)/2);

		gl::translate( xPos, yPos, 0 );

		for( vector<Particle>::iterator p = lines[j].begin(); p != lines[j].end(); ++p ){
			//p->mLoc+=( Rand::randFloat( 0.2f ) - Rand::randFloat( 0.2f ) );
			p->draw();
		}
	
		yPos += FontRenderer::getLineHeight(j)+10;

		gl::popMatrices();
	}

	*/


	float yPos = 100;
	float xPos = 0;//(getWindowWidth()/2);

	for (int j=0;j<lines.size();j++){

		gl::pushMatrices();

		xPos = 300;//(getWindowWidth()/2) - (getLineWidth(j)/2);

		gl::translate( xPos, yPos, 0 );

		animationInProgress = false;
		for( vector<TweenParticle>::iterator p = lines[j].begin(); p != lines[j].end(); ++p ){
			//p->mLoc+=( Rand::randFloat( 0.2f ) - Rand::randFloat( 0.2f ) );
			p->update(getElapsedSeconds());
			p->draw();
			if (p->moving){
				animationInProgress = true;
			}
		}
	
		yPos += FontRenderer::getLineHeight(j)+10;

		gl::popMatrices();
	}

}

void FontRenderer::clear()
{
	mParticles.clear();

	lines.clear();
}