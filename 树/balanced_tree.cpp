#include <iostream>
#include <algorithm>
#include <cassert>


struct treeNode {
    struct treeNode *left;
    struct treeNode *right;
    int val;
};

typedef struct treeNode TreeNode;

class Solution {
private:
    bool balanced_;

    auto helper(TreeNode* root) -> int {
        if (root == nullptr)    return 0;
        if (root->left == nullptr && root->right == nullptr)    return 1;
        auto lefth = helper(root->left);
        auto righth = helper(root->right);
        if (std::abs(lefth-righth) > 1) {
            balanced_ = false;
        }
        return std::max(lefth,righth) + 1;
    }

public:
    auto IsBalanced_Solution(TreeNode* pRoot) -> bool {
        if (pRoot == nullptr) return true;
        if (pRoot->left == nullptr && pRoot->right == nullptr) return true;
        balanced_ = true;
        helper(pRoot);
        return balanced_;
    }

    auto test() -> void {
        // one or zero node
        auto a = new TreeNode{nullptr, nullptr, 0};
        assert(IsBalanced_Solution(nullptr) == true);
        assert(IsBalanced_Solution(a) == true);

        
        auto b = new TreeNode{a, nullptr, 1};
        // balanced but diff 1
        assert(IsBalanced_Solution(b) == true);

        // unbalanced
        auto c = new TreeNode{b, nullptr, 2};
        assert(IsBalanced_Solution(c) == false);

        // balanced
        auto d = new TreeNode{nullptr, nullptr, 3};
        b->right = d;
        assert(IsBalanced_Solution(b) == true);

        delete(a);
        delete(b);
        delete(c);
        delete(d);
    }

};


auto main() -> int {
    auto test = Solution();
    test.test();
    return 0;
}