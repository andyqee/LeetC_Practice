//
//  Increasing Triplet Subsequence.cpp
//  contest
//
//  Created by ethon_qi on 24/2/2016.
//  Copyright © 2016 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>

//Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
//
//Formally the function should:
//Return true if there exists i, j, k
//such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
//Your algorithm should run in O(n) time complexity and O(1) space complexity.
//
//Examples:
//Given [1, 2, 3, 4, 5],
//return true.
//
//Given [5, 4, 3, 2, 1],
//return false.

// 新年第一刷
// need retry

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT32_MAX, c2 = INT32_MAX;
        for (int e : nums ) {
            if (e <= c1) {
                c1 = e;
            } else if(e <= c2){
                c2 = e;
            } else {
                return true;
            }
        }
        return false;
    }
};