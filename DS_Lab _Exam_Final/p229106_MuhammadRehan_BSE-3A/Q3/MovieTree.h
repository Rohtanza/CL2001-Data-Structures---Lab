//
// Created by rohtanza on 12/12/23.
//

#ifndef Q3_MOVIETREE_H
#define Q3_MOVIETREE_H


#include <iostream>
#include <climits>
#include <queue>

using namespace std;

template<typename T>
class MOVIETREE {
    class Node {
    public:
        T value;
        Node *left;
        Node *right;
        unsigned int height;
    public:
        explicit Node(T value) : value(value), left(nullptr), right(nullptr), height(0) {}

    };

    Node *root;

public:

    void Delete(T value);

    void insert(T value);

    void displayTree();

    bool isEmpty();

    string searchNode(T value);

    void inOrder();

    Node *successor(T value);

    Node *predecessor(T value);

    MOVIETREE() : root(nullptr) {}

private:

    Node *successor(Node *root, T value);

    Node *predecessor(Node *root, T value);

    Node *insert(Node *node, T value);

    unsigned int height(Node *node);

    void display(Node *node, int level);

    Node *search(Node *root, T value);

    void inOrder(Node *node);

    Node *deleteNode(Node *root, T delvalue);


};

template<typename T>
typename MOVIETREE<T>::Node *MOVIETREE<T>::insert(typename MOVIETREE<T>::Node *node, T value) {

    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    }
    node->height = 1 + max(height(node->left), height(node->right));
    return node;;

}

template<typename T>
void MOVIETREE<T>::insert(T value) {
    root = insert(root, value);
}


template<typename T>
typename MOVIETREE<T>::Node *MOVIETREE<T>::deleteNode(MOVIETREE::Node *root, T delvalue) {
    if (root == NULL)
        return root;
    if (root->value > delvalue) {
        root->left = deleteNode(root->left, delvalue);
        return root;
    } else if (root->value < delvalue) {
        root->right = deleteNode(root->right, delvalue);
        return root;
    }
    if (root->left == NULL) {
        Node *temp = root->right;
        delete root;
        return temp;
    } else if (root->right == NULL) {
        Node *temp = root->left;
        delete root;
        return temp;
    } else {
        Node *succParent = root;
        Node *succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        root->value = succ->value;
        delete succ;
        return root;
    }
}

template<typename T>
void MOVIETREE<T>::Delete(T value) {
    root = deleteNode(root, value);
}


template<typename T>
void MOVIETREE<T>::inOrder(MOVIETREE::Node *node) {
    if (node == nullptr)
        return;
    inOrder(node->left);
    cout << node->value << " ";
    inOrder(node->right);

}

template<typename T>
void MOVIETREE<T>::inOrder() {
    inOrder(root);
}


template<typename T>
typename MOVIETREE<T>::Node *MOVIETREE<T>::search(MOVIETREE::Node *root, T value) {

    if (root == nullptr || root->value == value) return root;

    if (value < root->value)
        return search(root->left, value);
    else return search(root->right, value);

}

template<typename T>
string MOVIETREE<T>::searchNode(T value) {
    Node *temp = search(root, value);
    if (temp == nullptr) return "Not found";
    else return (to_string(temp->value) + " found");
}


template<typename T>
bool MOVIETREE<T>::isEmpty() {
    return root == nullptr;
}

template<typename T>
void MOVIETREE<T>::display(MOVIETREE::Node *node, int level) {

    if (node == nullptr)
        return;

    display(node->right, level + 1);

    if (level != 0) {
        for (int i = 0; i < level - 1; ++i) {
            cout << "| \t\t";
        }
        cout << "----->" << node->value << endl;
    } else cout << node->value << endl;
    display(node->left, level + 1);

}

template<typename T>
void MOVIETREE<T>::displayTree() {
    display(root, 0);
}

template<typename T>
unsigned int MOVIETREE<T>::height(MOVIETREE::Node *node) {
    if (node == nullptr)
        return -1;
    return node->height;
}

template<typename T>
typename MOVIETREE<T>::Node *MOVIETREE<T>::predecessor(MOVIETREE::Node *root, T value) {
    Node *pre = nullptr;
    while (root) {
        if (root->value < value) {
            pre = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return pre;
}

template<typename T>
typename MOVIETREE<T>::Node *MOVIETREE<T>::predecessor(T value) {
    return predecessor(root, value);
}

template<typename T>
typename MOVIETREE<T>::Node *MOVIETREE<T>::successor(MOVIETREE::Node *root, T value) {
    return successor(root, value);
}


template<typename T>
typename MOVIETREE<T>::Node *MOVIETREE<T>::successor(T value) {
    Node *succ = nullptr;
    while (root) {
        if (root->value > value) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return succ;
}


#endif //Q3_MOVIETREE_H
