// invmenu.h
#include <string>
#include "bookinfo.h"
#pragma once

using namespace std; 
class Invmenu
{
    public:
        void invMenu();
        void handleUserChoice(); 
        void lookUpBook();
        void addBook();
        void editBook();
        void deleteBook();
};