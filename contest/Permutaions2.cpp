//
//  Permutaions2.cpp
//  contest
//
//  Created by andy on 5/6/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>

//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//For example,
//[1,1,2] have the following unique permutations:
//[1,1,2], [1,2,1], and [2,1,1].

// 对于这种唯一性问题，有什么通用的技巧，来处理吗？

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        doPermuteUnique(nums, ans);
        return ans;
    }
    
    void doPermuteUnique(vector<int>& nums, vector<vector<int>>& ans) {
        
    }
    
};