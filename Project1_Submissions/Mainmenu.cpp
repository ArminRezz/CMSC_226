#include <iostream>

using namespace std; 
void showDub(int); 
int main() { 
    int x = 2; 
    showDub(x); 
    cout << x << endl; 
    return 0; 
} 

void showDub(int num) { 
    cout << (num * 2) << endl; 
}