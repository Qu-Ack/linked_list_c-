#include <iostream>

class Node
{
    public:
        int data;
        Node *next = NULL;
        Node *prev = NULL;
        Node(int num)
            : data{num}
        {
        }
};

class DLL
{
    Node *head;

public:
    DLL()
        : head{NULL}
    {
    }

    void adde(int num)
    {
        Node *node = new Node({num});
        if (head == NULL)
        {
            head = node;
            return;
        }
        Node *tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = node;
        node->prev = tmp;
    }

    void insert(int data, int index) {
        Node *node = new Node({data});
        if (index == 1) {
            node->next = head;
            head->prev = node;
            head = node;
            return;
        }
        Node *tmp = head;
        for(int i = 1; i < index - 1; i++) {
            tmp = tmp->next;
            if (tmp == NULL) {
                std::cout << "List is not that big" << '\n';
                return;
            }
        }
        Node *supernext = tmp->next;
        node->next = supernext;
        supernext->prev = node;
        tmp->next = node;
        node->prev = tmp;
    }

    void print()
    {
        Node *tmp = head;
        while (tmp != NULL)
        {
            std::cout << tmp->data << "<>";
            tmp = tmp->next;
        }
        std::cout << '\n';
    }
};