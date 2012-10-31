#include "cinder\Cinder.h"
#ifndef TextureGlobals_h
#define TextureGlobals_h

#include "cinder\gl\Texture.h"


class TextureGlobals
{
private:
    static bool instanceFlag;
    static TextureGlobals *single;
	std::vector<ci::gl::Texture> particleTextures;

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
    }
public:
    static TextureGlobals* getInstance();
	void TextureGlobals::setParticleTexture(ci::gl::Texture texture,int type);

	ci::gl::Texture* getParticleTexture(int type);

    ~TextureGlobals()
    {
        instanceFlag = false;
    }
};
#endif