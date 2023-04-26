//
//  Settings.hpp
//  SingletonAndFactory
//
//  Created by Елизавета Шимкович on 26.04.23.
//

#ifndef Settings_hpp
#define Settings_hpp

#include <stdio.h>
#include "LinkGenerator.hpp"
#include "PhotoRequirementsGenerator.hpp"

enum class Platform
{
    Vkontakte,
    Instagram,
    Telegram,
    None
};

class Settings
{

    
private:
    static Settings* instance;
    Platform platform_;
    Settings();
    
    
public:
    static Settings* getInstance();
    void SetPlatform(Platform platform);
    LinkGenerator* CreateLinkGenerator();
    PhotoRequirements* CreatePhotoRequirements();
    
};




#endif /* Settings_hpp */
