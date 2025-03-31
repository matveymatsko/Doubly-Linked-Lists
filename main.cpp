#include <iostream>
#include "LinkedList.h"
#include "NodeIterator.h"
#include <iostream>
#include <algorithm>

int main()
{
    LinkedList<int> list;
    LinkedList<int> cloneList;

    ///tests out push_back, push_front, front, back, size and output the entire list
    list.push_back(5);
    list.push_front(10);
    std::cout << list.front() << std::endl;
    std::cout << list.back() << std::endl;
    std::cout << list.size() << std::endl;
    std::cout << list << std::endl;

    ///tests out clear, insert_after, and insert_before
    list.clear();
    list.push_back(4);
    list.insert_before(4, 9);
    list.insert_after(4,10);
    std::cout << list << std::endl;

    ///tests out pop front and back
    list.pop_back();
    list.pop_front();
    std::cout << list << std::endl;

    ///testing out the = operator (copy) and the += operator
    cloneList = list;
    cloneList += 5;
    std::cout << cloneList << std::endl;


    return 0;
}
