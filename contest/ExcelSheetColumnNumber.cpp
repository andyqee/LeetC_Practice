//
//  ExcelSheetColumnNumber.cpp
//  contest
//
//  Created by andy on 11/4/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        long len = s.length();
        for (long i = 0; i != len; ++i) {
          result = result * 26 + (s[i] - 64);
        }
        return result;
    }
};