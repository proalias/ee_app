#include "FontRenderer.h"
#include "cinder/Vector.h"
#include <vector>

using namespace std;
using namespace ci;

class PassiveScene1 {
 public:

	void setup();
	void draw();

	void animateIn();
	void animateOut();
	
	//std::vector<Vec2f> refToParticlesMaybe?;

	FontRenderer font;
	
	PassiveScene1( const FontRenderer &font );
	//~PassiveScene1(void);
};