#include "task_4.h"

void RedBlackTree::reverseTree() {
    reverseTreeUtil(root);
}

void RedBlackTree::reverseTreeUtil(Node* node) {
    if (node == nullptr) {
        return;
    }

    Node* temp = node->left;
    node->left = node->right;
    node->right = temp;

    if (node->left != nullptr) {
        reverseTreeUtil(node->left);
    }
    if (node->right != nullptr) {
        reverseTreeUtil(node->right);
    }
}