//
//  Power of Two.cpp
//  contest
//
//  Created by andy on 6/7/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
//Given an integer, write a function to determine if it is a power of two.
//
//Credits:
//Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

class Solution {
public:
    bool isPowerOfTwo(int n) {
          // 这里n 是整数，所以不需要考虑1/2 1/4 这些幂为负数得情况
          while (n > 0) {
            if ( n == 1) {
              return true;
            } else if (n % 2 != 0) {
              return false;
            }
            n = n >> 1;
          }
          return false;
    }

    // LeetCode 论坛上看到一个很快的方法
    bool isPowerOfTwoFromLeetCode(int n) {
      return (n<=0)?false:(n & (n-1))==0;
    }
};
