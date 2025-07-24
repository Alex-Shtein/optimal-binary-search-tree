#include "../googletest/googletest/include/gtest/gtest.h"
#include "../Task3/OptimalBinaryTree.h"

TEST(OBST, Test1)
{
    int arr[] = {1, 2, 3, 4};
    int success[] = {0, 5, 4, 1, 7};
    int failure[] = {3, 8, 2, 9, 6};
    OptimalBinaryTree<int> tree(arr, success, failure, 4);
    auto result = tree.RoundRootLR();
    std::vector<int> expect = {2, 1, 4, 3};
    ASSERT_EQ(result, expect);
}

TEST(OBST, Test2)
{
    int arr[] = {2, 7, 9, 11};
    int success[] = {0, 3, 2, 4, 5};
    int failure[] = {0, 0, 0, 0, 0};
    OptimalBinaryTree<int> tree(arr, success, failure, 4);
    auto result = tree.RoundRootLR();
    std::vector<int> expect = {9, 2, 11, 7};
    ASSERT_EQ(result, expect);
    tree.Output();
}

TEST(OBST, Test3)
{
    int arr[] = {2, 5, 8};
    int success[] = {0, 1, 1, 1};
    int failure[] = {0, 0, 0, 0};
    OptimalBinaryTree<int> tree(arr, success, failure, 3);
    auto result = tree.RoundRootLR();
    std::vector<int> expect = {5, 2, 8};
    ASSERT_EQ(result, expect);
    tree.Output();
}

TEST(OBST, Test4)
{
    int arr[] = {2, 3, 4, 5, 7, 9, 11};
    int success[] = {0, 2, 1, 1, 9, 1, 7, 2};
    int failure[] = {0, 0, 0, 0, 0, 0, 0, 0};
    OptimalBinaryTree<int> tree(arr, success, failure, 7);
    auto result = tree.RoundRootLR();
    std::vector<int> expect = {5, 3, 9, 2, 4, 7, 11};
    ASSERT_EQ(result, expect);
    tree.Output();
}

TEST(OBST, Test7)
{
    int arr[] = {1, 2, 3, 4};
    int success[] = {0, 2, 1, 2, 1};
    int failure[] = {0, 0, 0, 0, 0};
    OptimalBinaryTree<int> tree(arr, success, failure, 4);
    auto result = tree.RoundRootLR();
    std::vector<int> expect = {3, 1, 4, 2};
    ASSERT_EQ(result, expect);
    tree.Output();
}
