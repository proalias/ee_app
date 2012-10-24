#include "FontRenderer.h"

FontRenderer::FontRenderer(void)
{
	font = NobleeBold();
	animationInProgress = false;
	mGridPointInc = 0;

	layoutXPos = 0;
	layoutYPos = 0;

	particleCount = 0;

	tickCounter = 0;
	populateGridPoints();

	currentColor =  Color(1.0,1.0,1.0);

	tickCued = false;
}

//creates a lookup table of grid points.
void FontRenderer::populateGridPoints(){

	int SPACING = 40;
	float COLUMNS = 1280/SPACING;
	float ROWS = 800/SPACING;
	
	//fieldLayerContainer.clear();

	for( int j=0; j<ROWS; j++ ){
		for( int i=0; i<COLUMNS; i++ ){
			gridPoints.push_back(Vec2f( i*SPACING , j*SPACING ));
		}
	}

}

//This gets a sequential point on the grid. However, the effect doesn't look very good, so I've commented out the calling function.
ci::Vec2f FontRenderer::getNextPointOnGrid(){

	
	float incSize = particleCount / float(gridPoints.size()) ;
	mGridPointInc += 1;

	int pointIndex = ci::math<float>::floor(incSize * mGridPointInc);

	return gridPoints[pointIndex % gridPoints.size()];
}


ci::Vec2f FontRenderer::getRandomPointOnGrid(){
	
	int SPACING = 40;

	float COLUMNS = cinder::app::getWindowWidth()/SPACING;
	float ROWS = cinder::app::getWindowHeight()/SPACING;
	
	float pX = randInt(-COLUMNS, COLUMNS)*SPACING;
	float pY = randInt(-ROWS, ROWS)*SPACING;
	return ci::Vec2f(pX,pY);	
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

// goes through all points and gets the highest
ci::Vec2f FontRenderer::getLineVerticalBounds( float index )
{
	std::vector<TweenParticle> line = lines[index];
	float highestPoint = 0.0;
	float lowestPoint = 1200.0;
	float pointLength = line.size();
	for( int i=0; i<pointLength; i++ ){
		if(line[i].ypos>highestPoint){
			highestPoint = line[i].ypos;
		}
		if(line[i].ypos<lowestPoint){
			lowestPoint = line[i].ypos;
		}
	}

	float lineHeight = highestPoint - lowestPoint;
	return ci::Vec2f(lowestPoint,highestPoint);
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


void FontRenderer::tick(int lineIndex){
	
	//int lineIndex = randInt(lines.size()-1);
	int tickRange = 80;
	if (lines.size() == 0 && lineIndex == 0){
		return;
	}
	int particleIndexA = randInt(lines[lineIndex].size());
	int particleIndexB = particleIndexA + randInt(tickRange);; 

	if (particleIndexA == particleIndexB){
		return;
	}

	if (particleIndexB >= lines[lineIndex].size()){
		return;
	}



	//ensure A is lower than B
	if (particleIndexA > particleIndexB){
		int temp = particleIndexA;
		particleIndexA = particleIndexB;
		particleIndexB = temp;
	}

	//loop through the particles
	for (int i = particleIndexA; i<=particleIndexB; i++){
		
		if (i==particleIndexA){

			float aPosX = lines[lineIndex][particleIndexA].xpos;
			float aPosY = lines[lineIndex][particleIndexA].ypos;


			float bPosX = lines[lineIndex][particleIndexB].xpos;
			float bPosY = lines[lineIndex][particleIndexB].ypos;

			float rad = lines[lineIndex][particleIndexA].rad;

			//lines[lineIndex][particleIndexB].animateTo(ci::Vec2f(aPosX,aPosY),0.5,getElapsedSeconds(),rad);
			lines[lineIndex][particleIndexA].animateTo(ci::Vec2f(bPosX,bPosY),1,getElapsedSeconds(),rad);

			bPosX = lines[lineIndex][i+1].xpos;
			bPosY = lines[lineIndex][i+1].ypos;

			lines[lineIndex][i+1].animateTo(ci::Vec2f(aPosX,aPosY),1,getElapsedSeconds(),rad);

		}

		if (i>particleIndexA+1){

			float bPosX = lines[lineIndex][i-1].xpos;
			float bPosY = lines[lineIndex][i-1].ypos;

			float rad = lines[lineIndex][particleIndexA].rad;

			lines[lineIndex][i].animateTo(ci::Vec2f(bPosX,bPosY),0.5,getElapsedSeconds(),rad);
		}
	}
	
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
	}else if( character == *"#" ){
		points = font.HASHTAG;
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
			float x = ((character[i][0] + xPosition) * size ) + layoutXPos;
			float y = (character[i][1] * size ) + layoutYPos;
			newline.push_back( TweenParticle( x , y , size*2.5 , false) );

		}

		char theNextChar = *"";
		if(i<copy.length()-1){
			theNextChar = copy[i+1];
		}

		xPosition += FontRenderer::getCharWidth( theChar, theNextChar ) ;//20;

		// TODO - add leading var . for now its this
		xPosition += 2;//1.5;

		// if it was a space
		if(pointLength<1){
			xPosition += 5;
		}

	}
	
	
	lines.push_back(newline);
	particleCount += newline.size();

	//this doesn't quite work yet...
	ci::Vec2f verticalBounds = this->getLineVerticalBounds(lines.size()-1);
	float lineHeight = verticalBounds.y - verticalBounds.x; //x is actaully another y, representing the 
	
	layoutYPos += lineHeight * 2;
}

void FontRenderer::setColor(ci::Color color){
	currentColor = color;
}

void FontRenderer::animateIn(){
		mGridPointInc = 0;
		float t = 0;////offset each time value slightly

		for (int j=0;j<lines.size();j++){
			for( vector<TweenParticle>::iterator p = lines[j].begin(); p != lines[j].end(); ++p , t+=0.001){
				p->animateTo(ci::Vec2f(p->xpos,p->ypos),getNextPointOnGrid(),1.5,getElapsedSeconds()+t,p->rad);
				p->update(ci::app::getElapsedSeconds());
				p->rad = 0;
			}
		}
}

void FontRenderer::animateOut(){
	
		//tickingCue->removeSelf();
		mGridPointInc = 0;
		float t = 0;//offset each time value slightly
		for (int j=0;j<lines.size();j++){

			for( vector<TweenParticle>::iterator p = lines[j].begin(); p != lines[j].end(); ++p, t+=0.001 ){
				p->animateTo(getNextPointOnGrid(), ci::Vec2f(p->xpos,p->ypos),2.0,getElapsedSeconds(),0);
				p->update(ci::app::getElapsedSeconds());
			}
		}
}



void FontRenderer::draw()
{

	gl::color(currentColor);

	for (int j=0;j<lines.size();j++){
		animationInProgress = false;
		for( vector<TweenParticle>::iterator p = lines[j].begin(); p != lines[j].end(); ++p ){
			p->update(getElapsedSeconds());
			p->draw();
			if (p->moving){
				animationInProgress = true;
			}
		}
	}
	
	
	if (animationInProgress == false ){

		float time = timeline().getCurrentTime() + 0.5;
		tickCounter ++;

		if (tickCounter % 20 == 0){
			for (int li = 0; li < lines.size();li++){
				tick(li);
			}
		}
		//tickingCue = timeline().add( bind(&FontRenderer::tick, this), time );
		//tickingCue->setDuration(1);
		//tickingCue->setLoop();
		//tickingCue->setInfinite();
		//tickCued = true;
	}

	gl::color(Color(1.0,1.0,1.0));
}


void FontRenderer::setPosition(float x, float y){
	layoutXPos = x;
	layoutYPos = y;
}

void FontRenderer::clear()
{
	layoutXPos = 0;
	layoutYPos = 0;

	mGridPointInc = 0;
	tickCounter = 0;
	lines.clear();
}