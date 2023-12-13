/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include "task_1.h"
#include "task_2.h"
#include "task_3.h"
#include "task_4.h"
#include "task_5.h"
#include "task_6.h"
#include "task_7.h"
#include "task_8.h"
#include "task_9.h"
#include "task_10.h"


int main() {
    std::cout << "Task 1" << std::endl;
        RedBlackTree tree;
    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        int x;
        std::cin >> x;
        tree.Insert(x);
    }

    tree.printTree();



    std::cout << "Task 2" << std::endl;
        RedBlackTree tree;
    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        int x;
        std::cin >> x;
        tree.Insert(x);
    }

    tree.printTree();

    // Test leftRotate() and rightRotate()
    Node* node = tree.root->right;
    tree.leftRotate(node);
    tree.printTree();
    node = tree.root->left;
    tree.rightRotate(node);
    tree.printTree();






    std::cout << "Task 3" << std::endl;
    RedBlackTree tree;
    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        int x;
        std::cin >> x;
        tree.Insert(x);
    }

    tree.printTree();
    Node* node = tree.root->right;
    tree.leftRotate(node);
    tree.printTree();
    node = tree.root->left



    std::cout << "Task 4" << std::endl;
    RedBlackTree tree;
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int x;
        std::cin >> x;
        tree.Insert(x);
    }
    tree.printTree();
    tree.reverseTree();
    tree.printTree();

    std::cout << "Task 5" << std::endl;
    NaryTree tree;
    int N;
    std::cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        int parent, child;
        std::cin >> parent >> child;
        tree.Insert(parent, child);
    }
    tree.printChildrenCount();




    std::cout << "Task 6" << std::endl;
    RedBlackTree tree;
    int N;
    std::cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        int parent, child;
        std::cin >> parent >> child;
        tree.Insert(parent, child);
    }

    tree.printChildrenCount();






    std::cout << "Task 7" << std::endl;
    RedBlackTree tree;
    int N;
    std::cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        int parent, child;
        std::cin >> parent >> child;
        tree.Insert(parent, child);
    }

    tree.printTree();

    int searchValue;
    std::cin >> searchValue;

    Node* searchResult = tree.search(searchValue);
    if (searchResult == nullptr) {
        std::cout << searchValue << " is not found" << std::endl;
    } else {
        int searchHeight = tree.height(searchResult);
        std::cout << searchValue << " is found, its height is " << searchHeight << std::endl;
    }




    std::cout << "Task 8" << std::endl;
    RedBlackTree tree;
    int N;
    std::cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        int parent, child;
        std::cin >> parent >> child;
        tree.Insert(parent, child);
    }

    tree.printTree();

    int medianValue = tree.median();
    std::cout << medianValue << " is median" << std::endl;



     std::cout << "Task 9" << std::endl;
    RedBlackTree tree;
    int N;
    std::cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        int parent, child;
        std::cin >> parent >> child;
        tree.Insert(parent, child);
    }

    tree.printSubtreeNodeCount();



    std::cout << "Task 10" << std::endl;
    BinarySearchTree tree;
    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        int value;
        char comma;
        std::cin >> value >> comma;
        tree.Insert(value);
    }

    tree.printInOrder(tree.root);
    std::cout << std::endl;

    int treeHeight = tree.height(tree.root);
    std::cout << "Height of tree: " << treeHeight << std::endl;

    int depthOf3 = tree.depth(tree.root, 3);
    std::cout << "Depth of 3: " << depthOf3 << std::endl;

    tree.Delete(34);
    tree.Delete(62);
    tree.Delete(1);

    tree.printInOrder(tree.root);
    std::cout << std::endl;

    
    return 0;
}
