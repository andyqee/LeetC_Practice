//
//  Generate Parentheses.cpp
//  contest
//
//  Created by andy on 8/5/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>

//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//For example, given n = 3, a solution set is:
//
//"((()))", "(()())", "(())()", "()(())", "()()()"

/**
 *   这个问题首先让我联想起深度遍历和广度遍历的问题
 *
 */

// 递归方法

using namespace std;

//class Solution {
//public:
//    
//    vector<string> generateParenthesis(int n) {
//        vector<string> result;
//        string s;
//        doGP(n, 0, result, s);
//        return result;
//    }
//    
//    void doGP(int n, int m, vector<string> &result, string str) {
//        if (n == 0 && m == 0) {
//            result.push_back(str);
//            return;
//        }
//        if (m > 0) {
//            doGP(n, m-1, result, str+")");
//        }
//        if (n > 0) {
//            doGP(n-1, m+1, result, str+"(");
//        }
//    }
//    
//};


//class Solution {
//public:
//    std::vector<std::string> generateParenthesis(int n) {
//        std::vector<std::string> res;
//        std::string str;
//        size = n;
//        generateParenthesis(res, str, 0, 0);
//        return res;
//    }
//private:
//    int size;
//    void generateParenthesis(std::vector<std::string> &res, std::string str, int left, int right) {
//        if (left + right == 2 * size) {
//            res.push_back(str);
//            return;
//        }
//        if (left < size)
//            generateParenthesis(res, str + '(', left + 1, right);
//        if (left > right)
//            generateParenthesis(res, str + ')', left, right + 1);
//    }
//};

// DP 的解法
// https://leetcode.com/discuss/11509/an-iterative-method

//class Solution {
//public:
//    
//    vector<string> generateParenthesis(int n) {
//        
//    }
//    
//};

