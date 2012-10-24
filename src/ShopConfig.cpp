#include "ShopConfig.h"

bool ShopConfig::instanceFlag = false;
ShopConfig* ShopConfig::single = NULL;


ShopConfig* ShopConfig::getInstance()
{
    if(! instanceFlag)
    {
        single = new ShopConfig();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}


void ShopConfig::parseConfig(XmlTree config){
	
	for( XmlTree::ConstIter item = config.begin(); item != config.end(); ++item ) {

		std::list<XmlTree> children = item->getChildren();

		for (std::list<XmlTree>::iterator iter = children.begin();iter != children.end(); iter ++){

			std::string tagName = iter->getTag();

			if (tagName == "shop"){
				
				std::list<XmlTree::Attr> attributes = iter->getAttributes();
				for(std::list<XmlTree::Attr>::iterator attr = attributes.begin();attr != attributes.end();attr ++){
					if (attr->getName()=="location"){
						location = attr->getValue();
					}

					if (attr->getName()=="doorOnRight"){
						std::string doorOnRight = attr->getValue();
						if ( doorOnRight.compare("true") == 0){
							this->doorOnRight = true;
						}else{
							this->doorOnRight = false;
						}
					}
				}
			}
		}

	}
};