//
//  main.cpp
//  SingletonAndFactory
//
//  Created by Елизавета Шимкович on 26.04.23.
//

#include <iostream>
#include "Settings.hpp"
#include "PhotoRequirementsGenerator.hpp"
#include "LinkGenerator.hpp"
using namespace std;

void PrintMenu()
{
    cout << "0 - VK\n";
    cout << "1 - Instagram\n";
    cout << "2 - Telegram\n";
}

string pl[3] = {"VK", "Instagram", "Telegram"};

int main(int argc, const char * argv[])
{
    Settings* settings = Settings::getInstance();
    int button =0;
    PrintMenu();
    bool flag = true;
    while (flag)
    {
        cout << "Choose your platform: ";
        cin >> button;
        if (button>2)
        {
            cout << "\nError\n";
            PrintMenu();
        }
        else if (button<0)
        {
            cout << "Error\n";
            PrintMenu();
        }
        else
        {
            flag = false;
        }
    }
    settings->SetPlatform(static_cast<Platform>(button));
    
    cout << "\nLets make your own link in selected platform " << endl;
    string nick;
    cout << "Enter your nickname: ";
    cin >> nick;
    LinkGenerator * nickgen = settings->CreateLinkGenerator();
    cout << "Your personal link in " << pl[button] << ": " << nickgen->GetFormattedLink(nick) << endl;
    
    cout << "\nLets check the size of your photo" << endl;
    int width;
    cout << "Enter width of your photo (px): ";
    cin >> width;
    int height;
    cout << "Enter height of your photo (px): ";
    cin >> height;
    PhotoRequirements * req = settings->CreatePhotoRequirements();
    req->CheckSize(width, height);
    
    cout << "\nThe valid extension of photo for " << pl[button] << ": " << req->GetExtension()<< endl;
    return 0;
}
