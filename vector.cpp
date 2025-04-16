#include <iostream>
#include <vector>
using namespace std;

void output_vector_values(vector<int> v);
void reverse_output_vector_values(vector<int> v);

int main() {
    vector<int> marks;      // a vector is essentially python's list

    for(int i = 1; i <= 5; i++) 
        marks.push_back(i * 10);

    // alternatively
    // vector<int> marks{10, 20, 30, 40, 50};

    cout << "At index 1:  " << marks[1] << endl;

    output_vector_values(marks);
    reverse_output_vector_values(marks);

    // let's remove a value from a specific position
    // auto it = v.begin();
    vector<int>::iterator it = marks.begin();
    marks.erase(it + 2);

    output_vector_values(marks);

    return 0;
}

void output_vector_values(vector<int> v) {
    // use v.begin() to get a pointer to the start
    // (but this isn't an int *) ... It's a really weird pointer called "iterator" 
    // We don't know how to declare that. So, let's use the 'auto' keyword here
    
    cout << "[ ";
    for(vector<int>::iterator i = v.begin(); i != v.end(); i++) {
        cout << *i << ' ';
    }
    // for(auto i = v.begin(); i != v.end(); i++) {
    //     cout << *i << ' ';
    // }
    cout << ']' << endl;

    // alternatively
    cout << "[ ";
    for(int x : v) {        // sort of like the for loop in python
        cout << x << ' ';
    }
    cout << ']' << endl;
}

void reverse_output_vector_values(vector<int> v) {
    cout << "[ ";
    for(vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); i++) {
        cout << *i << ' ';
    }
    cout << ']' << endl;
}

