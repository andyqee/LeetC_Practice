//
//  214_Shortest Palindrome.cpp
//  contest
//
//  Created by andy on 30/3/2016.
//  Copyright © 2016 andy. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

//Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
//
//For example:
//
//Given "aacecaaa", return "aaacecaaa".
//
//Given "abcd", return "dcbabcd".

// 思考下以下几个问题
// 考察了什么算法技巧？ 还有哪些其它的题型
// string 相关的算法 有哪些？
//

// KMP T-  O(n)
// 前缀函数 预处理 为了建立一个完整地有效位移表 也就是移动几位是有可能全部匹配的
//
// T abaacaababac
// P ababc

// 这道题目 string 的前缀和 其 reverse 的后缀的最长共公部分，然后剩下的插入最开始的地方

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_Str = s;
        reverse(rev_Str.begin(), rev_Str.end());
        string l = s + "#" + rev_Str;
        
        vector<int> v(l.size(), 0);
        for (int i = 1; i <= l.size(); i++) {
            int j = v[i -1]; //prev
            while (j > 0 && l[i] != l[j]) {
                j = v[j - 1];
            }
            v[i] = (j += l[i] == l[j]);
        }
        return rev_Str.substr(0, s.size() - v[l.size() - 1]) + s;
    }
    
    std::string shortestPalindrome2(std::string s) {
        int len = s.length();
        if (len < 2)
            return s;
        // calculate the length of the longest palindromic prefix substring.
        int longest = 1, start, end;
        for (int begin = 0; begin <= len / 2;) {
            start = end = begin;
            while (end < len - 1 && s[end + 1] == s[end])
                ++end;
            begin = end + 1;
            while (end < len - 1 && start > 0 && s[end + 1] == s[start - 1]) {
                ++end;
                --start;
            }
            // start == 0 means the palindromic substring is also prefix string.
            if (start == 0 && longest < end - start + 1)
                longest = end - start + 1;
        }
        // reverse the remaining substring and adding it in front of s.
        std::string remaining = s.substr(longest, len - longest);
        std::reverse(remaining.begin(), remaining.end());
        return remaining + s;
    }
};