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

void TextureGlobals::setParticleTexture(ci::gl::Texture texture,int type){
	particleTextures[type] = texture;
}