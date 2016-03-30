//
//  Invert Binary Tree.cpp
//  contest
//
//  Created by andy on 9/7/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>

#warning 测试没通过

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        TreeNode *node = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(node);
        return root;
    }
    
    
};