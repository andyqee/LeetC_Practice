//
//  Binary Tree Inorder Traversal.cpp
//  contest
//
//  Created by andy on 21/5/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

//Given a binary tree, return the inorder traversal of its nodes' values.
//
//For example:
//Given binary tree {1,#,2,3},
//  1
//   \
//    2
//   /
//  3
// return [1,3,2].
//
//Note: Recursive solution is trivial, could you do it iteratively?

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> stack;
        
        TreeNode *cNode = root;
        
        while (!stack.empty() || cNode) {
            if (cNode) {
                stack.push(cNode);
                cNode = cNode->left;
            } else {
                TreeNode *node = stack.top();
                result.push_back(node->val);
                stack.pop();
                cNode = node->right;
            }
        }
        
        return result;
    }
};