#ifndef TASK_1_H
#define TASK_1_H

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
};

#endif