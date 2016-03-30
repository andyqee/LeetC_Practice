//
//  Combination Sum III.cpp
//  contest
//
//  Created by andy on 25/5/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>

//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//Ensure that numbers within the set are sorted in ascending order.
//
//
//Example 1:
//
//Input: k = 3, n = 7
//
//Output:
//
//[[1,2,4]]
//
//Example 2:
//
//Input: k = 3, n = 9
//
//Output:
//
//[[1,2,6], [1,3,5], [2,3,4]]

//利用 backtracking
//在遍历解空间的过程，可以看成一个深度优先搜索树，结果就是路径

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
       
        vector<vector<int>> result;
        
        vector<int> sol;
        
        doCombinationSum(result, sol, k, n);
        
        return result;
    }
    
    void doCombinationSum(vector<vector<int>> &v, vector<int> s, int k, int h) {
        // 找限制条件
        
        //成功找到解的条件，放到集合之中
        if (k == v.size() && h == 0) {
            v.push_back(s);
            return;
        }
        
        if (k > v.size()) {
            for (int i = (s.empty() ? 1: s.back()+1) ; i <= 9 ; i++) {
                if (h - i < 0) {
                    break;
                }
                s.push_back(i);
                doCombinationSum(v, s, k, h - i); // 这里如果成功之后，就不会执行 下面的s.pop_back()
                s.pop_back();
            }
        }
    }
};

//class Solution {
//public:
//    void combination(vector<vector<int>>& result, vector<int> sol, int k, int n) {
//        if (sol.size() == k && n == 0) { result.push_back(sol); return ; }
//        if (sol.size() < k) {
//            for (int i = sol.empty() ? 1 : sol.back() + 1; i <= 9; ++i) {
//                if (n - i < 0) break;
//                sol.push_back(i);
//                combination(result, sol, k, n - i);
//                sol.pop_back();
//            }
//        }
//    }
//    
//    vector<vector<int>> combinationSum3(int k, int n) {
//        vector<vector<int>> result;
//        vector<int> sol;
//        combination(result, sol, k, n);
//        return result;
//    }
//};