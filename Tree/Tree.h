#pragma once
class Tree
{
    class Node
    {
    public:
        int value;
        Node* left;
        Node* right;
        Node() :value(0),
            left(nullptr),
            right(nullptr) {};
        Node(int value) :value(value),
            left(nullptr),
            right(nullptr) {};
        Node(int value, Node* right, Node* left);
    };
private:
    Node* root;
    void Insert(Node*& node, int value);
    void Print(Node* node) const;
    bool Find(Node* node, int value) const;
    void Erase(Node*& node, int value);
    void Clear(Node*& node);
    void Copy(Node*& node, Node* other);
public:
    Tree() :root(nullptr) {};
    Tree(const Tree& obj);
    void Insert(int value);
    void Print() const;
    bool Find(int value) const;
    void Erase(int value);
    Tree& operator=(const Tree& obj);
    ~Tree();
};