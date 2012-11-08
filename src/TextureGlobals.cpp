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
	switch(type){
		case SPRITE_BUBBLEMAN_WAVE:
			return &bubbleManWave;
			break;
		case SPRITE_BUBBLEMAN_RUN:
			return &bubbleManRun;
	}
}




void TextureGlobals::setParticleTexture(ci::gl::Texture texture,int type){
	particleTextures[type] = texture;
}