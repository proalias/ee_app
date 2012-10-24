#ifndef ShopConfig_h
#define ShopConfig_h

#include "cinder\gl\Texture.h"
#include "cinder\Cinder.h"
#include "cinder\Xml.h"

#include <string>

using namespace cinder;
using namespace gl;

class ShopConfig
{
private:
    static bool instanceFlag;
    static ShopConfig *single;
	
	std::vector<gl::Texture> particleTextures;


    ShopConfig()
    {
		//defaults
		bool doorOnRight = false;
		std::string location = "LONDON";
    }

	
public:
    static ShopConfig* getInstance();
	void ShopConfig::parseConfig(XmlTree configXml);

	
	bool doorOnRight;
	std::string location;

    ~ShopConfig()
    {
        instanceFlag = false;
    }
};
#endif