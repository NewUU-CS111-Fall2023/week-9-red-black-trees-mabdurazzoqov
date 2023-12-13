#include "task_9.h"

void RedBlackTree::Insert(int parent, int child) {
    Node* newNode = new Node();
    newNode->data = child;

    if (root == nullptr) {
        Node* parentNode = new Node();
        parentNode->data = parent;
        parentNode->children.push_back(newNode);
        root = parentNode;
    } else {
        Node* parentNode = nullptr;
        std::vector<Node*> queue;
        queue.push_back(root);

        while (!queue.empty()) {
            Node* current = queue.front();
            queue.erase(queue.begin());

            if (current->data == parent) {
                current->children.push_back(newNode);
                return;
            }

            for (Node* childNode : current->children) {
                queue.push_back(childNode);
            }
        }
    }
}

int RedBlackTree::countNodes(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return countNodes(node->left) + countNodes(node->right) + 1;
}

void RedBlackTree::printSubtreeNodeCount() {
    std::vector<Node*> queue;
    queue.push_back(root);

    while (!queue.empty()) {
        Node* current = queue.front();
        queue.erase(queue.begin());

        std::cout << current->data << " - " << countNodes(current) << " ";

        for (Node* childNode : current->children) {
            queue.push_back(childNode);
        }

        std::cout << std::endl;
    }
}