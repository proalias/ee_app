#ifndef WaveGesture_h
#define WaveGesture_h

#include "cinder\Cinder.h"

class WaveGesture{

public:
	bool lookForWaveLeft();
	bool lookForWaveRight();
	void setBonePositions(bonePositions);
private:
	std::map<int,std::list<ci::Vec3f>> &bonePositions;
	
}
#endif