#include <iostream>
#include <string>
using namespace std;

class Employee {
    public:
    string name;
    string cnic;
    int id;
    int salary;

    void sign_in();
    void sign_out();
    Employee();
    Employee(int salary);

    ~Employee();
};

void Employee::sign_in() {
    cout << "Signing in the employee : " + name << endl;
}

Employee::Employee(int salary) {
    cout << " - Employee instance being created with salary ... " << endl;
    this->salary = salary;
}

Employee::Employee() {
    cout << " - Employee instance being created ... " << endl;
    salary = 10000;
}

Employee::~Employee() {
    cout << " - Employee instance being removed!" << endl;
}

int main() {
    Employee *e;
    e = new Employee();
    delete e;
    e = new Employee(2000);

    cout << "Salary : " << e->salary << endl;

    delete e;
    e = NULL;

    cout << "End of main ... " << endl;

    return 0;
}