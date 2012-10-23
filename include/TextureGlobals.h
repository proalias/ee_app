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
	gl::Texture particleTexture;
    TextureGlobals()
    {
        //private constructor
		particleTexture =  gl::Texture();
    }
public:
    static TextureGlobals* getInstance();
	void TextureGlobals::setParticleTexture(gl::Texture texture);

	gl::Texture* getParticleTexture();


    ~TextureGlobals()
    {
        instanceFlag = false;
    }
};
#endif