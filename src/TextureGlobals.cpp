#include "TextureGlobals.h"

bool TextureGlobals::instanceFlag = false;
TextureGlobals* TextureGlobals::single = NULL;

TextureGlobals* TextureGlobals::getInstance()
{
    if(! instanceFlag)
    {
        single = new TextureGlobals();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}

ci::gl::Texture* TextureGlobals::getParticleTexture(int type){
	return &particleTextures[type];
}

SpriteSheet* TextureGlobals::getSpriteSheet(int type){
	if (sprites.size() > 0){
		return sprites[type];
	}
}



void TextureGlobals::setSpriteSheet(SpriteSheet* spriteSheet,const int type){
	//You must use a constant to set a sprite.
	//E.G.
	//static const int SPRITE_BUBBLEMAN_WAVE = 1;
	//static const int SPRITE_BUBBLEMAN_RUN = 2;

	if (type == SPRITE_UNDEFINED){
		//FAIL
		return;
	}


	sprites[type] = spriteSheet;
	

}

void TextureGlobals::setParticleTexture(ci::gl::Texture texture,int type){
	particleTextures[type] = texture;
}