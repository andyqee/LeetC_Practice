//
//  236.cpp
//  contest
//
//  Created by ethon_qi on 8/3/2016.
//  Copyright © 2016 andy. All rights reserved.
//

#include <stdio.h>

//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//
//According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
//
//_______3______
///              \
//___5__          ___1__
///      \        /      \
//6      _2       0       8
///  \
//7   4
//For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#pragma mark - 注意这个和binary search Tree 的区别
#pragma mark - 这种和binary tree 相关的首先想到的 应该是递归的思路

#pragma mark 这个问题还需要 研究下

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || p == root || q == root) {
            return root;
        }
// 需要根据这个来画出 call stack 图
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right) {
            return root;
        }
        
        return left != nullptr ? left : right;
    }
};
