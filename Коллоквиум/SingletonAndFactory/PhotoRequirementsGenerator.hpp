//
//  PhotoRequirementsGenerator.hpp
//  SingletonAndFactory
//
//  Created by Елизавета Шимкович on 26.04.23.
//

#ifndef PhotoRequirementsGenerator_hpp
#define PhotoRequirementsGenerator_hpp

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


class PhotoRequirements
{
   public:
    PhotoRequirements();
    virtual ~PhotoRequirements();
    virtual void CheckSize(int width, int height) = 0;
    virtual string GetExtension()=0;
};

class VkPhotoRequirements: public PhotoRequirements
{
   public:
    VkPhotoRequirements();
    void CheckSize(int width, int height) override;
    string GetExtension() override;
};


class InstaPhotoRequirements : public PhotoRequirements
{
   public:
    InstaPhotoRequirements();
    void CheckSize(int width, int height) override;
    string GetExtension() override;
};


class TelegramPhotoRequirements : public PhotoRequirements
{
   public:
    TelegramPhotoRequirements();
    void CheckSize(int width, int height) override;
    string GetExtension() override;
};

#endif /* PhotoRequirementsGenerator_hpp */
