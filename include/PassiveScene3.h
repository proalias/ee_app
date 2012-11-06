#ifndef PassiveScene3_H_
#define PassiveScene3_H_

#include "FontRenderer.h"
#include "SceneBase.h"

class PassiveScene3: public SceneBase {
 
public:

	ci::gl::Texture bgImage;

	float leftShift;

	float incrementer;

	bool isFrame1;
	bool isFrame2;
	bool isFrame3;
	bool isFrame4;

	bool showTerms;

	float alphaValue; // of the particles

	float imageAlpha;

	float particleAlpha;

	float gridSpeed;
	float particleSpeed;

	ci::gl::Texture* particleTexture;
	ci::gl::Texture* otherParticleTexture;

	std::list<ParticleA> localParticles;

	// inherited and overridden
	void setup( FontRenderer &thefont, IconFactory &theIconFactory, ForegroundParticles &thefgParticles, std::vector<ParticleA> &thegridLayer );
	void update();
	void draw();

	void exitNow();

	PassiveScene3(void);
	//~PassiveScene2(void);

	float gridZ;
	
 private:
	ci::CueRef mCue;
	// keyframes
	void showFrame2();
	void showFrame3();
	void showFrame4();
	void showFrame5();
};

#endif /* PASSIVESCENE3_H_ */