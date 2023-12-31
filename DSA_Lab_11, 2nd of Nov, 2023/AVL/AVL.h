//
// Created by p22-9106 on 02/11/2023.
//

#ifndef DSA_LAB_TASK_09_AVL_H
#define DSA_LAB_TASK_09_AVL_H

#include <iostream>

using namespace std;

template<typename T>
class AVL {

    class node {
    public:
        T value;
        int height;
        node *left;
        node *right;

        node(T k) {
            height = 1;
            value = k;
            left = nullptr;
            right = nullptr;
        }
    };

    node *root = nullptr;
    int n; // Ma'am, this will keep the count of the nodes in our tree.
public:

    /*
     * As I can't provide my root in the main to
     * protect it, I have created some public
     * functions which will later call the real
     * methods of our class to keep the root protected.
     *
     * For example,
     *      insert public methode will only take value
     *      from the main, and then it will pass that
     *      value to our real methode, and then we will
     *      call the real methode with our root.
    */
    void insert(T x) {
        root = insertUtil(root, x);
    }

    void remove(T x) {
        root = removeUtil(root, x);
    }

    node *search(T x) {
        return searchUtil(root, x);
    }

    bool searchValue(T x) {
        if (search(x) == nullptr) return false;
        return true;
    }

    void inorder() {
        inorderUtil(root);
        cout << endl;
    }

    void FindMax() {
        cout << "Maximum :" << findMax(root) << endl;
    }

    void FindMin() {
        cout << "Minimum  :" << findMin(root) << endl;
    }

    void displayTree() {
        printTree(root);
    }

    bool updateValue(T x, T y) {
        update(x, y);
    }


private:
    int height(node *head) {
        if (head == nullptr) return 0;
        return head->height;
    }

    node *rightRotation(node *head) {
        node *newHead = head->left;
        head->left = newHead->right;
        newHead->right = head;
        head->height = 1 + max(height(head->left), height(head->right));
        newHead->height = 1 + max(height(newHead->left), height(newHead->right));
        return newHead;
    }

    node *leftRotation(node *head) {
        node *newHead = head->right;
        head->right = newHead->left;
        newHead->left = head;
        head->height = 1 + max(height(head->left), height(head->right));
        newHead->height = 1 + max(height(newHead->left), height(newHead->right));
        return newHead;
    }

    void inorderUtil(node *head) {
        if (head == nullptr) return;
        inorderUtil(head->left);
        cout << head->value << " ";
        inorderUtil(head->right);
    }

    node *insertUtil(node *head, T x) {
        if (head == nullptr) {
            n += 1;
            node *temp = new node(x);
            return temp;
        }
        if (x < head->value) head->left = insertUtil(head->left, x);
        else if (x > head->value) head->right = insertUtil(head->right, x);
        head->height = 1 + max(height(head->left), height(head->right));
        int bal = height(head->left) - height(head->right);
        if (bal > 1) {
            if (x < head->left->value) {
                return rightRotation(head);
            } else {
                head->left = leftRotation(head->left);
                return rightRotation(head);
            }
        } else if (bal < -1) {
            if (x > head->right->value) {
                return leftRotation(head);
            } else {
                head->right = rightRotation(head->right);
                return leftRotation(head);
            }
        }
        return head;
    }

    node *removeUtil(node *head, T x) {
        if (head == nullptr) return nullptr;
        if (x < head->value) {
            head->left = removeUtil(head->left, x);
        } else if (x > head->value) {
            head->right = removeUtil(head->right, x);
        } else {
            node *r = head->right;
            if (head->right == nullptr) {
                node *l = head->left;
                delete (head);
                head = l;
            } else if (head->left == nullptr) {
                delete (head);
                head = r;
            } else {
                while (r->left != nullptr) r = r->left;
                head->value = r->value;
                head->right = removeUtil(head->right, r->value);
            }
        }
        if (head == nullptr) return head;
        head->height = 1 + max(height(head->left), height(head->right));
        int bal = height(head->left) - height(head->right);
        if (bal > 1) {
            if (height(head->left) >= height(head->right)) {
                return rightRotation(head);
            } else {
                head->left = leftRotation(head->left);
                return rightRotation(head);
            }
        } else if (bal < -1) {
            if (height(head->right) >= height(head->left)) {
                return leftRotation(head);
            } else {
                head->right = rightRotation(head->right);
                return leftRotation(head);
            }
        }
        return head;
    }

    node *searchUtil(node *head, T x) {
        if (head == nullptr) return nullptr;
        T k = head->value;
        if (k == x) return head;
        if (k > x) return searchUtil(head->left, x);
        if (k < x) return searchUtil(head->right, x);
    }

    T findMax(node *root) {
        if (root == nullptr) {
            return INT_MIN;
        }
        T res = root->value;
        T right = findMax(root->right);
        if (right > res) {
            res = right;
        }
        return res;
    }

    T findMin(node *root) {
        if (root == nullptr) {
            return INT_MAX;
        }
        T res = root->value;
        T left = findMin(root->left);
        if (left < res) {
            res = left;
        }
        return res;
    }

public:
    void printTree(node *node, string indent = "", bool last = true) {
        if (node != nullptr) {
            cout << indent;
            if (last) {
                cout << "R----";
                indent += "     ";
            } else {
                cout << "L----";
                indent += "|    ";
            }
            cout << node->value << endl;
            printTree(node->left, indent, false);
            printTree(node->right, indent, true);
        }
    }

    void update(T x, T y) {
        node *newNode = searchUtil(root, x);
        if (newNode != nullptr) {
            newNode->value = y;
        } else {
            cout << "Node not found" << endl;
        }
    }


};


#endif //DSA_LAB_TASK_09_AVL_H
