//
//  FactorialTrailingZeroes.cpp
//  contest
//
//  Created by andy on 12/4/15.
//  Copyright (c) 2015 andy. All rights reserved.
//
// Given an integer n, return the number of trailing zeroes in n!.
//
// Note: Your solution should be in logarithmic time complexity.
// https://leetcode.com/problems/factorial-trailing-zeroes/

#include <stdio.h>

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n > 0) {
            n /= 5;
            count += n;
        }
        return count;
    }
};