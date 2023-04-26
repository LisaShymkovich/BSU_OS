//
//  LinkGenerator.hpp
//  SingletonAndFactory
//
//  Created by Елизавета Шимкович on 26.04.23.
//

#ifndef LinkGenerator_hpp
#define LinkGenerator_hpp

#include <stdio.h>
#include <string>
using namespace std;


class LinkGenerator
{
   public:
    LinkGenerator();
    virtual ~LinkGenerator();
    virtual string GetFormattedLink(string nick) = 0;
};

class VkLinkGenerator : public LinkGenerator
{
   public:
    VkLinkGenerator();
    string GetFormattedLink(string nick) override;
};


class InstaLinkGenerator : public LinkGenerator
{
   public:
    InstaLinkGenerator();
    string GetFormattedLink(string nick) override;
};


class TelegramLinkGenerator : public LinkGenerator
{
   public:
    TelegramLinkGenerator();
    string GetFormattedLink(string nick) override;
};

#endif /* LinkGenerator_hpp */
