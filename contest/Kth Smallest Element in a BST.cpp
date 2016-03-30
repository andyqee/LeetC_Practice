//
//  Kth Smallest Element in a BST.cpp
//  contest
//
//  Created by andy on 6/7/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>

//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//Note:
//You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//
//Follow up:
//What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
//How would you optimize the kthSmallest routine?

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// how to hack this problem? how to analysis
// 这个方法好巧妙啊
// 如何分析这个方法的复杂度

// 递归的方法
// glassdoor 上说这是fb 的面试题

#warning 这两个方法，测试的时候 都有bug

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
      int count = countNode(root->left);
      if (k <= count) {
        kthSmallest(root->left, k);
      } else if ( k > count + 1) {
        kthSmallest(root->right, k - 1 - count);
      }
      return root->val;
    }

    int countNode(TreeNode* n) {
      if(n == NULL) return 0;
      return 1 + countNode(n->left) + countNode(n->right);
    }

    /**
    * == 方法2
    * 利用inorder 的方式 traversal the BST
    * 这个方法有些抽象
    */

    int kthSmallest_02(TreeNode* root, int k) {
      int idx = 0;
      doKthSmallest_02(root, k, idx);
      return idx;
    }

    void doKthSmallest_02(TreeNode* root, int k, int& idx) {
        if (!root) {
            return;
        }
        doKthSmallest_02(root->left, k, idx);
        idx++;
        if (idx == k) {
            return ;
        }
        doKthSmallest_02(root->right, k, idx);
    }
};

#warning 说明对这个算法的东西，已经有点淡忘了

