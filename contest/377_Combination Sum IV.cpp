//
//  377_Combination Sum IV.cpp
//  contest
//
//  Created by ethon_qi on 24/9/2016.
//  Copyright © 2016 andy. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

#include <unordered_map>

//Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
//
//Example:
//
//nums = [1, 2, 3]
//target = 4
//
//The possible combination ways are:
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
//
//Note that different sequences are counted as different combinations.
//
//Therefore the output is 7.
//Follow up:
//What if negative numbers are allowed in the given array?
//How does it change the problem?
//What limitation we need to add to the question to allow negative numbers?

// 这个问题就是伯克利算法书里面介绍的背包问题,那个是求最大价值
// 这类问题太灵活了
// 这个是算所有可能行


// 递归算法三板斧
// 1. 添加memory
// 2. 最小case 什么时候break 递归

using namespace std;

class Solution {

public:
    // 13ms
    int doCombinationSum4(vector<int>& nums, int target, unordered_map<int, int>& table ) {
        if (table.count(target) > 0) {
            return table[target];
        }
        if (target == 0) {
            return 1;
        }
        int count = 0;
        for (size_t idx = 0; idx != nums.size(); idx++) {
            if (nums[idx] <= target) {
                count += doCombinationSum4(nums, target - nums[idx], table);
            }
        }
        table[target] = count;
        return count;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        return doCombinationSum4(nums, target, map);
    }
    
    // 3ms ,DP 就是快啊。
    int combinationSum4_dp(vector<int>& nums, int target) {
        vector<int> res(target + 1, 0);
        //target 逐渐变大
        res[0] = 1;
        
        for (size_t t = 1; t <= target; t++) {
            for (size_t idx = 0; idx != nums.size(); idx++) {
                if (t >= nums[idx]) {
                    res[t] += res[t - nums[idx]];
                }
            }
        }
        return res[target];
    }
    
};
