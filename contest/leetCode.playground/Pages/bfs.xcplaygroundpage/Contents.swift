//: [Previous](@previous)

import Foundation

//: [Next](@next)

//101. Symmetric Tree
//
//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//But the following [1,2,2,null,3,null,3] is not:
//   1
//  / \
// 2   2
//  \   \
//  3    3

//Bonus points if you could solve it both recursively and iteratively.


// * Definition for a binary tree node.

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

// 关于tree 相关的问题，首先就是递归，然后是DFS 和BFS 的方法
// 按层遍历
// 如何判断一层呢

class Solution {
//    func isSymmetric(_ root: TreeNode?) -> Bool {
//        if root != nil {
//            return true
//        }
//        
//        var queue = [TreeNode?]()
//        queue.append(root!)
//        
//        while queue.isEmpty {
//            let node : TreeNode? = queue.first!
//            queue.removeFirst()
//            
//            var valArrays = [Int?]()
//            if node != nil {
//                if node!.left != nil {
//                    queue.append(node!.left)
//                }
//                if node!.right != nil {
//                    queue.append(node!.right!)
//                }
//                valArrays.append(node!.val)
//            } else {
//                valArrays.append(nil)
//            }
//            
//        }
//        return true
//    }
//    
//    private func isSynmetric(_ nums: [Int?]) {
//        if nums.count % 2 != 0 {
//            return false
//        }
//        var i = 0
//        var j = nums.count
//        
//        while i < j {
//            if nums[i] != nums[j] {
//                return false
//            }
//            i += 1
//            j += 1
//        }
//        return true
//    }
    func isSymmetric(_ root: TreeNode?) -> Bool {
        return root == nil || _doSymmetric(root!.left, root!.right)
    }
    
    private func _doSymmetric(_ left: TreeNode?, _ right: TreeNode?) -> Bool {
        if left == nil && right == nil {
            return true
        }
        if left != nil && right != nil {
           return (left!.val == right!.val) && _doSymmetric(left!.left, right!.right) && _doSymmetric(left!.right, right!.left)
        }
        return false
    }
    // 做完题目还要分析时间复杂度和空间复杂度
//    Complexity Analysis
//    
//    Because we traverse the entire input tree once, the total run time is O(n)O(n), where nn is the total number of nodes in the tree.
//    
//    The number of recursive calls is bound by the height of the tree. In the worst case, the tree is linear and the height is in O(n)O(n). Therefore, space complexity due to recursive calls on the stack is O(n)O(n) in the worst case.
    
}
