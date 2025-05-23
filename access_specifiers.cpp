#include <iostream>
using namespace std;

class Employee {
    protected:
    int pay_rate;

    public:
    void set_pay_rate(int pay_rate) {
        if(pay_rate > 14) {
            this->pay_rate = pay_rate;
        } else {
            cout << "Pay rate " << pay_rate << " not acceptable. Not Setting ... ";
        }
    }

    int get_pay_rate() {
        return pay_rate;
    }
};

class FacultyMember : public Employee {
    public:
    // if we override this method, that's an error
    // for this, we need to make the pay_rate "protected"
    void set_pay_rate(int pay_rate) {
            if(pay_rate > 25) {
                this->pay_rate = pay_rate;
            } else {
                cout << "Pay rate " << pay_rate << " not acceptable. Not Setting ... ";
            }
    }
};

int main() {
    Employee a;

    // a.pay_rate = 10;        // error

    a.set_pay_rate(15);
    cout << "Current Pay rate : " << a.get_pay_rate() << endl;

    a.set_pay_rate(11);
    cout << "Current Pay rate : " << a.get_pay_rate() << endl;

    a.set_pay_rate(20);
    cout << "Current Pay rate : " << a.get_pay_rate() << endl;

    cout << "Creating a FacultyMember instance ... " << endl;
    FacultyMember f;
    f.set_pay_rate(20);
    cout << "Current Pay rate : " << f.get_pay_rate() << endl;

    f.set_pay_rate(11);
    cout << "Current Pay rate : " << f.get_pay_rate() << endl;

    f.set_pay_rate(19);
    cout << "Current Pay rate : " << f.get_pay_rate() << endl;

    f.set_pay_rate(29);
    cout << "Current Pay rate : " << f.get_pay_rate() << endl;

    return 0;
}