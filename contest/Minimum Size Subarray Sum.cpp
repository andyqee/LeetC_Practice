//
//  Minimum Size Subarray Sum.cpp
//  contest
//
//  Created by andy on 31/5/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>

//Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
//
//For example, given the array [2,3,1,2,4,3] and s = 7,
//the subarray [4,3] has the minimal length under the problem constraint.

//If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

using namespace std;

class Solution {
public:
    // O(N) 的方法
    // 这个方法技巧性太强了。对数组的算法，有一些很强的技巧性
    // 这个是网友的方法
    
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, end = 0, sum = 0, minLen = INT16_MAX;
        
        while (end < nums.size()) {
            while (end < nums.size() && sum < s) sum += nums[end++];
            if (sum < s) break;
            while (start < end && sum >= s) sum -= nums[start++];
            minLen = min(end - start + 1 , minLen);
        }
        return minLen == INT16_MAX ? 0 : minLen;
    }
    
    // O(NlogN) 的方法
    // Java 实现
    
//    private int solveNLogN(int s, int[] nums) {
//        int[] sums = new int[nums.length + 1];
//        for (int i = 1; i < sums.length; i++) sums[i] = sums[i - 1] + nums[i - 1];
//        int minLen = Integer.MAX_VALUE;
//        for (int i = 0; i < sums.length; i++) {
//            int end = binarySearch(i + 1, sums.length - 1, sums[i] + s, sums);
//            if (end == sums.length) break;
//            if (end - i < minLen) minLen = end - i;
//        }
//        return minLen == Integer.MAX_VALUE ? 0 : minLen;
//    }
//    
//    private int binarySearch(int lo, int hi, int key, int[] sums) {
//        while (lo <= hi) {
//            int mid = (lo + hi) / 2;
//            if (sums[mid] >= key){
//                hi = mid - 1;
//            } else {
//                lo = mid + 1;
//            }
//        }
//        return lo;
//    }
//
};