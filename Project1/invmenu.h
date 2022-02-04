// invmenu.h
#include <string>
#include "bookinfo.h"
#pragma once

using namespace std; 

class Invmenu
{
    public:
        void displayInventoryMenu();
        void getUserChoice(); 
        void findBook();
        void addBook();
        void editBookRecord();
        void deleteBook();
        void returnToMain();
};