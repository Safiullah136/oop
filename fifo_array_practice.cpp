#include <iostream>
using namespace std;

#define SIZE 10

void pause();

template <class T>
class Queue {
    private:
    T q[SIZE];
    int in, out;
    bool is_empty, is_full;

    void inc(int *arrow);

    public:
    Queue();
    void enqueue(T val);
    T dequeue();

    void print_queue();
};

template <class T>
Queue<T>::Queue() {
    // for(int i = 0; i < SIZE; i++) {
    //     q[i] = 0;
    // }
    is_empty = true;
    is_full = false;
    in = out = 0;
}

template <class T>
void Queue<T>::inc(int *arrow) {
    if(*arrow + 1 == SIZE) {
        *arrow = 0;
    } else {
        *arrow += 1;
    }
}

template <class T>
void Queue<T>::enqueue(T val) {
    if(is_full) 
        throw "Queue full. Cannot enqueue ... ";
    
    q[in] = val;
    inc(&in);
    
    if(in == out) 
        is_full = true;

    is_empty = false;
}

template <class T>
T Queue<T>::dequeue() {
    if(is_empty) 
        throw "Queue empty. Cannot dequeue ... ";

    T val = q[out];
    inc(&out);
    
    if(in == out) 
        is_empty = true;

    is_full = false;

    return val;
}

template <class T>
void Queue<T>::print_queue() {
    cout << "[\t";
    for(int i = 0; i < SIZE; i++)
        cout << q[i] << '\t';
    cout << ']' << endl;

    cout << " \t";
    for(int i = 0; i < SIZE; i++)
        cout << i << '\t';
    cout << ' ' << endl;

    cout << ' ';
    for(int i = 0; i <= in; i++) 
        cout << '\t';
    cout << "^in" << endl;

    cout << ' ';
    for(int i = 0; i <= out; i++)
        cout << '\t';
    cout << "^out" << endl;

    pause();
}


int main() {
    Queue<int> que;

    que.print_queue();

    try {

        que.enqueue(5);
        que.print_queue();

        que.enqueue(11);
        que.print_queue();

        que.enqueue(22);
        que.print_queue();

        que.enqueue(33);
        que.print_queue();

        que.enqueue(44);
        que.print_queue();

        que.enqueue(55);
        que.print_queue();

    } catch(const char *msg) {
        cout << msg << endl;
    }

    try {

        cout << endl << "Now dequeue ... " << endl;
        cout << "Got val: " << que.dequeue() << endl;   que.print_queue();
        cout << "Got val: " << que.dequeue() << endl;   que.print_queue();
        cout << "Got val: " << que.dequeue() << endl;   que.print_queue();
        cout << "Got val: " << que.dequeue() << endl;   que.print_queue();
        cout << "Got val: " << que.dequeue() << endl;   que.print_queue();
        cout << "Got val: " << que.dequeue() << endl;   que.print_queue();

    } catch(const char *msg) {
        cout << msg << endl;
    }

    Queue<string> questring;

    questring.print_queue();

    try {

        questring.enqueue("Hi");
        questring.print_queue();

        questring.enqueue("How");
        questring.print_queue();

        questring.enqueue("are");
        questring.print_queue();

        questring.enqueue("you");
        questring.print_queue();

        questring.enqueue("My boy");
        questring.print_queue();

        questring.enqueue("Well");
        questring.print_queue();

    } catch(const char *msg) {
        cout << msg << endl;
    }

    try {

        cout << endl << "Now dequeue ... " << endl;
        cout << "Got val: " << questring.dequeue() << endl;   questring.print_queue();
        cout << "Got val: " << questring.dequeue() << endl;   questring.print_queue();
        cout << "Got val: " << questring.dequeue() << endl;   questring.print_queue();
        cout << "Got val: " << questring.dequeue() << endl;   questring.print_queue();
        cout << "Got val: " << questring.dequeue() << endl;   questring.print_queue();
        cout << "Got val: " << questring.dequeue() << endl;   questring.print_queue();

    } catch(const char *msg) {
        cout << msg << endl;
    }

    return 0;
}

void pause() {
    getchar();
}