#include <iostream>
using namespace std;

template <class T>
class Queue {
    struct node {
        T val;
        node *next;
    };

    node *head, *last;
    public:
    Queue();
    void enqueue(T val);
    T dequeue();
    void print_queue();
};

template <class T>
Queue<T>::Queue() {
    head = last = NULL;
}

template <class T>
void Queue<T>::enqueue(T val) {
    node *temp = new node;
    temp->val = val;
    temp->next = NULL;
    
    if(head == NULL) {
        head = last = temp;
    } else {
        last->next = temp;
        last = temp;
    }
}

template <class T>
T Queue<T>::dequeue() {
    T val = head->val; 

    if(head->next == NULL) {
        delete head;
        head = last = NULL;
    } else {
        node *temp = head;
        head = head->next;
        delete temp;
    }

    return val;
}

template <class T>
void Queue<T>::print_queue() {
    node *current = head;
    cout << '[' << ' ';
    while(current != NULL) {
        cout << current->val << ' ';
        current = current->next;
    }
    cout << ']' << endl;
}

int main() {
    Queue<int> q;

    cout << "Creating integer queue ... " << endl;
    q.enqueue(5);
    q.enqueue(7);
    q.print_queue();

    q.dequeue();
    q.print_queue();

    cout << "Creating string queue ... " << endl;
    Queue<string> q2;
    // q2.enqueue(5);
    q2.enqueue("student_1");
    q2.enqueue("student_2");
    q2.print_queue();

    q2.dequeue();
    q2.print_queue();

    return 0;
}