#ifndef DATA_STRUCTURE_LECTURE_SLINKEDLIST_H
#define DATA_STRUCTURE_LECTURE_SLINKEDLIST_H


#include "SNode.h"

template <typename E>
class SLinkedList {
public:
    SLinkedList(): head(nullptr) { };

    ~SLinkedList() {
        while (!empty()) {
            removeFront();
        }
    };

    bool empty() const { return head == nullptr; };
    const E& front() const { return head->elem; };

    void addFront(const E& elem) {
        SNode<E>* newNode = new SNode<E>;

        newNode->elem = elem;
        newNode->next = head;

        head = newNode;
    };

    void removeFront() {
        SNode<E>* targetNode = head;

        head = targetNode->next;

        delete targetNode;
    };

    string toString() {
        string result = "[ ";
        SNode<E> *curNode = head ? head : nullptr;

        while (curNode != nullptr) {
            result += curNode->elem;

            if (curNode->next != nullptr) {
                result += ", ";
            } else {
                result += " ]";
            }

            curNode = curNode->next;
        }

        return result;
    }
private:
    SNode<E>* head;
};

#endif //DATA_STRUCTURE_LECTURE_SLINKEDLIST_H