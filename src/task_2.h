#ifndef TASK_2_H
#define TASK_2_H

#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    bool color; // Red or Black
};

class RedBlackTree {
public:
    Node* root;

    RedBlackTree() : root(nullptr) {}

    void Insert(int x);
    void printTreeRecursively(Node* node, std::string colorStr);
    void printTree();
    void leftRotate(Node* x);
    void rightRotate(Node* x);
};

#endif 