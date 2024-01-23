#include <iostream>

// implementation using linked list 

#include "linkedlist.hpp"


class Node {
    public:
        int data;
        Node *next;
        Node(int num)
        :data{num} {

        }
};

class Stack {
    Node * top = NULL;
    public:
        void push(int num) {
            Node *node = new Node({num});
            if (top == NULL) {
                top = node;
                return;
            }
            node->next = top;
            top = node;
        }

        void pop() {
            if (top == NULL) {
                cout << "list is empty" << '\n';
                return;
            }
            Node *tmp = top;
            top = tmp->next;
            delete(tmp);
        }
};