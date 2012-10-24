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

gl::Texture* TextureGlobals::getParticleTexture(int type){
	return &particleTextures[type];
}

void TextureGlobals::setParticleTexture(gl::Texture texture,int type){
	particleTextures[type] = texture;
}