// LowestCommonAncestor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

class Node
{
public:
    Node* left;
    Node* right;
    int data;

    Node(int d)
        : data(d)
        , left(nullptr)
        , right(nullptr)
    {}
};

Node* ArrayToTree(const std::vector<int>& v)
{
    if (v.size() == 0)
        return nullptr;
    Node* root = new Node(v[0]);
    std::queue<Node*> q;
    q.push(root);
    bool l = true;
    for (size_t i = 1; i < v.size(); ++i, l = !l)
    {
        Node* pNode = q.front();
        if (!l)
            q.pop();
        if (v[i] != -1)
        {
            if (l)
            {
                pNode->left = new Node(v[i]);
                q.push(pNode->left);
            }
            else
            {
                pNode->right = new Node(v[i]);
                q.push(pNode->right);
            }
        }
    }

    return root;
}

void FreeTree(Node* pNode)
{
    if (pNode == nullptr)
        return;

    FreeTree(pNode->left);
    FreeTree(pNode->right);

    delete pNode;
}

bool Find(Node* pNode, Node* p, Node* q)
{
    if (pNode == nullptr)
        return false;

    if (pNode == p || pNode == q)
        return true;

    return Find(pNode->left, p, q) || Find(pNode->right, p, q);
}

Node* FindTreeNode(Node* root, int value)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == value)
        return root;

    if (Node* pNode = FindTreeNode(root->left, value); pNode != nullptr)
        return pNode;

    return FindTreeNode(root->right, value);
}

Node* LowestCommonAncestor(Node* root, Node* p, Node* q)
{
    if (root == nullptr)
        return nullptr;

    if (p == q)
        return p;

    if (Find(root->left, p, q) && Find(root->right, p, q))
        return root;

    if (p == root && Find(root->left, p, q))
        return root;
    if (p == root && Find(root->right, p, q))
        return root;

    if (Node* pNode = LowestCommonAncestor(root->left, p, q))
        return pNode;

    return LowestCommonAncestor(root->right, p, q);
}

int main()
{
    while (true)
    {
        std::cout << "Number of nodes in the tree: ";
        int count = 0;
        std::cin >> count;
        if (count == 0)
            break;

        std::cout << "Values of the tree nodes: ";
        std::vector<int> v(count, 0);
        for (int i = 0; i < count; ++i)
            std::cin >> v[i];

        std::cout << "The indexes of the two nodes to find ancestor of: ";
        int pv = 0, qv = 0;
        std::cin >> pv >> qv;
        if (pv >= count || qv >= count)
        {
            std::cout << "There are only " << count << " nodes!" << std::endl;
            continue;
        }

        Node* root = ArrayToTree(v);

        Node* p = FindTreeNode(root, v[pv]);
        Node* q = FindTreeNode(root, v[qv]);

        Node* pNode = LowestCommonAncestor(root, p, q);
        std::cout << "The lowest ancester is: " << (pNode ? pNode->data : -1) << std::endl;
        FreeTree(root);
    }
}
