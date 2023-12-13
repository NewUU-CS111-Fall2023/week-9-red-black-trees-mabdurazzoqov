#include "task_3.h"

void RedBlackTree::deleteNode(int x) {
    Node* z = root;
    Node* parent = nullptr;
    while (z != nullptr) {
        if (z->data == x) {
            break;
        }
        parent = z;
        z = (z->data > x) ? z->left : z->right;
    }

    if (z == nullptr) {
        return;
    }

    Node* y;
    if (z->left == nullptr || z->right == nullptr) {
        y = z;
    } else {
        y = z->right;
        while (y->left != nullptr) {
            y = y->left;
        }
    }

    Node* x;
    if (y->left != nullptr) {
        x = y->left;
    } else {
        x = y->right;
    }

    if (x != nullptr) {
        x->parent = y->parent;
    }

    if (y->parent == nullptr) {
        root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    if (y != z) {
        z->data = y->data;
    }

    if (y->color == "BLACK") {
        deleteFix(x);
    }

    delete y;
}

void RedBlackTree::insertFix(Node* x) {
    while (x != root && x->parent->color == "RED") {
        if (x->parent == x->parent->parent->left) {
            Node* y = x->parent->parent->right;
            if (y != nullptr && y->color == "RED") {
                x->parent->color = "BLACK";
                y->color = "BLACK";
                x->parent->parent->color = "RED";
                x = x->parent->parent;
            } else {
                if (x == x->parent->right) {
                    x = x->parent;
                    leftRotate(x);
                }
                x->parent->color = "BLACK";
                x->parent->parent->color = "RED";
                rightRotate(x->parent->parent);
            }
        } else {
            Node* y = x->parent->parent->left;
            if (y != nullptr && y->color == "RED") {
                x->parent->color = "BLACK";
                y->color = "BLACK";
                x->parent->parent->color = "RED";
                x = x->parent->parent;
            } else {
                if (x == x->parent->left) {
                    x = x->parent;
                    rightRotate(x);
                }
                x->parent->color = "BLACK";
                x->parent->parent->color = "RED";
                leftRotate(x->parent->parent);
            }
        }
    }
    root->color = "BLACK";
}

void RedBlackTree::deleteFix(Node* x) {
    while (x != root && x->color == "BLACK") {
        if (x == x->parent->left) {
            Node* w = x->parent->right;
            if (w->color == "RED") {
                w->color = "BLACK";
                x->parent->color = "RED";
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == "BLACK" && w->right->color == "BLACK") {
                w->color = "RED";
                x = x->parent;
            } else {
                if (w->right->color == "BLACK") {
                    w->left->color = "BLACK";
                    w->color = "RED";
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = "BLACK";
                w->right->color = "BLACK";
                leftRotate(x->parent);
                x = root;
            }
        } else {
            Node* w = x->parent->left;
            if (w->color == "RED") {
                w->color = "BLACK";
                x->parent->color = "RED";
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == "BLACK" && w->left->color == "BLACK") {
                w->color = "RED";
                x = x->parent;
            } else {
                if (w->left->color == "BLACK") {
                    w->right->color = "BLACK";
                    w->color = "RED";
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = "BLACK";
                w->left->color = "BLACK";
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = "BLACK";
}