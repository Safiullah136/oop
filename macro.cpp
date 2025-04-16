#include <iostream>
using namespace std;

// #define INCLUDE_INVENTORY_MODULE

#ifdef INCLUDE_INVENTORY_MODULE
void show_inventory() {
    cout << "Showing Inventory ... " << endl;
}
#endif

#define SIZE 5
#define ABS(a) ((a) < 0 ? -(a) : a)

int main() {
    for(int i = 0; i < SIZE; i++) 
        cout << i << endl;

    cout << "SIZE" << endl;

    cout << "ABS Value : " << ABS(-25) << endl;

    show_inventory();

    return 0;
}