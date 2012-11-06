#include "cinder/Cinder.h"
#ifndef TextureGlobals_h
#define TextureGlobals_h

#include "cinder/gl/Texture.h"
#include "cinder/qtime/QuickTime.h"
#include "cinder/app/App.h"

class TextureGlobals
{
private:
    static bool instanceFlag;
    static TextureGlobals *single;
	std::vector<ci::gl::Texture> particleTextures;
	ci::qtime::MovieGl bubbleManWave;

    TextureGlobals()
    {

		ci::gl::Texture particleTexture =  ci::gl::Texture();
		particleTextures.push_back(particleTexture);
		particleTextures.push_back(particleTexture);
		particleTextures.push_back(particleTexture);
		particleTextures.push_back(particleTexture);
		particleTextures.push_back(particleTexture);
		particleTextures.push_back(particleTexture);
		particleTextures.push_back(particleTexture);
		particleTextures.push_back(particleTexture);
		particleTextures.push_back(particleTexture);
		particleTextures.push_back(particleTexture);

		bubbleManWave = ci::qtime::MovieGl( cinder::app::loadAsset("bubbleMan_Wave.mov" ));
		
    }
public:
    static TextureGlobals* getInstance();
	void TextureGlobals::setParticleTexture(ci::gl::Texture texture,int type);

	ci::gl::Texture* getParticleTexture(int type);
	
	ci::qtime::MovieGl* getBubbleManWave();

	
    ~TextureGlobals()
    {
        instanceFlag = false;
    }
};
#endif