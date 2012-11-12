#ifndef ShopConfig_h
#define ShopConfig_h

#include "cinder\gl\Texture.h"
#include "cinder\Cinder.h"
#include "cinder\Xml.h"

#include <string>

class ShopConfig
{
private:
    static bool instanceFlag;
    static ShopConfig *single;
	
	std::vector<ci::gl::Texture> particleTextures;


    ShopConfig()
    {
		//defaults
		doorOnRight = false;
		location = "LONDON";
    }

	
public:
    static ShopConfig* getInstance();
	void ShopConfig::parseConfig(ci::XmlTree configXml);

	
	bool doorOnRight;
	std::string location;

    ~ShopConfig()
    {
        instanceFlag = false;
    }
};
#endif