#include "FontRenderer.h"
#include "cinder/Vector.h"
#include <vector>

using namespace std;
using namespace ci;

class PassiveScene2 {
 public:

	void setup();
	void draw();

	void animateIn();
	void animateOut();
	
	//std::vector<Vec2f> refToParticlesMaybe?;

	FontRenderer font;
	
	PassiveScene2( const FontRenderer &font );
	//~PassiveScene2(void);
};