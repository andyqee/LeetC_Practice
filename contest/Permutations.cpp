//
//  Permutations.cpp
//  contest
//
//  Created by andy on 3/6/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>

//Given a collection of numbers, return all possible permutations.
//
//For example,
//[1,2,3] have the following permutations:
//[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

// 这道题第一遍 竟然没写对

// 这道题 有个升级版
// https://leetcode.com/problems/permutations-ii/

using namespace std;

class Solution {
public:
    // my solution
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        doPermute(nums, result);
        return result;
    }
    
    void doPermute(vector<int>& nums, vector<vector<int>>& result) {
        if (nums.size() == 0) {
            return;
        }
        
        for (int i = 0; i != nums.size(); i++) {
            vector<int> ve;
            ve.push_back(nums[i]);
            result.push_back(ve);
            
        }
        
    }
    
    //https://leetcode.com/discuss/18212/my-elegant-recursive-c-solution-with-inline-explanation
    // cool solution
    // 这个方法确实非常优雅
    // 这个技术属于 backtracing solution
    
    vector<vector<int> > permuteA(vector<int> &num) {
        vector<vector<int> > result;
        
        permuteRecursive(num, 0, result);
        return result;
    }
    
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)    {
        if (begin >= num.size()) {
            // one permutation instance
            result.push_back(num);
            return;
        }
        
        for (int i = begin; i < num.size(); i++) {
            swap(num[begin], num[i]);                      // 这一步A
            permuteRecursive(num, begin + 1, result);
            // reset
            swap(num[begin], num[i]);                      // 这一步B 通常很对称的。
        }
    }

    
    // method 2: using next_permutation to iterate all the permutaions
    vector<vector<int> > permuteB(vector<int> &num) {
        vector<vector<int> > ans;
        sort(num.begin(), num.end());
        ans.push_back(num);
        
        while(next_permutation(num.begin(), num.end()))
            ans.push_back(num);
        return ans;
    }
    
    // method 3: recursive dfs
    // 这个算法技术 是比较普通的方式
    // 但是 我发现这项技能 我一直掌握的不太好
    // 将问题降阶 F[n] =  对 F[n-1] 每个位置插入 a［0］
#warning 这道题还需要再搞一遍
    
    vector<vector<int> > permuteC(vector<int> &num) {
        vector<vector<int> > ans;
        dfs(num, ans);
        return ans;
    }
    
    void dfs(vector<int> &num, vector<vector<int>> &ans) {
        if (num.size() == 1) {
            vector<int> tmp(num.begin(), num.end());
            ans.push_back(tmp);
            return;
        }
        
        vector<vector<int> > ans1;
        vector<int> num1(num.begin()+1, num.end());
        dfs(num1, ans);
        
        for(int i = 0; i < ans.size(); ++i) {
            vector<int> tmp = ans[i];

            for(int j = 0; j <= tmp.size(); ++j) {
                tmp.insert(tmp.begin()+j, num[0]);
                ans1.push_back(tmp);
            }
        }
        
        ans = ans1;     // 通过这种替换的方式，来更新结果集合 这里进行的切换！ 关键问题
    }
};

// Map reduce 的算法思想来处理
// https://leetcode.com/discuss/30507/5-lines-map-reduce


