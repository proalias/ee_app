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

		ci::gl::Texture bubbleManWaveTexture = cinder::loadImage(ci::app::loadAsset("./bubbleman_wave_texture/bubbleman_wave.png"));
		bubbleManWave = SpriteSheet();
		bubbleManWave.init(bubbleManWaveTexture, "./bubbleman_wave_texture/bubbleman_wave.xml", SpriteSheet::FORMAT_TEXTUREPACKER_GENERIC_XML);

		ci::gl::Texture bubbleManRunTexture = cinder::loadImage(ci::app::loadAsset("./bubbleman_run_texture/bubbleman_run.png"));
		bubbleManRun = SpriteSheet();
		bubbleManRun.init(bubbleManRunTexture, "./bubbleman_run_texture/bubbleman_run.xml", SpriteSheet::FORMAT_TEXTUREPACKER_GENERIC_XML);

    }
public:
    static TextureGlobals* getInstance();
	void TextureGlobals::setParticleTexture(ci::gl::Texture texture,int type);
	 
	static const int SPRITE_BUBBLEMAN_WAVE = 1;
	static const int SPRITE_BUBBLEMAN_RUN = 2;

	SpriteSheet* getSpriteSheet(int spriteId);
	ci::gl::Texture* getParticleTexture(int type);
	
	//ci::qtime::MovieGl* getBubbleManWave();

	
    ~TextureGlobals()
    {
        instanceFlag = false;
    }
};
#endif