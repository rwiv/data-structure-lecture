#ifndef DATA_STRUCTURE_LECTURE_DEQUESTACKTEST_H
#define DATA_STRUCTURE_LECTURE_DEQUESTACKTEST_H


#include "iostream"
#include "DequeStack.h"

using namespace std;

class DequeStackTest {
public:
    static void run() {
        DequeStack dequeStack = DequeStack();

        dequeStack.push("1st");
        dequeStack.push("2nd");
        dequeStack.push("3rd");

        cout << dequeStack.toString() << endl;
    }
};

#endif //DATA_STRUCTURE_LECTURE_DEQUESTACKTEST_H