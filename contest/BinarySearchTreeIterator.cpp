//
//  BinarySearchTreeIterator.cpp
//  contest
//
//  Created by andy on 14/4/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>

/**
 * Definition for binary tree
 * 这个题目不怎么测试理解
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        p = root;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return p != NULL;
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *tmp;
        int ret;
        while (p) {
            if (p->left) {
                ret = p->val;
                p = p->right;
                break;
            } else {
                tmp = p->left;
                while (tmp->right != NULL && tmp->right != p)
                    tmp = tmp->right;
                if (tmp->right == NULL) {
                    tmp->right = p;
                    p = p->left;
                }
                else {
                    ret = p->val;
                    tmp->right = NULL;
                    p = p->right;
                    break;
                }  
            }
        }
        return ret;
    }
    
    TreeNode *p;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */