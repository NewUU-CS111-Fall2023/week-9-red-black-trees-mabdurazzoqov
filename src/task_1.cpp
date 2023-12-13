#include "task_1.h"

void RedBlackTree::Insert(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->parent = nullptr;
    newNode->color = "BLACK";

    if (root == nullptr) {
        root = newNode;
    } else {
        Node* current = root;
        Node* parent = nullptr;
        while (current) {
            parent = current;
            current = (current->data > x) ? current->left : current->right;
        }

        if (current == nullptr) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        newNode->parent = parent;
    }
}

void RedBlackTree::printTreeRecursively(Node* node, std::string colorStr) {
    if (node == nullptr) {
        return;
    }

    std::cout << "(" << node->data << "(" << colorStr << ")" << std::endl;
    printTreeRecursively(node->left, "BLACK");
    printTreeRecursively(node->right, "BLACK");
}

void RedBlackTree::printTree() {
    std::vector<std::string> colors = {"BLACK", "RED"};
    Node* current = root;
    Node* parent = nullptr;
    while (current) {
        parent = current;
        current = (current->data > parent->data) ? current->left : current->right;
    }

    printTreeRecursively(current, colors[0]);
}