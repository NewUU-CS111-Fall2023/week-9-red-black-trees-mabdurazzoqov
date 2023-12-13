#include "task_8.h"

int RedBlackTree::countNodes(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return countNodes(node->left) + countNodes(node->right) + 1;
}

int RedBlackTree::median() {
    int totalNodes = countNodes(root);
    Node* current = root;
    Node* prev = nullptr;
    int count = 0;
    int target = (totalNodes + 1) / 2;

    while (current != nullptr) {
        if (current->left == nullptr) {
            count++;
            if (count == target) {
                if (totalNodes % 2 != 0 || (totalNodes % 2 == 0 && prev != nullptr)) {
                    return current->data;
                }
            }
            current = current->right;
        } else {
            prev = current->left;
            while (prev->right != nullptr && prev->right != current) {
                prev = prev->right;
            }
            if (prev->right == nullptr) {
                prev->right = current;
                current = current->left;
            } else {
                prev->right = nullptr;
                count++;
                if (count == target) {
                    if (totalNodes % 2 != 0 || (totalNodes % 2 == 0 && prev != nullptr)) {
                        return current->data;
                    }
                }
                prev = current;
                current = current->right;
            }
        }
    }
    return -1;
}