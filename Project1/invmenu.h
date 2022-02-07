// invmenu.h
#include <string>
#include <vector>
#include "bookinfo.h"
#pragma once

using namespace std; 
class Invmenu
{
    vector<Bookinfo> books; 

    public:
        Invmenu();
        void displayInventoryMenu();
        void handleUserChoice(); 
        void lookUpBook();
        void addBook();
        void editBook();
        void deleteBook();
        // void displayAllbooks();
};