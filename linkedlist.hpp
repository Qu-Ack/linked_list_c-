#include <iostream>
using namespace std;

// -- First Data Structure that we will be implementing in C++
class Node
{
public:
    int data;
    Node *next = NULL; // a pointer to a typeof Node Object which will contain the reference to the next node

    Node(int x)
        : data{x}
    {
        // cout << "Node Initialized with " << x << " as the data" << '\n';
    }
};

class LnkdList
{
    // private
    Node *head;
    Node *tail;

public:
    LnkdList() // constructors initializes the head and tail to null
        : head{NULL}, tail{NULL}
    {
        // cout << "Linked List Initialized with head as NULL and tail as NULL\n";
    }

    void beef_chest(int num)
    {
        Node *node = new Node({num});
        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->next = head;
            head = node;
        }

        // cout << "Successfully added " << num << " in the linked list\n";
    }

    void beef_meat(int num, int position)
    {
        Node *node = new Node({num});
        Node *tmp = head;
        if (position == 1)
        {
            beef_chest(num);
        }
        while (tmp != NULL)
        {
            position--;
            if (position == 1)
            {
                node->next = tmp->next;
                tmp->next = node;
                return;
            }

            tmp = tmp->next;
        }
        cout << "The position entered is bigger than the length of the list\n";
        cout << "ERR: The element could not be added!!\n";
    }

    void beef_legs(int num)
    {
        Node *node = new Node({num});
        Node *tmp = tail;
        if (tail == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tmp->next = node;
            tail = node;
        }
    }

    void slay_bitch()
    {
        Node *node = head;
        head = node->next;
        free(node);
    }

    void slay_chad()
    {
        Node *tmp = head;
        Node *prev = head;
        while (tmp->next != NULL)
        {
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = NULL;
        tail = prev;
    }

    void slay_trans(int position)
    {
        Node *tmp = head;
        Node *prev = head;

        if (position == 1)
        {
            slay_bitch();
        }
        while (position > 0)
        {
            if (position == 1)
            {
                prev->next = tmp->next;
                tmp->next = NULL;
                free(tmp);
            }
            position--;
            prev = tmp;
            tmp = tmp->next;
            if (tmp == NULL)
            {
                cout << "No Element at that position" << '\n';
                return;
            }
        }
    }

    void ishowmeat()
    {
        Node *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << "->";
            tmp = tmp->next;
        }
        cout << '\n';
    }

    void reverse()
    {
        Node *tmp = head;
        if (head == NULL)
        {
            cout << "No element in the list";
        }
        else if (head->next == NULL)
        {
            cout << "Can't reverse only one element in the list";
        }
        head = NULL;
        Node *prev = head;
        while (tmp != NULL)
        {
            Node *supernext = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = supernext;
        }
        head = prev;
    }

    void print_recursive(Node *tmp)
    {
        // recursion
        if (tmp->next == NULL)
        {
            return;
        }
        cout << "->" << tmp;
        print_recursive(tmp->next);
    }

    void reverse_recursive(Node *tmp, Node *prev)
    {
        if (tmp == NULL)
        {
            head = prev;
            return;
        }
        Node *a = tmp->next;
        tmp->next = prev;
        reverse_recursive(a, tmp);
    }

    int * length() {
        int * length = (int *)malloc(sizeof(int));
        if (head == NULL) {
            cout << "List is empty";
            return length;
        }
        Node *tmp = head;
        while(tmp != NULL) {
            (*length)++;
            tmp = tmp->next;
        }
        return length;
    }

    Node * findnodefromend(int n) {
        int *len = length();
        Node *tmp = head;
        for(int i = 0; i < *len - n;i++ ) {
            tmp = tmp->next;
        }
        return tmp;
    }
};