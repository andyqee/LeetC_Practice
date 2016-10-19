// Given a set of distinct positive integers, 
// find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

// If there are multiple solutions, return any subset is fine.

// Example 1:

// nums: [1,2,3]

// Result: [1,2] (of course, [1,3] will also be ok)
// Example 2:

// nums: [1,2,4,8]

// Result: [1,2,4,8]
// Credits:
// Special thanks to @Stomach_ache for adding this problem and creating all test cases.
//  https://leetcode.com/problems/largest-divisible-subset/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    	vector<int> v;
    	// std::vector<> v;
    	for (size_t i = 0; i < nums.size(); ++i)
    	  {
    	  	for (int j = 0; j < count; ++j)
    	  	{
    	  		
    	  	}
    	  }  
    	return v; 
    } 
};