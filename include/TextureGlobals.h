#include "cinder\Cinder.h"
#ifndef TextureGlobals_h
#define TextureGlobals_h

#include "cinder\gl\Texture.h"

using namespace cinder;
using namespace gl;

class TextureGlobals
{
private:
    static bool instanceFlag;
    static TextureGlobals *single;
	std::vector<gl::Texture> particleTextures;

    TextureGlobals()
    {

		gl::Texture particleTexture =  gl::Texture();
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
	void TextureGlobals::setParticleTexture(gl::Texture texture,int type);

	gl::Texture* getParticleTexture(int type);

    ~TextureGlobals()
    {
        instanceFlag = false;
    }
};
#endif