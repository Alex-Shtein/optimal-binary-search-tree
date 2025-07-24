#ifndef IMPL_OPTIMAL_BINARY_TREE_H
#define IMPL_OPTIMAL_BINARY_TREE_H

#include "../OptimalBinarySearchTree.h"

template <typename T>
OptimalBinarySearchTree<T>::TreeNode::TreeNode(T value, TreeNode *left, TreeNode *right)
    : _value(value), _left(left), _right(right) {}

template <typename T>
OptimalBinarySearchTree<T>::TreeNode::~TreeNode()
{
    delete _left;
    delete _right;
}

template <typename T>
T OptimalBinarySearchTree<T>::TreeNode::GetValue()
{
    return _value;
}

template <typename T>
typename OptimalBinarySearchTree<T>::TreeNode *OptimalBinarySearchTree<T>::TreeNode::GetLeft()
{
    return _left;
}

template <typename T>
typename OptimalBinarySearchTree<T>::TreeNode *OptimalBinarySearchTree<T>::TreeNode::GetRight()
{
    return _right;
}

template <typename T>
void OptimalBinarySearchTree<T>::TreeNode::SetValue(T value)
{
    _value = value;
}

template <typename T>
void OptimalBinarySearchTree<T>::TreeNode::SetLeft(TreeNode *left)
{
    _left = left;
}

template <typename T>
void OptimalBinarySearchTree<T>::TreeNode::SetRight(TreeNode *right)
{
    _right = right;
}

template <typename T>
typename OptimalBinarySearchTree<T>::TreeNode *OptimalBinarySearchTree<T>::FindParent(T value)
{
    TreeNode *current = _root;
    TreeNode *parent = nullptr;

    while (current != nullptr && current->GetValue() != value)
    {
        parent = current;
        current = (value < current->GetValue()) ? current->GetLeft() : current->GetRight();
    }

    return parent;
}

template <typename T>
void OptimalBinarySearchTree<T>::BuildOptimalBinarySearchTree(int *values, int **matrix, int leftValue, int rightValue)
{
    if (leftValue <= rightValue && rightValue != 0)
    {
        Insert(values[matrix[leftValue][rightValue] - 1]);

        if (leftValue < matrix[leftValue][rightValue])
        {
            BuildOptimalBinarySearchTree(values, matrix, leftValue, matrix[leftValue][rightValue] - 1);
        }

        if (matrix[leftValue][rightValue] < rightValue)
        {
            BuildOptimalBinarySearchTree(values, matrix, matrix[leftValue][rightValue] + 1, rightValue);
        }
    }
}

template <typename T>
typename OptimalBinarySearchTree<T>::TreeNode *OptimalBinarySearchTree<T>::Find(T value)
{
    TreeNode *current = _root;

    while (current != nullptr && current->GetValue() != value)
    {
        current = (value < current->GetValue()) ? current->GetLeft() : current->GetRight();
    }

    return current;
}

template <typename T>
OptimalBinarySearchTree<T>::OptimalBinarySearchTree(T *arr, int *success, int *failure, int size)
{
    _root = nullptr;
    int **R = new int *[size + 1];
    int **W = new int *[size + 1];
    int **P = new int *[size + 1];

    for (int i = 0; i <= size; ++i)
    {
        R[i] = new int[size + 1]();
        W[i] = new int[size + 1]();
        P[i] = new int[size + 1]();
        R[i][i] = i;
        W[i][i] = failure[i];
    }

    for (int l = 1; l < size + 1; ++l)
    {
        for (int i = 0; i < size + 1 - l; ++i)
        {
            int j = i + l;
            int minK = j;
            W[i][j] = W[i][j - 1] + success[j] + failure[j];
            int minSum = P[i][minK - 1] + P[minK][j] + W[i][minK - 1] + W[minK][j];

            for (int k = i + 1; k <= j; ++k)
            {
                int sum = P[i][k - 1] + P[k][j] + W[i][k - 1] + W[k][j];
                if (sum <= minSum)
                {
                    minSum = sum;
                    minK = k;
                }
            }

            R[i][j] = minK;
            P[i][j] = minSum;
        }
    }

    BuildOptimalBinarySearchTree(arr, R, 0, size);

    for (int i = 0; i <= size; ++i)
    {
        delete[] R[i];
        delete[] W[i];
        delete[] P[i];
    }
    delete[] R;
    delete[] W;
    delete[] P;
}

template <typename T>
bool OptimalBinarySearchTree<T>::Insert(const T &value)
{
    if (Contains(value))
    {
        return true;
    }

    TreeNode *parent = FindParent(value);
    TreeNode *node = new TreeNode(value, nullptr, nullptr);

    if (!parent)
    {
        _root = node;
    }

    else
    {
        if (value < parent->GetValue())
        {
            parent->SetLeft(node);
        }

        else
        {
            parent->SetRight(node);
        }
    }

    return true;
}

template <typename T>
bool OptimalBinarySearchTree<T>::Contains(const T &value)
{
    TreeNode *tree = Find(value);
    return tree != nullptr;
}

template <typename T>
bool OptimalBinarySearchTree<T>::Empty() const
{
    return !_root;
}

template <typename T>
std::vector<T> OptimalBinarySearchTree<T>::RoundRootLR()
{
    std::vector<T> result;
    std::vector<TreeNode *> TreeNodes;
    TreeNode *current = _root;
    result.push_back(current->GetValue());

    while (current || !TreeNodes.empty())
    {
        if (current->GetLeft())
        {
            result.push_back(current->GetLeft()->GetValue());
        }

        if (current->GetRight())
        {
            result.push_back(current->GetRight()->GetValue());
        }

        if (current->GetRight())
        {
            TreeNodes.push_back(current->GetRight());
        }

        if (current->GetLeft())
        {
            current = current->GetLeft();
        }

        else if (!TreeNodes.empty())
        {
            current = TreeNodes.back();
            TreeNodes.pop_back();
        }

        else
        {
            break;
        }
    }

    return result;
}

template <typename T>
void OptimalBinarySearchTree<T>::Output()
{
    if (_root)
    {
        Print(_root, "");
    }
}

template <typename T>
void OptimalBinarySearchTree<T>::Print(TreeNode *current, std::string padding)
{
    if (current->GetRight())
    {
        Print(current->GetRight(), padding + "     ");
    }

    std::cout << padding << current->GetValue() << std::endl;

    if (current->GetLeft())
    {
        Print(current->GetLeft(), padding + "     ");
    }
}

#endif