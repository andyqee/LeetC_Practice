//
//  String to Integer.cpp
//  contest
//
//  Created by andy on 2/6/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

//Implement atoi to convert a string to an integer.
//
//Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
//Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
//
//Update (2015-02-10):
//The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.

using namespace std;

class Solution {
public:
    
    // 这个问题，我忽略了 空格处理 和 整型溢出的场景
    
    int myAtoi(string str) {
        
        bool positive = true;
        int sum = 0;
        
        if (str[0] == '-')
        {
            positive = false;
            
        } else if(str[0] > '0' && str[0] <= '9')
        {
            sum = str[0] - '0';
        }
        
        for (int i = 1; i < str.length(); i++) {
            sum = sum * 10 + str[i] - '0';
        }
        
        return positive ? sum : 0 - sum;
        
    }
    
        int fromNetAtoi(const char *str) {
            int sign = 1, base = 0, i = 0;
            while (str[i] == ' ') { i++; }
            if (str[i] == '-' || str[i] == '+') {
                sign = 1 - 2 * (str[i++] == '-');
            }
            while (str[i] >= '0' && str[i] <= '9') {
                
                // 这边的 > 7 不太好想
                if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                    if (sign == 1) return INT_MAX;
                    else return INT_MIN;
                }
                base  = 10 * base + (str[i++] - '0');
            }
            return base * sign;
        }
};