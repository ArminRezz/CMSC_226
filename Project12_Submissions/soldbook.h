// Specification file for the 'BookData' Class
#ifndef SOLDBOOK_H
#define SOLDBOOK_H

#include <iostream>
#include "inventorybook.h"
using namespace std;

class SoldBook : public InventoryBook 
{
    private:
        static double TAX_RATE;
        int qtySold;
        double tax, subtotal;
        static double total;
    public:
        SoldBook();
        void setQtySold(int qtySold);
        double setTax();
        double setSubtotal();
        int getQtySold();
        double getTax();
        double getTotal();
        void addTotal(double total);
};
#endif