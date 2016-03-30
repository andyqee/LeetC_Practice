//
//  Kth Largest Element in an Array.cpp
//  contest
//
//  Created by andy on 26/5/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

#include <queue>

//Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//For example,
//Given [3,2,1,5,6,4] and k = 2, return 5.
//
//Note:
//You may assume k is always valid, 1 ≤ k ≤ array's length.
//
//Credits:
//Special thanks to @mithmatt for adding this problem and creating all test cases.


// https://leetcode.com/discuss/36966/solution-explained

using namespace std;

class Solution {
public:
    // 第一种办法，最简单的方式 排序
    // O(N lg N) running time + O(1) memory
    int findKthLargest1(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        return nums[n - k];
    }
    
    // 第二种方式
    // 优先队列  O(nlgk) by using min-heap
    // leetcode 显示的时间 比上面那种算法 慢
    
    int findKthLargest2(vector<int>& nums, int k) {
        // 定义一个最小堆
        priority_queue<int, vector<int>, greater<int>> q;
        
        for(auto &v : nums) {
            if (q.size() < k) {
                q.push(v);
            }
            else {
                q.push(v);
                q.pop();
            }
        }
        return q.top();
    }
    
    // O(n) by partitioning recursively
    // 这个方法和快速排序的方法 差不多
    
    int findKthLargest3(vector<int>& nums, int k) {
        //TODO:
        int l = 0;
        int h = nums.size() - 1;
        int index = nums.size() - k;
        
        int j = 0;
        while (l < h) {
            j = partition(nums, l, h);
            if (j < index) {
                l = j + 1;
            } else if( j > index) {
                h = j - 1;
            } else {
                break;
            }
        }
        return nums[j];
    }
    
    int partition(vector<int> nums, int l, int h) {
        int i = l;
        int j = h + 1;
        while(true) {
            while(i < h && nums[++i] > nums[l]);   // 找到大的
            while(j > l && nums[l] > nums[--j]);   // 找到小的。
            if(i >= j) {
                break;
            }
            swap(nums[i], nums[j]);          // 大小交换
        }
        swap(nums[l], nums[j]);              // 把主元 换到正确的位置上
        return j;
    }
};