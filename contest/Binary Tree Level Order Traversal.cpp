//
//  Binary Tree Level Order Traversal.cpp
//  contest
//
//  Created by andy on 18/5/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;


//  Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<TreeNode *> queue;
        
        if (root == NULL) {
            return result;
        }
        queue.push_back(root);
        
        while (!queue.empty()) {
            
            vector<int> ans;
            TreeNode *node = queue.front();
            
            ans.push_back(root->val);
            
            if (root->left) {
                queue.push_back(root->left);
            }
            if (root->right) {
                queue.push_back(root->right);
            }
            
        }
        
        return result;
    }
};


//vector<vector<int> > levelOrder(TreeNode *root) {
//    vector<vector<int> > retVal;
//    
//    levelOrder(root, retVal, 0);
//    
//    return retVal;
//}
//
//void levelOrder(TreeNode* root, vector<vector<int> > &v, int currLevel) {
//    if (root == NULL) {
//        return;
//    }
//    
//    if (v.empty() || currLevel > (v.size() - 1)) {       
//        v.push_back(vector<int>());
//    }
//    
//    v[currLevel].push_back(root->val);
//    
//    levelOrder(root->left, v, currLevel + 1);
//    levelOrder(root->right, v, currLevel + 1);
//}

//vector<vector<int>> ret;
//
//void buildVector(TreeNode *root, int depth)
//{
//    if(root == NULL) return;
//    if(ret.size() == depth)                              这里是等于深度
//        ret.push_back(vector<int>());
//    
//    ret[depth].push_back(root->val);
//    buildVector(root->left, depth + 1);
//    buildVector(root->right, depth + 1);
//}
//
//vector<vector<int> > levelOrder(TreeNode *root) {
//    buildVector(root, 0);
//    return ret;
//}


//class Solution {
//public:
//    vector<vector<int> > levelOrder(TreeNode *root) {
//        vector< vector<int> > ans;
//        if (!root) return ans;
        queue<pair<TreeNode *, int> > q;
//        q.push(make_pair(root, 0));
//        while (!q.empty()) {
//            
//            int i = q.front().second;
//            TreeNode * node = q.front().first;
//            if (ans.size() >= i) ans.resize(i + 1);             // 为什么这里的判断条件是 > 大于深度
//            ans[i].push_back(node -> val);
//            if (node -> left) q.push(make_pair(node -> left, i + 1));
//            if (node -> right) q.push(make_pair(node -> right, i + 1));
//            q.pop();
//        }
//        return ans;
//    }
//    
//};
