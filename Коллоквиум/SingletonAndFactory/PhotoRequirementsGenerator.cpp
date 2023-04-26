//
//  PhotoRequirementsGenerator.cpp
//  SingletonAndFactory
//
//  Created by Елизавета Шимкович on 26.04.23.
//

#include "PhotoRequirementsGenerator.hpp"


using namespace std;
PhotoRequirements::PhotoRequirements() {}
PhotoRequirements::~PhotoRequirements() {}


VkPhotoRequirements::VkPhotoRequirements():PhotoRequirements() {}

void VkPhotoRequirements::CheckSize(int width, int height)
{
    if (width > 600 || height > 600 )
    {
        cout << "Photo should be not above 600px*600px" << endl;
    }
    else if (width <= 0 || height <= 0)
    {
        cout << "Height and width should be above 0 px" << endl;
    }
    else
    {
        cout << "Hurray!!! Size of your photo is correct for selected platform!" << endl;
    }
}

string VkPhotoRequirements::GetExtension()
{
    return ("png");
}


InstaPhotoRequirements::InstaPhotoRequirements():PhotoRequirements() {}

void InstaPhotoRequirements::CheckSize(int width, int height)
{
    if (width > 800 || height > 800 )
    {
        cout << "Photo should be not above 800px*800px";
    }
    else if (width <= 0 || height <= 0)
    {
        cout << "Height and width should be above 0 px";
    }
    else
    {
        cout << "Hurray!!! Size of your photo is correct for selected platform!" << endl;
    }
}

string InstaPhotoRequirements::GetExtension()
{
    return ("jpeg");
}


TelegramPhotoRequirements::TelegramPhotoRequirements():PhotoRequirements() {}

void TelegramPhotoRequirements::CheckSize(int width, int height)
{
    if (width > 1200 || height > 1200 )
    {
        cout << "Photo should be not above 1200px*1200px";
    }
    else if (width <= 0 || height <= 0)
    {
        cout << "Height and width should be above 0 px";
    }
    else
    {
        cout << "Hurray!!! Size of your photo is correct for selected platform!" << endl;
    }
}

string TelegramPhotoRequirements::GetExtension()
{
    return ("jpeg");
}
