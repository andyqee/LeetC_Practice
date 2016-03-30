//
//  Implement strStr.cpp
//  contest
//
//  Created by andy on 2/6/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <string>

//Implement strStr().
//
//Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// 字符串的匹配问题
// 有点复杂 KMP

using namespace std;

class Solution {
public:
    // 该算法 瞬间超时间 O(mn)
    
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) {
            return 0;
        }
        
        if (haystack.length() < needle.length()) {
            return -1;
        }
        for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {
            for (int j = 0; j < needle.length(); j++) {
                if (needle[j] != haystack[i+j]) break;
                if (j == needle.length() - 1) {
                    return i;
                }
            }
        }
        return -1;
    }
    
};


// TODO;

// Rabin-Karp algorithm, KMP algorithm, and the Boyer- Moore algorithm
// 这些高级算法 已经忘记了。泪
// 这个可以参考 alogrithm 里面的实现 来重写下
