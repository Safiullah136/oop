#include <iostream>
using namespace std;

void cut_slices(int pieces) {
    if(pieces == 1) {
        cout <<  "I cut " << pieces << "th piece." << endl;
        return;
    }

    cut_slices(pieces - 1);

    cout <<  "I cut " << pieces << "th piece." << endl;
}

void packet_pass(int routers) {
    if(routers == 1) {
        cout << "I passed from router " << routers << " to router " << routers + 1 << endl; 
        return;
    }

    packet_pass(routers - 1);

    cout << "I passed from router " << routers << " to router " << routers + 1 << endl; 
}

int main() {
    // cut_slices(50);
    packet_pass(30);
    return 0;
}