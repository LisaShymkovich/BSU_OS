//
//  Settings.cpp
//  SingletonAndFactory
//
//  Created by Елизавета Шимкович on 26.04.23.
//

#include "Settings.hpp"


Settings::Settings() : platform_(Platform::None) {}

Settings* Settings::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Settings();
    }
    return instance;
}

void Settings::SetPlatform(Platform platform)
{
    platform_ = platform;
}

LinkGenerator* Settings::CreateLinkGenerator()
{
    switch (platform_)
    {
        case Platform::Vkontakte:
            return new VkLinkGenerator();
            break;
        case Platform::Instagram:
            return new InstaLinkGenerator();
            break;
        case Platform::Telegram:
            return new TelegramLinkGenerator();
            break;
        default:
            return nullptr;
    }
}


PhotoRequirements* Settings::CreatePhotoRequirements()
{
    switch (platform_)
    {
        case Platform::Vkontakte:
            return new VkPhotoRequirements();
            break;
        case Platform::Instagram:
            return new InstaPhotoRequirements();
            break;
        case Platform::Telegram:
            return new TelegramPhotoRequirements();
            break;
        default:
            return nullptr;
    }
}


Settings* Settings::instance = nullptr;
