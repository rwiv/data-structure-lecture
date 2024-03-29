#ifndef DATA_STRUCTURE_LECTURE_LINKEDBINARYTREE_H
#define DATA_STRUCTURE_LECTURE_LINKEDBINARYTREE_H


#include "vector"
#include "BinaryNode.h"
#include "BinaryPosition.h"

template <typename E>
class LinkedBinaryTree {
protected:
    typedef BinaryNode<E> Node;
    typedef BinaryPosition<E> Position;
    typedef typename vector<BinaryPosition<E>>::iterator Iterator;

    Node *root;
    int length;
public:
    LinkedBinaryTree(): length(0) {}
    ~LinkedBinaryTree() {
        vector<Position> *positions = getPositions(Traversal::PREORDER);

        for (Iterator iter = positions->begin(); iter != positions->end(); ++iter) {
            Node *node = (*iter).getNode();
            delete node;
        }
    }

    int getLength() { return length; }
    bool isEmpty() { return length == 0; }
    Position getRoot() { return Position(root); }
    
    void addRoot() {
        root = new Node();
        length = 1;
    }

    void printTree(Traversal traversal) {
        vector<Position> *positions = getPositions(traversal);

        for (Iterator iter = positions->begin(); iter != positions->end(); ++iter) {
            cout << **iter;
            cout << " ";
        }
        cout << endl;

        delete positions;
    }

    vector<Position> *getPositions(Traversal traversal) {
        vector<Position> *positions = new vector<Position>();
        switch (traversal) {
            case PREORDER: pushPreorder(getRoot(), positions); break;
            case POSTORDER: pushPostorder(getRoot(), positions); break;
            case INORDER: pushInorder(getRoot(), positions); break;
        }

        return positions;
    }
private:
    void pushPreorder(Position target, vector<Position> *positions) {
        positions->push_back(target);

        if (target.getNode()->getLeft() != nullptr) {
            pushPreorder(target.getLeft(), positions);
        }

        if (target.getNode()->getRight() != nullptr) {
            pushPreorder(target.getRight(), positions);
        }
    }

    void pushPostorder(Position target, vector<Position> *positions) {
        if (target.getNode()->getLeft() != nullptr) {
            pushPostorder(target.getLeft(), positions);
        }

        if (target.getNode()->getRight() != nullptr) {
            pushPostorder(target.getRight(), positions);
        }

        positions->push_back(target);
    }

    void pushInorder(Position target, vector<Position> *positions) {
        if (target.getNode()->getLeft() != nullptr) {
            pushInorder(target.getLeft(), positions);
        }

        positions->push_back(target);

        if (target.getNode()->getRight() != nullptr) {
            pushInorder(target.getRight(), positions);
        }
    }
};

#endif //DATA_STRUCTURE_LECTURE_LINKEDBINARYTREE_H
