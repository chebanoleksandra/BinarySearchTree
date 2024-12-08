#pragma once
template<typename T>
class Tree
{
    class Node
    {
    public:
        T value;
        Node* left;
        Node* right;
        Node() :value(T()),
            left(nullptr),
            right(nullptr) {};
        Node(T value) :value(value),
            left(nullptr),
            right(nullptr) {};
        Node(T value, Node* right, Node* left);
    };
private:
    Node* root;
    void Insert(Node*& node, T value);
    void Print(Node* node) const;
    bool Find(Node* node, T value) const;
    void Erase(Node*& node, T value);
    void Clear(Node*& node);
    void Copy(Node*& node, Node* other);
public:
    Tree() :root(nullptr) {};
    Tree(const Tree& obj);
    void Insert(T value);
    void Print() const;
    bool Find(T value) const;
    void Erase(T value);
    Tree& operator=(const Tree& obj);
    ~Tree();
};

#include <iostream>
#include "Tree.h"
using namespace std;

template<typename T>
Tree<T>::Tree(const Tree& obj)
{
    root = nullptr;
    if (obj.root) {
        Copy(root, obj.root);
    }
}

template<typename T>
inline Tree<T>::Node::Node(T value, Node* right, Node* left)
    :value(value),
    right(right),
    left(left) {};

template<typename T>
void Tree<T>::Insert(Node*& node, T value) {
    if (!node)
    {
        node = new Node(value);
        return;
    }
    if (value > node->value)
        Insert(node->right, value);
    else if (value < node->value)
        Insert(node->left, value);
}

template<typename T>
void Tree<T>::Print(Node* node) const {
    if (!node) return;
    Print(node->left);
    cout << node->value << " ";
    Print(node->right);
}

template<typename T>
bool Tree<T>::Find(Node* node, T value) const {
    if (!node) return false;
    if (node->value == value)
        return true;
    if (value > node->value)
        Find(node->right, value);
    else if (value < node->value)
        Find(node->left, value);
    else
        return false;
}

template<typename T>
void Tree<T>::Erase(Node*& node, T value) {
    if (!node)
        return;
    if (value > node->value)
        Erase(node->right, value);
    else if (value < node->value)
        Erase(node->left, value);
    else
    {
        if (!node->left && !node->right) {
            delete node;
            node = nullptr;
        }
        else if (!node->left) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        else if (!node->right) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        else {
            Node* minimal = node->right;
            while (minimal->left) {
                minimal = minimal->left;
            }
            node->value = minimal->value;
            Erase(node->right, minimal->value);
        }
    }
}

template<typename T>
void Tree<T>::Clear(Node*& node) {
    if (!node) return;
    Clear(node->left);
    Clear(node->right);
    delete node;
    node = nullptr;
}

template<typename T>
void Tree<T>::Copy(Node*& node, Node* other) {
    if (!other) {
        other = nullptr;
        return;
    }
    node = new Node(other->value);
    Copy(node->left, other->left);
    Copy(node->right, other->right);
}



template<typename T>
void Tree<T>::Insert(T value) {
    if (root == nullptr)
    {
        root = new Node(value);
    }
    else
    {
        Insert(root, value);
    }
}

template<typename T>
void Tree<T>::Print() const {
    Print(root);
    cout << endl;
}

template<typename T>
bool Tree<T>::Find(T value) const {
    return Find(root, value);
}

template<typename T>
void Tree<T>::Erase(T value) {
    Erase(root, value);
}

template<typename T>
Tree<T>& Tree<T>::operator=(const Tree& obj) {
    if (this == &obj)
    {
        return *this;
    }
    Clear(root);
    if (obj.root) {
        Copy(root, obj.root);
    }
    return *this;
}

template<typename T>
Tree<T>::~Tree()
{
    Clear(root);
}