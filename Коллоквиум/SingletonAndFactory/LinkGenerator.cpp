//
//  LinkGenerator.cpp
//  SingletonAndFactory
//
//  Created by Елизавета Шимкович on 26.04.23.
//

#include "LinkGenerator.hpp"


LinkGenerator::LinkGenerator() {}
LinkGenerator::~LinkGenerator() {}

VkLinkGenerator::VkLinkGenerator():LinkGenerator() {}

string VkLinkGenerator::GetFormattedLink(string nick)
{
    return ("https://vk.com/" + nick);
}

InstaLinkGenerator::InstaLinkGenerator():LinkGenerator() {}
string InstaLinkGenerator::GetFormattedLink(string nick)
{
    return ("https://instagram.com/" + nick);
}


TelegramLinkGenerator::TelegramLinkGenerator():LinkGenerator() {}
string TelegramLinkGenerator::GetFormattedLink(string nick)
{
    return ("https://t.me/" + nick);
}

