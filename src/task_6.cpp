#include "task_6.h"

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

int RedBlackTree::BlackHeight(Node* node) {
    if (node == nullptr) {
        return -1;
    }

    int leftHeight = BlackHeight(node->left);
    int rightHeight = BlackHeight(node->right);

    if (node->color == "BLACK") {
        return std::max(leftHeight, rightHeight) + 1;
    } else {
        return std::max(leftHeight, rightHeight);
    }
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