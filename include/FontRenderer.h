#include "cinder/Color.h"
#include "cinder/Vector.h"
#include <vector>
#include "Particle.h"
#include "NobleeBold.h"

using namespace std;
using namespace ci;

#include <list>
using std::list;

class FontRenderer {
 
public:
	std::list<Particle>	mParticles;

	// TODO - pass in one of the 3 noblees to use
	// void setFont();
	// TODO - for now using one font. should be able to use any of the weights
	NobleeBold font;

	//void setColor( Color );

	// pass in a string you want to display and a size
	void addLine( const std::string &line, int );

	void setup();
	void draw();
	void clear();

	// TODO - this one should actually be private
	// TODO - also for now its a massive switch, I read can do some kind of hash map to function pointers instead
	// essentially you pass in a string and it will give you the points for that character
	std::vector<Vec2f> getCharacter(char);

	float getCharWidth( char, char );

	FontRenderer(void);
	//~FontRenderer(void);
};