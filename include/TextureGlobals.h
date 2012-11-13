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
	std::vector<SpriteSheet*> sprites;

	
    TextureGlobals()
    {

		ci::gl::Texture particleTexture =  ci::gl::Texture();
		
		int totalParticleTextures = 11;
		for(int i=0;i<totalParticleTextures;i++){
			particleTextures.push_back(particleTexture);
		}

		int totalSprites = 4;
		SpriteSheet undefined = SpriteSheet();
		for(int i=0;i<totalSprites;i++){
			sprites.push_back(&undefined);
		}

    }
public:

    static TextureGlobals* getInstance();
	void TextureGlobals::setParticleTexture(ci::gl::Texture texture,int type);
	
	static const int SPRITE_UNDEFINED = 0;
	static const int SPRITE_BUBBLEMAN_WAVE = 1;
	static const int SPRITE_BUBBLEMAN_RUN = 2;

	
	void setSpriteSheet(SpriteSheet* spriteSheet, const int spriteId);
	SpriteSheet* getSpriteSheet(const int spriteId);
	
	ci::gl::Texture* getParticleTexture(int type);
	

    ~TextureGlobals()
    {
        instanceFlag = false;
    }
};
#endif