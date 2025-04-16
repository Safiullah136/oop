#include <iostream>
#include "first.h"
using namespace first;

namespace second {
    double var = 3.1416;
}

int main() {
    using namespace std;
    // using namespace first;
    // using namespace second;

    std::cout << var << std::endl;
    std::cout << second::var << std::endl;

    cout << var << endl;

    cout << ("Usman" == "usman") << endl;

    return 0;
}