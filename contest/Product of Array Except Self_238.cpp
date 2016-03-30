//
//  Product of Array Except Self_238.cpp
//  contest
//
//  Created by ethon_qi on 2/3/2016.
//  Copyright © 2016 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>

//
//Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//
//Solve it without division and in O(n).
//
//For example, given [1,2,3,4], return [24,12,8,6].
//
//Follow up:
//Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

// 这里复杂的关键在于处理如何 元素为0 的情况

// [1, 0] 这个边界条件弄错了

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int pro = 1;
        size_t firstLocationOfZero = INT32_MAX;
        for (size_t idx = 0; idx != nums.size(); idx++) {
            if (nums[idx] == 0) {
                if (firstLocationOfZero == INT32_MAX) {
                    firstLocationOfZero = idx;
                    //escape this element
                } else {
                    pro = 0;
                }
            } else {
                pro = pro * nums[idx];
            }
        }
        
        for (size_t idx = 0; idx != nums.size(); idx++) {
            if (pro == 0) {
                result.push_back(0);
            } else {
                if (firstLocationOfZero == INT32_MAX) {
                    result.push_back(pro / nums[idx]);
                } else {
                    if (idx != firstLocationOfZero) {
                        result.push_back(0);
                    } else {
                        result.push_back(pro);
                    }
                }
            }
        }
        return result;
    }
};


// 下面有高vote 代码，还是非常巧妙的，不需要考虑 0 的情况

//public class Solution {
//    public int[] productExceptSelf(int[] nums) {
//        int n = nums.length;
//        int[] res = new int[n];
//        res[0] = 1;
//        for (int i = 1; i < n; i++) {
//            res[i] = res[i - 1] * nums[i - 1];
//        }
//        int right = 1;
//        for (int i = n - 1; i >= 0; i--) {
//            res[i] *= right;
//            right *= nums[i];
//        }
//        return res;
//    }
