#include "task_7.h"

Node* RedBlackTree::search(int x) {
    Node* node = root;
    while (node != nullptr) {
        if (node->data == x) {
            return node;
        } else if (node->data > x) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return nullptr;
}

int RedBlackTree::height(Node* node) {
    if (node == nullptr) {
        return -1;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return std::max(leftHeight, rightHeight) + 1;
}

void RedBlackTree::printChildrenCount() {
    std::vector<Node*> queue;
    queue.push_back(root);

    while (!queue.empty()) {
        Node* current = queue.front();
        queue.erase(queue.begin());

        std::cout << current->data << " - " << current->children.size() << " ";

        for (Node* childNode : current->children) {
            queue.push_back(childNode);
        }

        std::cout << std::endl;
    }
}