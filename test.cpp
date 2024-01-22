#include <iostream>
// #include "linkedlist.hpp"
#include "doublylinkedlist.hpp"


int main() {
    DLL nums{};
    nums.adde(1);
    nums.adde(2);
    nums.adde(3);
    nums.insert(123, 2);
    nums.print();
}