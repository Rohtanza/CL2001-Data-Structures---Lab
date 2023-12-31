//
// Created by rohtanza on 11/27/23.
//

#ifndef ORGANIZATIONALHIERARCHYMANAGEMENT_HIERARCHYTREE_H
#define ORGANIZATIONALHIERARCHYMANAGEMENT_HIERARCHYTREE_H

#include <iostream>
#include <string>
#include <climits>

using namespace std;

struct Employee {
    int ID;
    string name;
    string designation;

    Employee(int id, const string &empName, const string &empDesignation)
            : ID(id), name(empName), designation(empDesignation) {}
};

class AVL {
private:
    class Node; // Forward declaration of our class Node

    Node *root = nullptr;

    Node *insertUtil(Node *head, Employee emp);

    Node *removeUtil(Node *head, int empID);

    Node *searchUtil(Node *head, int empID);

    void printTree(Node *node, string indent = "", bool last = true);

    int height(Node *head);

    int balance(Node *head);

    Node *rightRotate(Node *head);

    Node *leftRotate(Node *head);

    void display(Node *node, int level);


public:

    void displayTree();

    void insertEmployee(Employee emp);

    void removeEmployee(int empID);

    Employee *searchEmployee(int empID);

    void updateEmployee(int empID, const string &newName, const string &newDesignation);

    void displayOrganizationalChart();
};

struct AVL::Node {
public:
    Employee empData;
    int height;
    Node *left;
    Node *right;

    Node(Employee emp) : empData(emp), height(1), left(nullptr), right(nullptr) {}
};

int AVL::height(Node *head) {
    if (head == nullptr) {
        return 0;
    }
    return head->height;
}

int AVL::balance(Node *head) {
    if (head == nullptr) {
        return 0;
    }
    return height(head->left) - height(head->right);
}

AVL::Node *AVL::rightRotate(Node *head) {
    Node *newHead = head->left;
    Node *temp = newHead->right;

    // perform rotation
    newHead->right = head;
    head->left = temp;

    // update heights
    head->height = max(height(head->left), height(head->right)) + 1;
    newHead->height = max(height(newHead->left), height(newHead->right)) + 1;

    return newHead; // return the new root after rotation
}


AVL::Node *AVL::leftRotate(Node *head) {
    Node *newHead = head->right;
    Node *temp = newHead->left;

    // perform rotation
    newHead->left = head;
    head->right = temp;

    // update heights
    head->height = max(height(head->left), height(head->right)) + 1;
    newHead->height = max(height(newHead->left), height(newHead->right)) + 1;

    return newHead; // return the new root after rotation
}


AVL::Node *AVL::insertUtil(Node *head, Employee emp) {
    if (head == nullptr) {
        return new Node(emp);
    }

    if (emp.ID < head->empData.ID) {
        head->left = insertUtil(head->left, emp);
    } else if (emp.ID > head->empData.ID) {
        head->right = insertUtil(head->right, emp);
    } else {
        // handle the duplicate employee ids
        return head;
    }

    // update height of our current node
    head->height = 1 + max(height(head->left), height(head->right));

    // get the balance
    int balanceFactor = balance(head);

    // perform rotations if needed to balance our tree
    if (balanceFactor > 1 && emp.ID < head->left->empData.ID) {
        return rightRotate(head);
    }
    if (balanceFactor < -1 && emp.ID > head->right->empData.ID) {
        return leftRotate(head);
    }
    if (balanceFactor > 1 && emp.ID > head->left->empData.ID) {
        head->left = leftRotate(head->left);
        return rightRotate(head);
    }
    if (balanceFactor < -1 && emp.ID < head->right->empData.ID) {
        head->right = rightRotate(head->right);
        return leftRotate(head);
    }

    return head;
}


AVL::Node *AVL::removeUtil(Node *head, int empID) {
    if (head == nullptr) {
        return head;
    }

    if (empID < head->empData.ID) {
        head->left = removeUtil(head->left, empID);
    } else if (empID > head->empData.ID) {
        head->right = removeUtil(head->right, empID);
    } else {
        if (head->left == nullptr || head->right == nullptr) {
            Node *temp = head->left ? head->left : head->right;

            if (temp == nullptr) {
                temp = head;
                head = nullptr;
            } else {
                *head = *temp;
            }

            delete temp;
        } else {
            Node *temp = head->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }

            head->empData = temp->empData;
            head->right = removeUtil(head->right, temp->empData.ID);
        }
    }

    if (head == nullptr) {
        return head;
    }

    // update height of our current node
    head->height = 1 + max(height(head->left), height(head->right));

    // get the balance
    int balanceFactor = balance(head);

    // perform rotations if needed to balance our tree
    if (balanceFactor > 1 && balance(head->left) >= 0) {
        return rightRotate(head);
    }
    if (balanceFactor > 1 && balance(head->left) < 0) {
        head->left = leftRotate(head->left);
        return rightRotate(head);
    }
    if (balanceFactor < -1 && balance(head->right) <= 0) {
        return leftRotate(head);
    }
    if (balanceFactor < -1 && balance(head->right) > 0) {
        head->right = rightRotate(head->right);
        return leftRotate(head);
    }

    return head;
}


AVL::Node *AVL::searchUtil(Node *head, int empID) {
    if (head == nullptr || head->empData.ID == empID) {
        return head;
    }

    if (empID < head->empData.ID) {
        return searchUtil(head->left, empID);
    } else {
        return searchUtil(head->right, empID);
    }
}


void AVL::printTree(Node *node, string indent, bool last) {
    if (node != nullptr) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "     ";
        } else {
            cout << "L----";
            indent += "|    ";
        }
        cout << node->empData.name << " (" << node->empData.ID << ")" << endl;

        printTree(node->left, indent, false);
        printTree(node->right, indent, true);
    }
}


void AVL::insertEmployee(Employee emp) {
    root = insertUtil(root, emp);
}

void AVL::removeEmployee(int empID) {
    root = removeUtil(root, empID);
}

Employee *AVL::searchEmployee(int empID) {
    Node *resultNode = searchUtil(root, empID);
    if (resultNode != nullptr)
        return &(resultNode->empData);
    else
        return nullptr;
}

void AVL::updateEmployee(int empID, const string &newName, const string &newDesignation) {
    Employee *emp = searchEmployee(empID);
    if (emp != nullptr) {
        emp->name = newName;
        emp->designation = newDesignation;
    } else {
        cout << "Employee not found" << endl;
    }
}

void AVL::displayOrganizationalChart() {
    printTree(root);
}

void AVL::display(AVL::Node *node, int level) {
    if (node == nullptr)
        return;

    display(node->right, level + 1);

    if (level != 0) {
        for (int i = 0; i < level - 1; ++i) {
            cout << "| \t\t";
        }

        cout << "----->" << node->empData.name << " (" << node->empData.ID << ")" << endl;
    } else cout << node->empData.name << " (" << node->empData.ID << ")" << endl;
    display(node->left, level + 1);


}

void AVL::displayTree() {
    display(root, 0);


}


#endif //ORGANIZATIONALHIERARCHYMANAGEMENT_HIERARCHYTREE_H
