//
// Created by rohtanza on 10/19/23.
//

#ifndef DSA_LAB_09_TREE_H
#define DSA_LAB_09_TREE_H
#define One 1
#define Zero 0

#include <iostream>

enum Position {
    LEFT, RIGHT
};

using namespace std;

template<typename T>
class Tree {

    class Node {
        T value;
        Node *right;
        Node *left;

    public:
        Node(T value, Node *right = nullptr, Node *left = nullptr) : value(value), right(right), left(left) {}

        friend class Tree;
    };

    Node *root;

    friend class Node;


    bool setLeft(Node *node, T key) {
        if (node->left == nullptr) {
            node->left = new Node{key, nullptr, nullptr};
            return true;
        } else return false;
    }

    bool setRight(Node *node, T key) {
        if (node->right == nullptr) {
            node->right = new Node{key, nullptr, nullptr};
            return true;
        } else return false;
    }


    bool dummyinsert(Node *node, T key, Position pos) {
        if (pos == LEFT && node->left == nullptr) {
            node->left = new Node{key, nullptr, nullptr};
            return true;
        } else if (pos == RIGHT && node->right == nullptr) {
            node->right = new Node{key, nullptr, nullptr};
            return true;
        }
        return false;
    }


    void deleteTree(Node *node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }

    }

    void insert(Node *&node, T value) {
        if (nullptr == node)
            node = new Node{value, nullptr, nullptr};
        else if (value < node->value)
            insert(node->left, value);
        else
            insert(node->right, value);
    }

    Node *searchNode(T key, Node *node) {
        if (nullptr == node || node->value == key)
            return node;
        if (node->value < key)
            return searchNode(node->right, key);
        return searchNode(node->left, key);
    }

    void inOrder(Node *node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->value << "\t ";
            inOrder(node->right);
        }
    }

    void preOrder(Node *node) {
        if (node != nullptr) {
            cout << node->value << "\t ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void postOrder(Node *node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->value << "\t ";
        }
    }

    size_t depth(Node *node) {
        if (node == nullptr)
            return Zero;
        else {
            size_t leftDepth = depth(node->left);
            size_t rightDepth = depth(node->right);
            return max(leftDepth, rightDepth) + One;
        }
    }

    size_t findlevel(Node *node, T key, size_t level) {
        if (node == nullptr)
            return Zero;
        if (node->value == key)
            return level;
        auto nodeLevel = findlevel(node->left, key, level + One);
        if (nodeLevel != Zero)
            return nodeLevel;
        return findlevel(node->right, key, level + One);
    }

public:
    Tree() : root(nullptr) {}

    void dummyInsert() {
        T value, node;
        auto pos(0);
        cout << "Enter value :", cin >> value;
        cout << " Enter the node's value to attach it with :", cin >> node;
        cout << "Enter 0 to put it on left and 1 to put in on right", cin >> pos;
        if (pos == LEFT)
            if (setLeft( (node), value)) { cout << "Node attached." << endl; }
            else cout << "Already a node exits." << endl;
        if (pos == RIGHT)
            if (setRight(searchNode(node), value)) { cout << "Node attached." << endl; }
            else cout << "Already a node exits." << endl;
    }

    void insert(T value) {
        insert(root, value);
    }

    bool search(T value) {
        Node *node = searchNode(value, root);
        if (node == nullptr)
            return false;
        return true;

    }

    size_t depth() {
        return depth(root);
    }

    size_t findlevel(T key) {
        return findlevel(root, key, One);
    }

    void deleteTree() {
        return deleteTree(root);
    }

    void transversal() {
        char option('0');
        cout << "1. for InOrder | 2. for PreOrder |3. for PostOrder =>", cin >> option;
        switch (option) {
            case '1':
                inOrder(root);
                break;
            case '2':
                preOrder(root);
                break;
            case '3':
                postOrder(root);
                break;
            default:
                cout << "retry with a valid option" << endl;
                return;
        }
        cout << endl;
    }
};


#endif //DSA_LAB_09_TREE_H
