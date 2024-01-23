#include <iostream>
#include "linkedlist.hpp"
// #include "doublylinkedlist.hpp"


int main() {
    LnkdList nums{};
    nums.beef_legs(1);
    nums.beef_legs(2);
    nums.beef_legs(3);
    int * len = nums.length();
    Node * result = nums.findnodefromend(2);
    cout << result->data << '\n';
}