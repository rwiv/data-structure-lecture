#ifndef DATA_STRUCTURE_LECTURE_NODELISTTEST_H
#define DATA_STRUCTURE_LECTURE_NODELISTTEST_H


#include "iostream"
#include "NodeList.h"

using namespace std;

class NodeListTest {
public:
    static void run() {
        NodeList list = NodeList();

        list.insertFront("1st");
        list.insertFront("2nd");
        list.insertFront("3rd");

        NodeList::Iterator iterator1 = list.begin();
        cout << *iterator1 << endl;

        list.eraseFront();

        NodeList::Iterator iterator2 = list.begin();
        cout << *iterator2 << endl;
    }
};

#endif //DATA_STRUCTURE_LECTURE_NODELISTTEST_H
