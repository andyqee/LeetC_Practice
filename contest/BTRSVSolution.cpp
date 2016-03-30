//
//  BTRSVSolution.cpp
//  contest
//
//  Created by andy on 11/4/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result;
    doRightSideView(root, result, 0);
    return result;
  }

private:
    void doRightSideView(TreeNode *root, vector<int> result, int idx) {
      if (!root) {
        return ;
      }
      if (idx == result.size()) {
        result.push_back(root->val);
      }
      doRightSideView(root->right, result, idx + 1 );
      doRightSideView(root->left, result, idx + 1 );
    }
};

/**
 *   对分层遍历tree，忘记怎么弄了。
 *
 *
 */