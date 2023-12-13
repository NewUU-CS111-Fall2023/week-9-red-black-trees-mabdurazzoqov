#ifndef TASK_9_H
#define TASK_9_H

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

    void Insert(int parent, int child);
    int countNodes(Node* node);
    void printSubtreeNodeCount();
};

#endif