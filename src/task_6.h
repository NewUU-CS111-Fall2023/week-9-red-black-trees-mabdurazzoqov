#ifndef TASK_6_H
#define TASK_6_H

#include <iostream>
#include <vector>

struct Node {
    int data;
    std::vector<Node*> children;
    bool color; // Red or Black
};

class RedBlackTree {
public:
    Node* root;

    RedBlackTree() : root(nullptr) {}

    void Insert(int parent, int child);
    int BlackHeight(Node* node);
    void printChildrenCount();
};

#endif