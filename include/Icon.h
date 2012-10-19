#include "cinder/Vector.h"
#include <vector>

using namespace std;
using namespace ci;

class Icon {
 public:

	void draw();
	
	std::vector<Vec3f> iconParticles; // currently looking like the parer already makes them tween particles?

	Icon( std::vector<Vec3f> particles ); // TODO - copy in and destroy originals?
	//~Icon(void);
};