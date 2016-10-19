//: [Previous](@previous)

import Foundation

//413. Arithmetic Slices
//A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
//
//For example, these are arithmetic sequence:
//
//1, 3, 5, 7, 9
//7, 7, 7, 7
//3, -1, -5, -9
//The following sequence is not arithmetic.
//
//1, 1, 2, 5, 7
//
//A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
//
//A slice (P, Q) of array A is called arithmetic if the sequence:
//A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
//
//The function should return the number of arithmetic slices in the array A.
//
//
//Example:
//
//A = [1, 2, 3, 4]
//
//return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.

//func numberOfArithmeticSlices(_ A: [Int]) -> Int {
//    
//}

// 300. Longest Increasing Subsequence

//Difficulty: Medium
//Contributors: Admin
//Given an unsorted array of integers, find the length of longest increasing subsequence.
//
//For example,
//Given [10, 9, 2, 5, 3, 7, 101, 18],
//The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
//
//Your algorithm should run in O(n2) complexity.
//
//Follow up: Could you improve it to O(n log n) time complexity?

// O(n2)
// 写的好几遍 非常容易出错！！！！🔥 😓 😨
// map[i] 应该是以 nums[i-1] 结尾的 递增序列，如果不是以这个结尾，那么该index 对应的map 就是0
// 这里还有nlogn 的算法实现，可以学习下 😨

func lengthOfLIS(_ nums: [Int]) -> Int {
    let count = nums.count
    if count <= 1 {
        return count
    }
    // 注意这里repeating value is 1 不是0
    var map = [Int](repeating: 1, count: count + 1)
    map[0] = 0
    map[1] = 1
    
    var res = 1
    for i in 2...count {
        for j in 1..<i {
            if nums[j-1] < nums[i-1] {
                map[i] = max(map[j] + 1, map[i])
            }
        }
        res = max(map[i], res)
    }
    return res
}
//let lcs = lengthOfLIS([10,9,2,5,3,7,101,18])

//303. Range Sum Query - Immutable   QuestionEditorial Solution  My Submissions
//Total Accepted: 47652
//Total Submissions: 183372
//Difficulty: Easy
//Contributors: Admin
//Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
//
//Example:
//Given nums = [-2, 0, 3, -5, 2, -1]
//
//sumRange(0, 2) -> 1
//sumRange(2, 5) -> -1
//sumRange(0, 5) -> -3
//Note:
//You may assume that the array does not change.
//There are many calls to sumRange function.

//https://leetcode.com/problems/range-sum-query-immutable/
// 没有swift 版本


//279. Perfect Squares   QuestionEditorial Solution  My Submissions

//Difficulty: Medium
//Contributors: Admin
//Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//
//For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

//这种数字规律问题，数学的技巧性偏强
//
func numSquares(_ n: Int) -> Int {
    if n == 0 {
        return 0
    }
    var map = [Int](repeating: Int.max, count: n + 1)
    map[0] = 0
    map[1] = 1
    if n < 2 {
        return map[n]
    }
    var k = 2
    while k * k <= n {
        map[k*k] = 1
        k += 1
    }
    
    for i in 2...n {
        if map[i] != 1 {
            for j in 1..<i {
                map[i] = min (map[i], map[j] + map[i-j])
            }
        }
    }
    return map[n]
}

// 第二个算法有了很大的改进，但是swift 还是 TLE 😢
func numSquares_2(_ n: Int) -> Int {
    if n == 0 {
        return 0
    }
    var map = [Int](repeating: Int.max, count: n + 1)
    map[0] = 0
    map[1] = 1
    if n < 2 {
        return map[n]
    }
    
    for i in 2...n {
        var j = 1
        while i - j*j >= 0{  // z这里拆分的更佳巧妙些
            map[i] = min(map[i], 1 + map[i-j*j])
            j += 1
        }
    }
    return map[n]
}

//    同样的C++ 版本确可以瞬间秒杀
//    vector<int> cntPerfectSquares(n + 1, INT_MAX);
//    cntPerfectSquares[0] = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        // For each i, it must be the sum of some number (i - j*j) and
//        // a perfect square number (j*j).
//        for (int j = 1; j*j <= i; j++)
//        {
//            cntPerfectSquares[i] =
//                min(cntPerfectSquares[i], cntPerfectSquares[i - j*j] + 1);
//        }
//    }
//
//    return cntPerfectSquares.back();

// 当n = 7168 发生TLE 😔😔
//let nu = numSquares_2(7168)

// leetCode 老司机想到一个变态的办法，使用staic 变量来保存没次运行的结果，这样在跑不同case的时候，就可以直接运用之前case 已经运行过的结果。
// https://discuss.leetcode.com/topic/23812/static-dp-c-12-ms-python-172-ms-ruby-384-ms

// another solution ; Breadth-First Search
