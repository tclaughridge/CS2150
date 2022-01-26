/**
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 9/30/21
 **/
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <string>

using namespace std;

stack<int> total;
TreeNode* deletion;

// Constructor
TreeCalc::TreeCalc() {
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
    cleanTree(deletion);
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
    if (tree != NULL) {
        cleanTree(tree->right);
        cleanTree(tree->left);
        delete tree;
    }
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    if (val == "+" || val == "-" || val == "*" || val == "/") {
        TreeNode* aNode = new TreeNode();
        aNode->value = val;

        aNode->right = expressionStack.top();
        if (expressionStack.size() > 0)
            expressionStack.pop();

        aNode->left = expressionStack.top();
        if (expressionStack.size() > 0)
            expressionStack.pop();

        expressionStack.push(aNode);
    }
    else {
        TreeNode* bNode = new TreeNode();
        bNode->value = val;
        expressionStack.push(bNode);
    }
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    if (tree != NULL) {
        cout << tree->value << " ";
        printPrefix(tree->left);
        printPrefix(tree->right);
    }
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    if (tree != NULL) {
        if (tree->left != NULL)
            cout << "( ";
        printInfix(tree->left);
        cout << tree->value << " ";
        printInfix(tree->right);
        if (tree->right != NULL)
            cout << ") ";
    }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    if (tree != NULL) {
        printPostfix(tree->left);
        printPostfix(tree->right);
        cout << tree->value << " ";
    }
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    if (tree->left != NULL)
        calculate(tree->left);
    if (tree->right != NULL)
        calculate(tree->right);

    if (tree->value == "+" || tree->value == "-" || tree->value == "*" || tree->value == "/") {
        if (tree->value == "+") {
            int num1 = total.top();
            if (!total.empty()) {
                total.pop();
            }
            int num2 = total.top();
            if (!total.empty()) {
                total.pop();
                total.push(num1 + num2);
            }
        }

        if (tree->value == "-") {
            int num1 = total.top();
            if (!total.empty()) {
                total.pop();
            }
            int num2 = total.top();
            if (!total.empty()) {
                total.pop();
                total.push(num2 - num1);
            }
        }

        if (tree->value == "*") {
            int num1 = total.top();
            if (!total.empty()) {
                total.pop();
            }
            int num2 = total.top();
            if (!total.empty()) {
                total.pop();
                total.push(num1 * num2);
            }
        }

        if (tree->value == "/") {
            int num1 = total.top();
            if (!total.empty()) {
                total.pop();
            }
            int num2 = total.top();
            if (!total.empty()) {
                total.pop();
                total.push(num2 / num1);
            }
        }
    }

    else {
        total.push(stoi(tree->value));
    }

    return total.top();
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int result = 0;
    deletion = expressionStack.top();
    result = calculate(expressionStack.top());
    expressionStack.pop();
    return result;
}