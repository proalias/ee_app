#include "FontRenderer.h"
#include "cinder/Vector.h"
#include <vector>

using namespace std;
using namespace ci;

class PassiveScene3 {
 public:

	void setup();
	void draw();

	void animateIn();
	void animateOut();
	
	//std::vector<Vec2f> refToParticlesMaybe?;

	FontRenderer font;
	
	PassiveScene3( const FontRenderer &font );
	//~PassiveScene3(void);
};