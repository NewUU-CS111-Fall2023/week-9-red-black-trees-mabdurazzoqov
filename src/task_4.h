#ifndef TASK_4_H
#define TASK_4_H

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
    void deleteNode(int x);
    void insertFix(Node* x);
    void deleteFix(Node* x);
    void reverseTree(); // New method to reverse the tree
};

#endif