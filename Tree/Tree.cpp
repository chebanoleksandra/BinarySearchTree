#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree(const Tree& obj)
{
    root = nullptr;
    if (obj.root) {
        Copy(root, obj.root);
    }
}

Tree::Node::Node(int value, Node* right, Node* left)
    :value(value),
    right(right),
    left(left) {}

void Tree::Insert(Node*& node, int value)
{

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

void Tree::Print(Node* node) const {
    if (!node) return;
    Print(node->left);
    cout << node->value << " ";
    Print(node->right);
}

bool Tree::Find(Node* node, int value) const
{
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

void Tree::Erase(Node*& node, int value)
{
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

void Tree::Clear(Node*& node)
{
    if (!node) return;
    Clear(node->left);
    Clear(node->right);
    delete node;
    node = nullptr;
}

void Tree::Copy(Node*& node, Node* other)
{
    if (!other) {
        other = nullptr;
        return;
    }
    node = new Node(other->value);
    Copy(node->left, other->left);
    Copy(node->right, other->right);
}

void Tree::Insert(int value)
{
    if (root == nullptr)
    {
        root = new Node(value);
    }
    else
    {
        Insert(root, value);
    }
}

void Tree::Print() const {
    Print(root);
    cout << endl;
}

bool Tree::Find(int value) const
{
    return Find(root, value);
}

void Tree::Erase(int value)
{
    Erase(root, value);
}

Tree& Tree::operator=(const Tree& obj)
{
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

Tree::~Tree()
{
    Clear(root);
}
