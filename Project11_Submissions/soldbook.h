// Specification file for the 'BookData' Class
#ifndef SOLDBOOK_H
#define SOLDBOOK_H

#include <iostream>
#include "inventorybook.h"
using namespace std;

class SoldBook : public InventoryBook 
{
private:
    static double taxRate; 
    static double total; 
    int qtySold; 
    double tax; 
    double subtotal; 
public:
	SoldBook();	// the default constructor	
    double getTotal() {
        return total; 
    }

}
};
#endif