#include <iostream>


class Stack
{
    char p[50];
    int top = -1;

public:
    void push(char c)
    {
        if (top > 50 - 1)
        {
            std::cout << "Stack overflow" << '\n';
            return;
        }
        top++;
        p[top] = c;
    }

    char pop()
    {
        if (top == -1)
        {
            std::cout << "Stack is empty\n";
            return -1;
        }
        else
        {
            char res = p[top];
            top--;
            return res;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};