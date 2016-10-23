//: [Previous](@previous)

import Foundation

//https://leetcode.com/problems/sum-of-left-leaves/

//404. Sum of Left Leaves   QuestionEditorial Solution  My Submissions

//Contributors: Admin
//Find the sum of all left leaves in a given binary tree.
//
//Example:
//
//    3
//   / \
//  9  20
//     / \
//   15   7
//
//There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

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

// 对于treeNode 为nil，其返回值 能否为0
// 如果tree 只有一个 节点，这个算left吗，肯定不算对吧
// !!!! 😢😢 1 - W
// https://leetcode.com/problems/sum-of-left-leaves/

//recursive 

func sumOfLeftLeaves(_ root: TreeNode?) -> Int {
    if root == nil {
        return 0
    }
    var res = 0
    if root!.left != nil {
        if root!.left!.left == nil && root!.left!.right == nil {
            res = root!.left!.val
        } else {
            res = sumOfLeftLeaves(root!.left!)
        }
    }
    if root!.right != nil {
        res += sumOfLeftLeaves(root!.right!)
    }
    return res
}

// iterate 

func sumOfLeftLeaves_iterate(_ root: TreeNode?) -> Int {
    if root == nil {
        return 0
    }
    var res = 0
    var stack = [TreeNode]()
    stack.append(root!)
    
    while !stack.isEmpty {
        let node = stack.removeFirst()
        if node.left != nil {
            if node.left!.left == nil && node.left!.right == nil {
                res += node.left!.val
            } else {
                stack.append(node.left!)
            }
        }
        if node.right != nil {
            stack.append(node.right!)
        }
    }
    return res
}

//257. Binary Tree Paths   QuestionEditorial Solution  My Submissions
//Difficulty: Easy
//Given a binary tree, return all root-to-leaf paths.

//For example, given the following binary tree:

//   1
// /  \
// 2   3
//  \
//   5
//All root-to-leaf paths are:

// ["1->2->5", "1->3"]
// leetcode 这道题不支持 swift

func binaryTreePaths(_ root: TreeNode?) -> [String] {
    if root == nil {
        return [""]
    }
    var paths = [String]()
    if root!.left == nil && root!.right == nil {
        paths.append("\(root!.val)")
    }
    
    if(root!.left !== nil) {
        let leftPaths = binaryTreePaths(root!.left!)
        leftPaths.forEach({ (str) in
            if str.characters.count > 0 {
                let newpath = "\(root?.val)" + "->" + str
                paths.append(newpath)
            }
        })
    }
    if (root!.right != nil) {
        let rightPath = binaryTreePaths(root!.right!)
        rightPath.forEach({ (str) in
            if str.characters.count > 0 {
                let newpath = "\(root?.val)" + "->" + str
                paths.append(newpath)
            }
        })
    }
    return paths
}

//337. House Robber III
//The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
//Determine the maximum amount of money the thief can rob tonight without alerting the police.
//Example 1:
//   3
//  / \
// 2   3
//  \   \
//   3   1
//Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
//Example 2:
//     3
//    / \
//   4   5
//  / \   \
// 1   3   1
//Maximum amount of money the thief can rob = 4 + 5 = 9.

//递归出现 TLE。但是c++ 版本的是可以过的
// 第一版，
// 想关联的 https://leetcode.com/problems/house-robber-ii/

func rob(_ root: TreeNode?) -> Int {
    // 基本case
    if root == nil {
        return 0
    }
    if root!.left == nil && root!.right == nil {
        return root!.val
    }
    
    //case one pick not root
    let resA : Int = rob(root!.left) + rob(root!.right)
    //case two: pick root
    var res :Int = root!.val //注意初始值
    if root!.left != nil {
        res += rob(root!.left!.left) + rob(root!.left!.right)
    }
    if root!.right != nil {
        res += rob(root!.right!.left) + rob(root!.right!.right)
    }
    return max(res , resA)
}
//? 😯😖😖
//func rob(_ root: TreeNode?) -> Int {
//    if root == nil {
//        return 0
//    }
//    var stack = [TreeNode]()
//    stack.append(root)
//    
//    var ans = 0
//    
//    while !stack.isEmpty {
//        let node = stack.removeFirst()
//        if node.left == nil && root!.right == nil {
//            ans += node.val
//        }
//        stack.append(node.left!)
//        stack.append(node.right!)
//        
//        if let left = node.left {
//            if left.left != nil {
//                stack.append(left.left)
//            }
//            if left.right != nil {
//                stack.append(left.right)
//            }
//        }
//        
//        if node!.left != nil {
//            
//            stack.append(node!.left!.left)
//        }
//    }
//}

// 第二版添加hash表避免重复计算，对于这种有限制条件的，应该联想起动态规划

//class solution
//{
//    //但是这个问题在于 treeNode 不是 hashable，不能用做key. Java是可以直接用TreeNode 作key的
//    var map : [TreeNode: Int]
//    
//    init() {
//        self.map = [TreeNode: Int]()
//    }
//    
//    func do_rob(_ root: TreeNode?) -> Int {
//        // 基本case
//        if root == nil {
//            return 0
//        }
//        if root!.left == nil && root!.right == nil {
//            return root!.val
//        }
//        
//        if map[root] != nil {
//            return map[root]
//        }
//        
//        //case one pick not root
//        let resA : Int = rob(root!.left) + rob(root!.right)
//        //case two: pick root
//        var resB :Int = root!.val //注意初始值
//        if root!.left != nil {
//            resB += rob(root!.left!.left) + rob(root!.left!.right)
//        }
//        if root!.right != nil {
//            resB += rob(root!.right!.left) + rob(root!.right!.right)
//        }
//        let r = max(resB , resA)
//        map[root] = r
//        return r
//    }
//}

// 这个思路还是挺巧妙的 🆒

func rob3(_ root: TreeNode?) -> Int {
    let res = do_rob_3(root)
    return max(res.0, res.1)
}

func do_rob_3(_ root: TreeNode?) -> (Int, Int) {
    if root == nil {
        return (0, 0)
    }
    let left : (Int, Int) = do_rob_3(root!.left)
    let right : (Int, Int) = do_rob_3(root!.right)
    
    let noRoot   = max(left.0, left.1) + max(right.0, right.1)
    let haveRoot = root!.val + left.1 + right.1
    return (haveRoot, noRoot)
}














