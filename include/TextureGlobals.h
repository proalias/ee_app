#include "cinder/Cinder.h"
#ifndef TextureGlobals_h
#define TextureGlobals_h

#include "cinder/gl/Texture.h"
#include "cinder/app/App.h"
#include "SpriteSheet.h"
#include "cinder/ImageIo.h"

class TextureGlobals
{
private:
    static bool instanceFlag;
    static TextureGlobals *single;
	std::vector<ci::gl::Texture> particleTextures;
	std::vector<ci::gl::Texture> bubbleManWaveFrames;

	//ci::qtime::MovieGl bubbleManWave;
	SpriteSheet bubbleManWave;
	SpriteSheet bubbleManRun;

    TextureGlobals()
    {

		ci::gl::Texture particleTexture =  ci::gl::Texture();
		
		int totalParticleTextures = 11;
		for(int i=0;i<totalParticleTextures;i++){
			particleTextures.push_back(particleTexture);
		}

		int bubbleManWaveTextures = 10;
		for(int i=0;i<totalParticleTextures;i++){
			particleTextures.push_back(particleTexture);
		}

    }
public:

	std::map<int,SpriteSheet*> spriteSheets;
    static TextureGlobals* getInstance();
	void TextureGlobals::setParticleTexture(ci::gl::Texture texture,int type);
	
	static const int SPRITE_BUBBLEMAN_WAVE = 0;
	static const int SPRITE_BUBBLEMAN_RUN = 1;

	
	void setSpriteSheet(SpriteSheet* spriteSheet, int spriteId);
	SpriteSheet* getSpriteSheet(int spriteId);
	
	ci::gl::Texture* getParticleTexture(int type);
	
	//ci::qtime::MovieGl* getBubbleManWave();

	
    ~TextureGlobals()
    {
        instanceFlag = false;
    }
};
#endif