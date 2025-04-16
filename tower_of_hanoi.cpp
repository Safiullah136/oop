#include <iostream>
using namespace std;

void print_move(int disk, char from_rod, char to_rod) {
    cout << "Move disk " << disk << " from rod "  << from_rod << " to rod " << to_rod << endl;
}

void move_disk(int n, char from_rod, char to_rod, char aux_rod) {
    if(n == 1) {
        print_move(1, from_rod, to_rod);
        return;
    }

    move_disk(n-1, from_rod, aux_rod, to_rod);

    print_move(n, from_rod, to_rod);

    move_disk(n-1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 3;
    move_disk(n, 'A', 'C', 'B');
    return 0;
}