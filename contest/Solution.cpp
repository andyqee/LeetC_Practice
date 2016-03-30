//
//  Solution.cpp
//  contest
//
//  Created by andy on 11/4/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include "Solution.h"
#include <vector>
/**
   House Robber
   You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 
 Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 
 Credits:
 https://leetcode.com/problems/house-robber/
 */
using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
        if (num.size() == 0) {
            return 0;
        }
        int result;
        vector<int> table;
        for (int idx = 0; idx != num.size(); idx++) {
            table.push_back(-1);
        }
        result = doRob(num, 0, table);
        
        return result;
    }
    
private:
    int doRob(vector<int> &num, int i, vector<int> &table) {
        if (table[i] != -1) {
            return table[i];
        }
        
        if (i == num.size() - 1) {
            table[i] = num[i];
        } else if (i == num.size() - 2) {
            table[i] = max(num[i], num[i+1]);
        } else {
            table[i] = max( doRob(num, i+1, table), num[i] + doRob(num, i+2, table));
        }
        
        return table[i];
    }
    
};

/**
 *  下面这个方法很巧妙
 *  T = O(n) space O(1)
 */

#warning cool Stuff1 

//public class Solution {
//    public int rob(int[] num) {
//        int i = 0;
//        int e = 0;
//        for (int k = 0; k<num.length; k++) {
//            int tmp = i;
//            i = num[k] + e;
//            e = Math.max(tmp, e);
//        }
//        return Math.max(i,e);
//    }
//}
