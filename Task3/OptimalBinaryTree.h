#ifndef OPTIMALBINARYTREE_H
#define OPTIMALBINARYTREE_H

#include <vector>
#include <string>
#include <iomanip>

template <typename T>
class OptimalBinaryTree
{
private:
    class TreeNode
    {
    public:
        TreeNode(T value, TreeNode *left, TreeNode *right);
        ~TreeNode();
        T GetValue();
        TreeNode *GetLeft();
        TreeNode *GetRight();
        void SetValue(T value);
        void SetLeft(TreeNode *left);
        void SetRight(TreeNode *right);

    private:
        T _value;
        TreeNode *_left;
        TreeNode *_right;
    };

    TreeNode *_root;
    TreeNode *FindParent(T value);
    void BuildOptimalBinaryTree(int *values, int **matrix, int leftvalue, int rightvalue);
    TreeNode *Find(T value);
    void Print(TreeNode *current, std::string padding);

public:
    OptimalBinaryTree(T *arr, int *success, int *failure, int size);
    bool Insert(const T &value);
    bool Contains(const T &value);
    bool Empty() const;
    std::vector<T> RoundRootLR();
    void Output();
};

#include "./impl/OptimalBinaryTree.h"

#endif