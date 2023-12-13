#include "task_10.h"

void BinarySearchTree::Insert(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (root == nullptr) {
        root = newNode;
    } else {
        Node* current = root;
        while (true) {
            if (x < current->data) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == nullptr) {
                    current->right = newNode;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

void BinarySearchTree::Delete(int x) {
    Node* parent = nullptr;
    Node* current = root;
    bool isLeftChild = false;

    while (current != nullptr) {
        if (current->data == x) {
            break;
        } else {
            parent = current;
            if (x < current->data) {
                current = current->left;
                isLeftChild = true;
            } else {
                current = current->right;
                isLeftChild = false;
            }
        }
    }

    if (current == nullptr) {
        return;
    }

    if (current->left == nullptr && current->right == nullptr) {
        if (current == root) {
            root = nullptr;
        } else if (isLeftChild) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete current;
    } else if (current->left == nullptr) {
        if (current == root) {
            root = current->right;
        } else if (isLeftChild) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        delete current;
    } else if (current->right == nullptr) {
        if (current == root) {
            root = current->left;
        } else if (isLeftChild) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        delete current;
    } else {
        Node* successor = current->right;
        Node* successorParent = current;

        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        if (successor != current->right) {
            successorParent->left = successor->right;
            successor->right = current->right;
        }

        if (current == root) {
            root = successor;
        } else if (isLeftChild) {
            parent->left = successor;
        } else {
            parent->right = successor;
        }

        successor->left = current->left;
        delete current;
    }
}

void BinarySearchTree::printInOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    printInOrder(node->left);
    std::cout << node->data << " ";
    printInOrder(node->right);
}

int BinarySearchTree::height(Node* node) {
    if (node == nullptr) {
        return -1;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return std::max(leftHeight, rightHeight) + 1;
}

int BinarySearchTree::depth(Node* node, int x) {
    if (node == nullptr) {
        return -1;
    }
    if (node->data == x) {
        return 0;
    }
    int leftDepth = depth(node->left, x);
    int rightDepth = depth(node->right, x);
    if (leftDepth == -1 && rightDepth == -1) {
        return -1;
    } else if (leftDepth == -1) {
        return rightDepth + 1;
    } else {
        return leftDepth + 1;
    }
}