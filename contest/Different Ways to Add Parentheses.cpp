//
//  Different Ways to Add Parentheses.cpp
//  contest
//
//  Created by ethon_qi on 15/3/2016.
//  Copyright © 2016 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

//Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
//
//
//Example 1
//Input: "2-1-1".
//
//((2-1)-1) = 0
//(2-(1-1)) = 2
//Output: [0, 2]
//
//
//Example 2
//Input: "2*3-4*5"
//
//(2*(3-(4*5))) = -34
//((2*3)-(4*5)) = -14
//((2*(3-4))*5) = -10
//(2*((3-4)*5)) = -10
//(((2*3)-4)*5) = 10
//Output: [-34, -14, -10, -10, 10]

using namespace std;

class Solution {
public:
//    vector<int> diffWaysToCompute(string input) {
//        
//    }
};
