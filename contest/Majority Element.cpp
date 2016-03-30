//
//  Majority Element.cpp
//  contest
//
//  Created by andy on 12/4/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int e = 0;
        int count = 0;
        for (int i = 0; i < num.size(); i++) {
            if (count == 0 ) e = num[i];
            
            if (e == num[i]) {
                count++;
            } else {
                count--;
            }
        }
        return e;
    }
};