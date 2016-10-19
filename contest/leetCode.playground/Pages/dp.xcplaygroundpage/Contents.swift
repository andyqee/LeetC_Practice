//: Playground - noun: a place where people can play

import Cocoa


//class Solution {
    //Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
    //
    //If there are multiple solutions, return any subset is fine.
    //
    //Example 1:
    //
    //nums: [1,2,3]
    //
    //Result: [1,2] (of course, [1,3] will also be ok)
    //Example 2:
    //
    //nums: [1,2,4,8]
    //
    //Result: [1,2,4,8]
    //Credits:
    //Special thanks to @Stomach_ache for adding this problem and creating all test cases.
    //
    //Subscribe to see which companies asked this question
    // https://leetcode.com/problems/largest-divisible-subset/
    
    //对于返回数组的该如何弄？
    //第二遍做竟然忘记了，确实挺难的
    
    // 答案是错的
    func largestDivisibleSubset(_ nums: [Int]) -> [Int] {
        
        var r = [Int](repeating: 0, count: nums.count)
        var parent = [Int](repeating: 0, count: nums.count) // track path
        
        var m = 0
        var mi = 0
        
        let sNums = nums.sorted()
        for i in 0..<sNums.count {
            var j = 0
            while j < i {
                if nums[i] % nums[j] == 0 && (r[i] < r[j] + 1) {
                    r[i] = r[j] + 1
                    parent[i] = j;
                    
                    if r[i] > m {
                        m = r[i]
                        mi = i
                    }
                }
                j += 1
            }
        }
        
        var ret = [Int]()
        for _ in 0..<m {
            ret.append(nums[mi])
            mi = parent[mi]
        }
        return ret.reversed()
    }
    
//    Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
//    
//    Example:
//    Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
    
    //这种属于偏数学的，需要发现数学规律
    //高中组合基本问题
    func countNumbersWithUniqueDigits(_ n: Int) -> Int {
        if n == 0 {
            return 1
        }
        
        var ret = 10
        var count = min(10, n)
        var fir = 9
        var availableName = 9
        
        while count > 1 && availableName > 0{
            fir = fir * availableName  // 这个地方写错了
            ret += fir
            count -= 1
            availableName -= 1
        }
        return ret
    }
    
//    312. Burst Balloons
//    Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
//    
//    Find the maximum coins you can collect by bursting the balloons wisely.
//    
//    Note:
//    (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
//    (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
//    
//    Example:
//    
//    Given [3, 1, 5, 8]
//    
//    Return 167
//    
//    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//    coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
    
    func maxCoins_recurcive(_ nums: [Int]) -> Int {
        //TLE 直接跪了
        var maxC : Int = 0
        if nums.isEmpty {
            return 0
        }
        if nums.count == 1 {
            return nums.first!
        }
        
        for i in 0..<nums.count {
            let left  = (i == 0) ? 1 : nums[i-1]
            let right = (i == nums.count-1) ? 1 : nums[i+1]
            var otherArray : [Int] = nums
            otherArray.remove(at: i)
            maxC = max(maxC, left * nums[i] * right + maxCoins_recurcive(otherArray))
        }
        return maxC
    }
    
    //已经很接近了。很典型的问题
    //对于step 的管理弄错了
    
//    func maxCoins_dp_wrong(_ nums: [Int]) -> Int {
//        let len = nums.count
//        var table = [[Int]](repeating: [Int](repeating: 0, count:len), count: len)
//        
//        for i in 0..<len {
//            table[i][i] = nums[i]
//        }
//        
//        for i in 1..<len {
//            for j in 0..<i {
//                for k in j...i {
//                    table[j][i] = max(table[j][i], table[j][k-1] + table[k+1][i] + left * nums[k] * right)
//                }
//            }
//        }
//        return table[0][len-1]
//    }
    // i 是最后一个爆破的，那么就确定的问题的边界 nums[-1]*nums[i]*nums[n]
    // 如果i 是第一个爆破的，nums[i-1]*nums[i]*nums[i+1]，但是这样不好拆分问题
    // 逆向思考 reverse thking
    // 处理边界！！ index 从啥时候开始 最短
    func maxCoins(_ nums: [Int]) -> Int {
        let len = nums.count + 2
        var table = [[Int]](repeating: [Int](repeating: 0, count:len), count: len)
        
        var fNums = nums
        fNums.insert(1, at: 0)
        fNums.append(1)
        
        for k in 2..<len {
            for l in 0..<len-k {
                let r = l + k
                for i in (l + 1)..<r {
                    table[l][r] = max (fNums[l] * fNums[r] * fNums[i] + table[l][i] + table[i][r], table[l][r])
                }
            }
        }
        return table[0][len-1]
    }
    
//    309. Best Time to Buy and Sell Stock with Cooldown
//    Difficulty: Medium
//    Say you have an array for which the ith element is the price of a given stock on day i.
//    
//    Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
//    
//    You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//    After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
//    Example:
//    
//    prices = [1, 2, 3, 0, 2]
//    maxProfit = 3
//    transactions = [buy, sell, cooldown, buy, sell]
//  还在折腾烦人的DP，但是网上的答案技巧性太强了
//  https://discuss.leetcode.com/topic/30680/share-my-dp-solution-by-state-machine-thinking
//  https://discuss.leetcode.com/topic/30421/share-my-thinking-process
    
    //the key for dp is to find the variables to represent the states and duduces the transition function 
    //当时我想的用一个数组来代表状态，答案用的是三个数组
    //推到状态转移方程
    //需要再做一遍
    func maxProfit(_ prices: [Int]) -> Int {
        if prices.count <= 1 {
            return 0
        }
        
        var sold = 0
        var hold = Int.min
        var rest = 0
        
        for price in prices {
            let prevSold = sold
            sold = hold + price
            hold = max(hold, rest-price)
            rest = max(rest, prevSold)
        }
        return max(sold, rest)
    }
    
//    70. Climbing Stairs  QuestionEditorial Solution  My Submissions

//    Difficulty: Easy
//    You are climbing a stair case. It takes n steps to reach to the top.
//    
//    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//    https://leetcode.com/problems/climbing-stairs/

    func climbStairs(_ n: Int) -> Int {
        var t = [Int](repeating: 0 , count: n+1)
        t[1] = 1
        if n < 2 {
            return t[n]
        }
        
        t[2] = 2
        
        if n < 3 {
            return t[n]
        }
        for i in 3...n {
            t[i] = t[i-1] + t[i-2]
        }
        return t[n]
    }
    
//    Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//  Note: You can only move either down or right at any point in time
    
    func minPathSum(_ grid: [[Int]]) -> Int {
        let m = grid.count
        let n = grid.first!.count
        if m == 0 || n == 0 {
            return 0
        }
        
        var map = [[Int]](repeating: [Int](repeating: Int.max, count:n), count: m)
        map[0][0] = grid[0][0]
        //边界问题是动态规划处理的一个关键
        //然后就是 优化空间，是不是要优化 m*n 换成两个一维数组
        for i in 1..<m {
            map[i][0] = grid[i][0] + map[i-1][0]
        }
        for j in 1..<n {
            map[0][j] = grid[0][j] + map[0][j-1]
        }
        
        for i in 1..<m {
            for j in 1..<n {
                map[i][j] = min(map[i-1][j] + grid[i][j], map[i][j-1] + grid[i][j])
            }
        }
        
        return map[m-1][n-1]
    }
    
//    A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//    
//    The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
    
    func uniquePaths(_ m: Int, _ n: Int) -> Int {
        // 边界case处理
        if m <= 1 || n <= 1 {
            return min(m, n)
        }
        var map = [[Int]](repeating: [Int](repeating: 0, count:n + 1), count: m + 1)
        for i in 1...m {
            map[i][1] = 1
        }
        for j in 1...n {
            map[1][j] = 1
        }
        // 这里一定要注意 m 的范围是不是大于2！！
        for i in 2...m {
            for j in 2...n {
                map[i][j] = map[i][j-1] + map[i-1][j]
            }
        }
        return map[m][n]
    }

    //    63. Unique Paths II  QuestionEditorial Solution  My Submissions
    //    Total Accepted: 80639
    //    Total Submissions: 264694
    //    Difficulty: Medium
    //    Follow up for "Unique Paths":
    //
    //    Now consider if some obstacles are added to the grids. How many unique paths would there be?
    //
    //    An obstacle and empty space is marked as 1 and 0 respectively in the grid.
    //
    //    For example,
    //    There is one obstacle in the middle of a 3x3 grid as illustrated below.
    //
    //    [
    //    [0,0,0],
    //    [0,1,0],
    //    [0,0,0]
    //    ]
    //    The total number of unique paths is 2.
    //
    //    Note: m and n will be at most 100.
    
    func uniquePathsWithObstacles(_ obstacleGrid: [[Int]]) -> Int {
        let m = obstacleGrid.count
        if m == 0 || obstacleGrid.first!.count == 0 {
            return 0
        }
        let n = obstacleGrid.first!.count
        let repeatingValue = (obstacleGrid[0][0] == 0) ? 1 : 0

        var map = [[Int]](repeating: [Int](repeating: repeatingValue, count:n + 1), count: m + 1)
        
        for i in 1...m {
            map[i][1] = (obstacleGrid[i-1][0] == 1) ? 0 : map[i-1][1]
        }
        for j in 1...n {
            map[1][j] = (obstacleGrid[0][j-1] == 1) ? 0 : map[1][j-1]
        }
        // 边界case的处理，提炼出法则
        if m == 1 || n == 1 {
            return map[m][n]
        }
        for i in 2...m {
            for j in 2...n {
                map[i][j] = (obstacleGrid[i-1][j-1] == 1) ? 0 : (map[i][j-1] + map[i-1][j])
            }
        }
        return map[m][n]
    }
    
//    Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
//    
//    You have the following 3 operations permitted on a word:
//    
//    a) Insert a character
//    b) Delete a character
//    c) Replace a character
//    72. Edit Distance
//  https://leetcode.com/problems/edit-distance/
    
    func minDistance(_ word1: String, _ word2: String) -> Int {
        let m = word1.characters.count
        let n = word2.characters.count
        var map = [[Int]](repeating: [Int](repeating: 0, count:n + 1), count: m + 1)
        //base case
        
        for i in 0...m {
            map[i][0] = i
        }
        for j in 0...n {
            map[0][j] = j
        }
        if m == 0 || n == 0{
            return map[m][n]
        }
        //通过index 获取string 中的Char, swift 中异常复杂
        // swift 的for 和其他语言不一样的地方在于，如果m < 1 会发生运行时错误。所以要添加检测
        //注意dp 中使用的biao 的index，和输入元素如array的index 之间的区别管理
        for i in 1...m {
            for j in 1...n {
                let tem = min(map[i][j - 1] + 1 , map[i - 1][j] + 1)
                map[i][j] = min(tem , map[i-1][j-1] + diff(word1[word1.index(word1.startIndex, offsetBy: i-1)], word2[word2.index(word2.startIndex, offsetBy: j-1)]) )
            }
        }
        return map[m][n]
    }
    
    private func diff(_ char1: Character, _ char2: Character) -> Int {
        return char1 == char2 ? 0 : 1
    }
    
//    115. Distinct Subsequences   QuestionEditorial Solution  My Submissions

//    Difficulty: Hard
//    Contributors: Admin
//    Given a string S and a string T, count the number of distinct subsequences of T in S.
//    
//    A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//    
//    Here is an example:
//    S = "rabbbit", T = "rabbit"
//    
//    Return 3.
    // 这个应该算是edit distance 的衍生问题
    func numDistinct(_ s: String, _ t: String) -> Int {
        if t.isEmpty {
            return 1
        }
        
        let tA = Array(t.characters)
        let sA = Array(s.characters)
        let m = sA.count
        let n = tA.count //
        
        if n > m {
            return 0
        }
        
        var map = [[Int]](repeating: [Int](repeating: 0, count: n + 1), count: m + 1)
        //step 2initialize 
        for i in 1...m {
            map[i][0] = 1
        }
        for j in 1...n {
            map[0][j] = 0
        }
        map[0][0] = 1
        
        for i in 1...m {
            for j in 1...n {
                map[i][j] = map[i-1][j] + (tA[j-1] == sA[i-1] ? map[i-1][j-1] : 0)
            }
        }
        return map[m][n]
    }
    
//    97. Interleaving String   QuestionEditorial Solution  My Submissions
//    Total Accepted: 58553
//    Total Submissions: 248380
//    Difficulty: Hard
//    Contributors: Admin
//    Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//    
//    For example,
//    Given:
//    s1 = "aabcc",
//    s2 = "dbbca",
//    
//    When s3 = "aadbbcbcac", return true.
//    When s3 = "aadbbbaccc", return false.
    
    func isInterleave(_ s1: String, _ s2: String, _ s3: String) -> Bool {
        let len1 = s1.characters.count
        let len2 = s2.characters.count
        let len3 = s3.characters.count
        
        if len1 + len2 != len3 {
            return false
        }
        if s1.isEmpty {
            return s2 == s3
        }
        if s2.isEmpty {
            return s1 == s3
        }
        
        let a1 = Array(s1.characters)
        let a2 = Array(s2.characters)
        let a3 = Array(s3.characters)
        

        var map = [[Bool]](repeating:[Bool](repeating:true, count: len2 + 1), count: len1 + 1)
        for j in 1...len2 {
            map[0][j] = (a2[j-1] == a3[j-1]) && map[0][j-1] //这里在初始化的时候，状态和前面的状态是有关的！！
        }
        for i in 1...len1 {
            map[i][0] = (a1[i-1] == a3[i-1]) && map[i-1][0]
        }
        
        for i in 1...len1 {
            for j in 1...len2 {
                let case1 = (a3[i+j-1] == a1[i-1]) && map[i-1][j]
                let case2 = (a3[i+j-1] == a2[j-1]) && map[i][j-1]
                map[i][j] = case1 || case2
            }
        }
        return map[len1][len2]
    }

//Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
//For example, given the following triangle
//[
      //[2],
     //[3,4],
    //[6,5,7],
   //[4,1,8,3]
//]

//The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
//Note:
//Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

//https://leetcode.com/problems/triangle/

func wrong_minimumTotal(_ triangle: [[Int]]) -> Int {
    //弄清楚这个triangle 是不是标准的，也就是下面的数组比上面的长度大一
    // 这里在求和的时候，注意Int 和，类型是否会overflow
    // 思考中各种边界情况，貌似不肯嗯的情况
    // 数字是否是负数之类的
    // wrong
    if triangle.isEmpty {
        return 0
    }
    
    let len = triangle.count
    var filterdTriangle = triangle.filter { (item) -> Bool in
        !item.isEmpty
    }
    
    var map = [[Int]](repeating:[Int](repeating:Int.max, count: filterdTriangle.last!.count + 1), count: len + 1)
    
    map[0][0] = 0
    let firstLen = filterdTriangle.first!.count
    for j in 1...firstLen {
        map[1][j] = min(map[1][j-1], filterdTriangle[0][j-1])
    }
    if len < 2 {
        return map[len][firstLen]
    }
    
    for i in 2...len {
        for j in 1...filterdTriangle[i-1].count {
            var minV = Int.max
            if j == 1 {
                minV = map[i-1][j]
            } else if j == filterdTriangle[i-2].count {
                minV = map[i-1][j-1]
            } else {
                minV = min(map[i-1][j-1], map[i-1][j])
            }
            
            let cur = filterdTriangle[i-1][j-1] + minV
            map[i][j] = min(map[i][j-1], cur)
        }
    }
    return map[len][(filterdTriangle.last!.count)]
    
}
// 注意这题
func minimumTotal_lt(_ triangle: [[Int]]) -> Int {
    let n = triangle.count
    var map = triangle.last!
    var idx = n-2
    while idx >= 0 {
        for i in 0...idx {
            map[i] = min(map[i], map[i+1]) + triangle[idx][i]
        }
        
        idx -= 1
    }
    return map[0]
}

//Scramble String
//https://leetcode.com/problems/scramble-string/
//Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
//
//Below is one possible representation of s1 = "great":
//
//great
///    \
//gr    eat
/// \    /  \
//g   r  e   at
/// \
//a   t
//To scramble the string, we may choose any non-leaf node and swap its two children.
//
//For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
//
//rgeat
///    \
//rg    eat
/// \    /  \
//r   g  e   at
/// \
//a   t
//We say that "rgeat" is a scrambled string of "great".
//
//Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
//
//rgtae
///    \
//rg    tae
/// \    /  \
//r   g  ta  e
/// \
//t   a
//We say that "rgtae" is a scrambled string of "great".
//
//Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

// 这种题目和前面的思路不太一样，不太好找subproblem

//func isScramble_dp(_ s1: String, _ s2: String) -> Bool {
//    if s1.characters.count != s2.characters.count {
//        return false
//    }
//    if s1.characters.count == 1 && s2 == s1 {
//        return true
//    }
//    if s1.isEmpty && s2.isEmpty {
//        return true
//    }
//    
//    var map = [Bool](repeating: false, count: s1.characters.count)
//    
//}

// 这题目需要重新再写一遍，有技巧性。 对于规律没有发现正确
// 少考虑了一种情况，所以不能 多思考思考。看看有没有其他什么情况
// https://discuss.leetcode.com/topic/37261/optimized-recursive-0ms-and-dp-20ms-solution-c-beating-100-submissions
// 思考： 对于字符串问题 要考虑各种情况，string isequal isempty is alphabeta numberic

func isScramble_recursive_fail(_ s1: String, _ s2: String) -> Bool {
    if s1.characters.count != s2.characters.count {
        return false
    }
    if s1.characters.count == 1 && s2 == s1 {
        return true
    }
    if s1.isEmpty && s2.isEmpty || (s1 == s2) {
        return true
    }
    let a1 = Array(s1.characters)
    let a2 = Array(s2.characters)

    
    let len = s1.characters.count
    for idx in 0..<len-1 {
        var isScr = false
        let end2 = len - 2 - idx
        let from2 = len - 1 - idx
        isScr = isScramble_recursive_fail(String(a1[0...idx]), String(a2.suffix(from: from2))) &&
                isScramble_recursive_fail(String(a2[0...end2]), String(a1.suffix(from: idx + 1))) ||
                isScramble_recursive_fail(String(a1[0...idx]), String(a2[0...idx])) &&
                isScramble_recursive_fail(String(a1.suffix(from: idx + 1)), String(a2.suffix(from: idx + 1)))

        if isScr {
            return true
        }
    }
    return false
}

//    96. Unique Binary Search Trees  QuestionEditorial Solution  My Submissions
//    Total Accepted: 98656
//    Total Submissions: 252283
//    Difficulty: Medium
//    Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//    
//    For example,
//    Given n = 3, there are a total of 5 unique BST's.
//    
//    1         3     3      2      1
//    \       /     /      / \      \
//    3     2     1      1   3      2
//    /     /       \                 \
//    2     1         2                 3
//  https://leetcode.com/problems/unique-binary-search-trees/
    
    //没想出来，是看得答案 要二刷
    func numTrees(_ n: Int) -> Int {
        // 初始化的时候错了
        var map = [Int](repeating:0, count:n+1)
        if n == 1 {
            return 1
        }
        map[0] = 1
        map[1] = 1

        for i in 2...n {
            for j in 1...i {
                map[i] += map[j-1] * map[i-j]
            }
        }
        return map[n]
    }

//    https://leetcode.com/problems/unique-binary-search-trees-ii/
//    95. Unique Binary Search Trees II  QuestionEditorial Solution  My Submissions
//    Total Accepted: 66854
//    Total Submissions: 222371
//    Difficulty: Medium
//    Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//    
//    For example,
//    Given n = 3, your program should return all 5 unique BST's shown below.
//    
//    1         3     3      2      1
//    \       /     /      / \      \
//    3     2     1      1   3      2
//    /     /       \                 \
//    2     1         2                 3
//    
//    
//      Definition for a binary tree node.
public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
}
    //tough
    func generateTrees(_ n: Int) -> [TreeNode?] {
        var res = [TreeNode]()
        
        return res
    }
    
//    A message containing letters from A-Z is being encoded to numbers using the following mapping:
//    
//    'A' -> 1
//    'B' -> 2
//    ...
//    'Z' -> 26
//    Given an encoded message containing digits, determine the total number of ways to decode it.
//    
//    For example,
//    Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//    
//    The number of ways decoding "12" is 2.
//    https://leetcode.com/problems/decode-ways/

//    func numDecodings(_ s: String) -> Int {
//        //比较简单的动态规划，但是用swift 操作string 很蛋疼，不直接支持下标，而且 C 语言的那种for还不支持
//    }
//    
//    func minPathSum_optimize_space(_ grid: [[Int]]) -> Int {
//        let m = grid.count
//        let n = grid.first!.count
//        if m == 0 || n == 0 {
//            return 0
//        }
//        
//        var map = [[Int]](repeating: [Int](repeating: Int.max, count:n), count: m)
//        map[0][0] = grid[0][0]
//        //边界问题是动态规划处理的一个关键
//        //然后就是 优化空间，是不是要优化 m*n 换成两个一维数组
//        for i in 1..<m {
//            map[i][0] = grid[i][0] + map[i-1][0]
//        }
//        for j in 1..<n {
//            map[0][j] = grid[0][j] + map[0][j-1]
//        }
//        
//        for i in 1..<m {
//            for j in 1..<n {
//                map[i][j] = min(map[i-1][j] + grid[i][j], map[i][j-1] + grid[i][j])
//                inVec[j] = min(inVec[j-1], outVec[j]) + grid[i][j]
//            }
//        }
//        
//        return map[m-1][n-1]
//    }
    
    //类似于matrix multiple problem
    
//    Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//    
//    Do not allocate extra space for another array, you must do this in place with constant memory.
//    
//    For example,
//    Given input array nums = [1,1,2],
//    
//    Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
//  26 https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    
//    func removeDuplicates(_ nums: inout [Int]) -> Int {
//        
//    }
//}

//let res = isInterleave("aabc", "abad", "aabcabad")
//let res = wrong_minimumTotal([[1],[3,2],[7,8,9],[4,1,1,3],[4,3,1,3,4], [4,5,3,10,11,2]])
//let res_lt = minimumTotal_lt([[1],[3,2],[7,8,9],[4,1,1,3],[4,3,1,3,4], [4,5,3,10,11,2]])
//let r = isScramble_recursive_fail("abc", "acb")

// 😢 416. Partition Equal Subset Sum
//Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//
//Note:
//Each of the array element will not exceed 100.
//The array size will not exceed 200.
//Example 1:
//
//Input: [1, 5, 11, 5]
//
//Output: true
//
//Explanation: The array can be partitioned as [1, 5, 5] and [11].
//Example 2:
//
//Input: [1, 2, 3, 5]
//
//Output: false
//
//Explanation: The array cannot be partitioned into equal sum subsets.
// https://leetcode.com/problems/partition-equal-subset-sum/

// 不是很好构造subproblem
// 答案的方法太巧妙了。
// 动态规划中构建的表，不是和 nums.count 有关，还是和元素的 sum 有关。
// 所以这里就能够理解到 为什么给出数组中元素的范围了。以及没有正数，到底怎么用

// 需要重新再写

// failed at [1,2,5]
// 但是下面的代码在大数据上会TLE

// DP 方法,除此之外还有DFS BIT 还有更屌的 bit实现

func canPartition(_ nums: [Int]) -> Bool {
    if nums.count == 1 {
        return false
    }
    
    var sum = nums.reduce(0, + )
    if sum % 2 != 0 {
        return false
    }
    sum = sum >> 1
    var map = [Bool](repeating: false, count: sum + 1)
    let len = nums.count
    map[0] = true
    for i in 1...len {
        let st = nums[i-1]
        if st > sum {
            return false
        }
        for j in (st...sum).reversed() {
            map[j] = map[j] || map[j-st]
        }
    }
    
    return map[sum]
}

// OJ 上跑会TLE

//let re = canPartition([7,36,41,74,96,24,73,65,15,47,75,92,68,25,58,11,26,55,5,16,96,92,47,96,24,42,20,92,92,1,72,20,54,2,18,80,50,37,13,11,23,80,82,72,55,95,56,91,39,90,83,91,44,41,18,48,96,97,45,4,70,36,40,27,34,25,38,27,7,80,69,87,30,99,72,96,64,59,72,74,15,66,80,63,33,28,50,26,54,46,3,81,48,84,97,85,51,41,14,19])

