//
//  Contains Duplicate.cpp
//  contest
//
//  Created by andy on 25/5/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <set>

//Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> set;
        
        for(int i = 0; i != nums.size(); i++){
            if (set.count(nums[i]) == 1) {
                return true;
            } else {
                set.insert(nums[i]);
            }
        }
        return false;
    }
};