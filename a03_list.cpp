#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
};

class List {
    node *head, *last;
    
    void delete_after_node(node* current);

    public:
    List();
    void push(int val);
    int pop();
    void print_list();
};

List::List() {
    last = head = NULL;
}

void List::push(int val) {
    node *temp = new node;
    temp->val = val;
    temp->next = NULL;

    if(last == NULL) {
        head = last = temp;     // need this when list is empty
    } else {
        last->next = temp;
        last = last->next;      // last = temp;
    }
}

void List::delete_after_node(node* current) {
    node *temp = current->next;
    current->next = current->next->next;
    delete temp;
}

int List::pop() {
    int val;

    if(head->next == NULL) {    // only one element in list
        val = last->val;
        delete head;
        head = last = NULL;
    } else {
        val = last->val;
        node* current = head;
        while(current->next != last) {
            current = current->next;
        }
        delete_after_node(current);
        last = current;
    }

    return val;
}

void List::print_list() {
    node *current = head;
    cout << '[';
    while(current != NULL) {
        cout << current->val << ' ';

        current = current->next;
    }

    cout << ']' << endl;
}

int main() {
    List l;

    l.push(5);
    l.print_list();

    return 0;
}