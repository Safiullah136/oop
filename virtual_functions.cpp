#include <iostream>
#include <string>

#include "plugin.h"
#include "make_it_black.h" 
#include "make_it_white.h" 

using namespace std;

void init_matrix(int a[5][5]);
void output_matrix(int a[5][5]);
Plugin* select_plugin();

int main() {
    int pic[5][5];

    init_matrix(pic);

    cout << "Before: " << endl;
    output_matrix(pic);

    // Plugin p;
    // p.apply_filter(pic);

    // MakeItBlack mib;
    // mib.apply_filter(pic);

    // cout << "After MakeItBlack: " << endl;
    // output_matrix(pic);

    // MakeItWhite miw;
    // miw.apply_filter(pic);

    // cout << "After MakeItWhite: " << endl;
    // output_matrix(pic);

    // init_matrix(pic);

    // return 0;

    Plugin *p;

    p = select_plugin();
    p->apply_filter(pic);
    cout << "After Plugin Application: " << endl;
    output_matrix(pic);

    return 0;
}

Plugin* select_plugin() {
    string plugin_name = "MIb";

    Plugin* p;
    if(plugin_name == "MIW") {
        p = new MakeItWhite;
    } else {
        p = new MakeItBlack;
    }

    return p;
}


void init_matrix(int a[5][5]) {
    int val = 0; 
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            a[i][j] = val;
            val += 1;
        }
    }
}

void output_matrix(int a[5][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << a[i][j] << ' ';
        }

        cout << endl;
    }
}