//
//  Unique Binary Search Trees II.cpp
//  contest
//
//  Created by andy on 25/5/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>

#include <vector>

//Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
//For example,
//Given n = 3, there are a total of 5 unique BST's.
//
// 1         3     3      2      1
//  \       /     /      / \      \
//   3     2     1      1   3      2
//  /     /       \                 \
// 2     1         2                 3

// confused what "{1,#,2,3}" means?
// The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

// Here's an example:
//     1
//    / \
//   2   3
//  /
// 4
//  \
//   5

// The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        
        
        return result;
    }
};










