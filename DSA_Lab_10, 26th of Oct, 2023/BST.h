//
// Created by rohtanza on 11/3/23.
//

#ifndef BST_BST_H
#define BST_BST_H

#include <iostream>
#include <climits>
#include <queue>
#include <utility>

using namespace std;

template<typename T>
class BST {
    class Node {
    public:
        T value;
        string gemName;
        Node *left;
        Node *right;
        unsigned int height;
    public:
        explicit Node(T value, string gemName) : gemName(std::move(gemName)), value(value), left(nullptr),
                                                 right(nullptr),
                                                 height(0) {}

    };

    Node *root;

    size_t size;
public:

    T deleteGem(T value);

    void insertGem(T value, string gemName);

    void displayTree();

    bool isEmpty();

    string searchNode(T value);

    void inOrder();

    void preOrder();

    void postOrder();

    string findMax();

    T findMix();

    Node *successor(T value);

    Node *predecessor(T value);

    void levelOrderTraversal();

    size_t getSize();

    BST() : root(nullptr), size(0) {}

private:

    Node *successor(Node *root, T value);

    Node *predecessor(Node *root, T value);

    void levelOrderTraversal(Node *root);

    Node *findMax(Node *root);

    T findMix(Node *root);

    Node *insert(Node *node, T value, string gemName);

    unsigned int height(Node *node);

    void display(Node *node, int level);

    Node *search(Node *root, T value);

    void inOrder(Node *node);

    void preOrder(Node *node);

    void postOrder(Node *node);

    Node *deleteNode(Node *root, T value);


};

template<typename T>
size_t BST<T>::getSize() {
    return size;
}

template<typename T>
typename BST<T>::Node *BST<T>::deleteNode(BST<T>::Node *root, T value) {
    if (root == nullptr)
        return root;
    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == nullptr) {
            Node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = successor(root, root->value);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

template<typename T>
T BST<T>::deleteGem(T value) {
    Node *temp = deleteNode(root, value);
    return temp->value;
}

template<typename T>
void BST<T>::levelOrderTraversal(BST::Node *root) {
    if (root == nullptr) {
        return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
}

template<typename T>
void BST<T>::levelOrderTraversal() {
    levelOrderTraversal(root);

}

template<typename T>
typename BST<T>::Node *BST<T>::predecessor(BST::Node *root, T value) {
    Node *pre = nullptr;
    while (root) {
        if (root->data < value) {
            pre = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return pre;
}

template<typename T>
typename BST<T>::Node *BST<T>::predecessor(T value) {
    return predecessor(root, value);
}

template<typename T>
typename BST<T>::Node *BST<T>::successor(BST::Node *root, T value) {
    return successor(root, value);
}


template<typename T>
typename BST<T>::Node *BST<T>::successor(T value) {
    Node *succ = nullptr;
    while (root) {
        if (root->data > value) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return succ;
}

template<typename T>
T BST<T>::findMix(BST::Node *root) {
    if (root == nullptr)
        return INT_MAX;
    else if (root->left == nullptr)
        return root->data;
    return findMin(root->left);
}

template<typename T>
typename BST<T>::Node *BST<T>::findMax(BST::Node *root) {
    if (root == nullptr)
        return root;
    else if (root->right == nullptr)
        return root;
    return findMax(root->right);
}

template<typename T>
T BST<T>::findMix() {
    return findMix(root);
}

template<typename T>
string BST<T>::findMax() {
    Node *temp = findMax(root);
    if (temp == nullptr) return "Not found";
    else return "[" + to_string(temp->value) + " " + temp->gemName + "]";
}

template<typename T>
void BST<T>::postOrder(BST::Node *node) {
    if (node == nullptr)
        return;
    postOrder(node->left);
    postOrder(node->right);
    cout << "[ " << node->value << "-" << node->gemName << " ]";

}

template<typename T>
void BST<T>::preOrder(BST::Node *node) {
    if (node == nullptr)
        return;
    cout << "[ " << node->value << "-" << node->gemName << " ]";
    preOrder(node->left);
    preOrder(node->right);
}

template<typename T>
void BST<T>::inOrder(BST::Node *node) {
    if (node == nullptr)
        return;
    inOrder(node->left);
    cout << "[ " << node->value << "-" << node->gemName << " ]";
    inOrder(node->right);

}

template<typename T>
void BST<T>::inOrder() {
    inOrder(root);
}

template<typename T>
void BST<T>::preOrder() {
    preOrder(root);
}

template<typename T>
void BST<T>::postOrder() {
    postOrder(root);
}


template<typename T>
typename BST<T>::Node *BST<T>::search(BST::Node *root, T value) {

    if (root == nullptr || root->value == value) return root;

    if (value < root->value)
        return search(root->left, value);
    else return search(root->right, value);

}

template<typename T>
string BST<T>::searchNode(T value) {
    Node *temp = search(root, value);
    if (temp == nullptr) return "Not found";
    else return "[" + to_string(temp->value) + " " + temp->gemName + "]";
}


template<typename T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}

template<typename T>
void BST<T>::display(BST::Node *node, int level) {

    if (node == nullptr)
        return;

    display(node->right, level + 1);

    if (level != 0) {
        for (int i = 0; i < level - 1; ++i) {
            cout << "| \t\t";
        }
        cout << "----->" << node->value << "-" << node->gemName << endl;
    } else cout << node->value << "-" << node->gemName << endl;
    display(node->left, level + 1);

}

template<typename T>
void BST<T>::displayTree() {
    display(root, 0);
}

template<typename T>
unsigned int BST<T>::height(BST::Node *node) {
    if (node == nullptr)
        return -1;
    return node->height;
}

template<typename T>
typename BST<T>::Node *BST<T>::insert(typename BST<T>::Node *node, T value, string gemName) {

    if (node == nullptr) {
        size++;
        return new Node(value, gemName);
    }
    if (value < node->value) {
        node->left = insert(node->left, value, gemName);
    } else if (value > node->value) {
        node->right = insert(node->right, value, gemName);
    }
    node->height = 1 + max(height(node->left), height(node->right));
    return node;

}

template<typename T>
void BST<T>::insertGem(T value, string gemName) {
    root = insert(root, value, gemName);
}


#endif //BST_BST_H
