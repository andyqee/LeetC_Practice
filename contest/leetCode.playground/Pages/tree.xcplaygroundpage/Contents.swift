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

//100. Same Tree   QuestionEditorial Solution  My Submissions
//Difficulty: Easy
//Contributors: Admin
//Given two binary trees, write a function to check if they are equal or not.
//
//Two binary trees are considered equal if they are structurally identical and the nodes have the same value

func isSameTree(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
    if p == nil && q == nil {
        return true
    } else if p != nil && q != nil {
        return (p!.val == q!.val) && isSameTree(p!.left, q!.left) && isSameTree(p!.right, q!.right)
    } else {
        return false
    }
}

//递归写法，容易犯的低级错误时参数的名称 可能会写错
func isSameTree_iterate(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
    var stack = [TreeNode?]()
    stack.append(p)
    stack.append(q)
    
    var res = false
    while !stack.isEmpty {
        let pNode = stack.removeFirst()
        let qNode = stack.removeFirst()
        
        if pNode == nil && qNode == nil {
            res = true
        } else if pNode != nil && qNode != nil {
            if (pNode!.val == qNode!.val) {
                res = true
            } else {
                return false
            }
            stack.append(pNode!.left)
            stack.append(qNode!.left)
            stack.append(pNode!.right)
            stack.append(qNode!.right)
        } else {
            return false
        }
    }
    return res
}

//98. Validate Binary Search Tree   QuestionEditorial Solution  My Submissions

//Difficulty: Medium
//Contributors: Admin
//Given a binary tree, determine if it is a valid binary search tree (BST).
//
//Assume a BST is defined as follows:
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.

//Example 1:
//  2
// / \
//1   3
//Binary tree [2,1,3], return true.
//Example 2:
//   1
//  / \
// 2   3
//Binary tree [1,2,3], return false.

// 这个解决犯了个错误在于，没有校验 left subtree 中的最大值，是不是比中的要小。只比较了left subtree 中的node 值，是不够的
func isValidBST(_ root: TreeNode?) -> Bool {
    if root == nil {
        return true
    }
    var res = true
    if root!.left != nil {
        if (root!.left!.val < root!.val) && isValidBST(root!.left) {
            res = true
        } else {
            return false
        }
    }
    if root!.right != nil {
        if (root!.right!.val > root!.val) && isValidBST(root!.right) {
            res = true
        } else {
            return false
        }
    }
    return res
}

func isValidBST_new(_ root: TreeNode?) -> Bool {
    return doValidBST(root, Int.min, Int.max)
}

func doValidBST(_ root: TreeNode?, _ minV: Int, _ maxV: Int) -> Bool {
    if root == nil {
        return true
    }
    if root!.val >= maxV || root!.val <= minV {
        return false
    }
    return doValidBST(root!.left, minV, root!.val) && doValidBST(root!.right, root!.val, maxV)
}

// 这个递归版的有些问题，也就是说这种recursive 转成iterate 的思路是有问题的。

func worong_isValidBST_new_iterate(_ root: TreeNode?) -> Bool {
    if root == nil {
        return true
    }
    var stack = [TreeNode?]()
    stack.append(root)
    
    var paramStack = [Int]()
    paramStack.append(Int.min)
    paramStack.append(Int.max)
    
    while !stack.isEmpty {
        let node = stack.removeFirst()
        if node == nil {
            return false
        }
        let minV = paramStack.removeFirst()
        let maxV = paramStack.removeFirst()
        
        if node!.val >= maxV || node!.val <= minV {
            return false
        }
        stack.append(node!.left)
        paramStack.append(minV)
        paramStack.append(node!.val)
        
        stack.append(node!.right)
        paramStack.append(node!.val)
        paramStack.append(maxV)
    }
    return true
}

// 利用inorder https://discuss.leetcode.com/topic/46016/learn-one-iterative-inorder-traversal-apply-it-to-multiple-tree-questions-java-solution/2

func isValidBST_inorder(_ root: TreeNode?) -> Bool {
    if root == nil {
        return true
    }
    var stack = [TreeNode?]()
    var prevNode : TreeNode? = nil
    var node = root
    
    while !stack.isEmpty || node != nil {
        while node != nil {
            stack.append(node)
            node = node!.left
        }
        node = stack.removeFirst()
        if prevNode != nil && node!.val <= prevNode!.val {
            return false
        }
        prevNode = node
        node = node!.right
    }
    return true
}
// 同样的test case OJ 上是没过，这里过了
//let treeNode = TreeNode.init(1)
//let leftNode = TreeNode.init(0)
//let rightNode = TreeNode.init(3)
//treeNode.left = leftNode
//treeNode.right = rightNode
//
//let test = isValidBST(treeNode)

//102. Binary Tree Level Order Traversal   QuestionEditorial Solution
//Difficulty: Easy
//Contributors: Admin
//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//   3
//  / \
// 9  20
//    /  \
//   15   7
//return its level order traversal as:
//[
// [3],
// [9,20],
// [15,7]
//]

func levelOrder(_ root: TreeNode?) -> [[Int]] {
    if root == nil {
        return [[Int]]()
    }
    var res = [[Int]]()
    levelOrder(root!, 0, &res)
    return res
}
// pre order kind of DFS
func levelOrder(_ root: TreeNode, _ level: Int, _ res : inout [[Int]]) {
    if res.count == level {
        res.append([root.val])
    } else {
        res[level].append(root.val)
    }
    
    if root.left != nil {
        levelOrder(root.left!, level + 1, &res)
    }
    if root.right != nil {
        levelOrder(root.right!, level + 1, &res)
    }
}

// BFS
func levelOrder_queue(_ root: TreeNode?) -> [[Int]] {
    if root == nil {
        return [[Int]]()
    }
    var queue = [TreeNode]()
    queue.append(root!)
    
    var res = [[Int]]()
    while !queue.isEmpty {
        let cunt = queue.count
        var subArray = [Int]()
        for _ in 0..<cunt {
            let node = queue.removeLast()
            subArray.append(node.val)
            if node.left != nil {
                queue.append(node.left!)
            }
            if node.right != nil {
                queue.append(node.right!)
            }
        }
        res.append(subArray)
    }
    return res
}


//107. Binary Tree Level Order Traversal II   QuestionEditorial Solution  My Submissions
//Total Accepted: 101617
//Total Submissions: 276651
//Difficulty: Easy
//Contributors: Admin
//Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//  /  \
// 15   7
//return its bottom-up level order traversal as:
//[
//  [15,7],
//  [9,20],
//  [3]
//]

//func levelOrderBottom(_ root: TreeNode?) -> [[Int]] {
//    
//}


//230. Kth Smallest Element in a BST

//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//Note:
//You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//
//Follow up:
//What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
//
//Hint:
//
//Try to utilize the property of a BST.
//What if you could modify the BST node's structure?
//The optimal runtime complexity is O(height of BST).

//inorder search

// iterate & recursive

func kthSmallest_iterative(_ root: TreeNode?, _ k: Int) -> Int {
    if root == nil {
        return 0 // assume to return 0 Indicate not found
    }
    var count = k
    
    var stack = [TreeNode?]() //stack
    var node = root
    while !stack.isEmpty || node != nil {
        while node != nil {
            stack.append(node)
            node = node!.left //update the node
        }
        //node's left child is nil.it is the samallest now
        node = stack.removeLast()
        count -= 1
        if count == 0 {
            return node!.val
        }
        // node right
        node = node!.right
    }
    return 0
}

// recuriseve 算法一定要注意返回值 return 的传递

func kthSmallest_recursive(_ root: TreeNode?, _ k: Int) -> Int {
    if root == nil {
        return 0 // assume to return 0 Indicate not found
    }
    
    var arr = [Int]()  // we can use
    var res = 0
    doKthSmallest(root!, k, &arr, &res)
    return arr[k - 1]
}

func doKthSmallest(_ root: TreeNode, _ k: Int, _ array: inout [Int], _ val : inout Int){
// 原来的实现，问题是 这里进来的node前面一个是k-1，但是不能说明这个是Kth，
// 因为需要经过下面root.left 递归下去，找到之后最小的那个才是
//    if array.count == k - 1 {
//        val = root.val
//        return
//    }
    if array.count >= k {
        return
    }
    if root.left != nil {
        doKthSmallest(root.left! , k, &array, &val)
    }
    array.append(root.val)
    if root.right != nil {
        doKthSmallest(root.right! , k, &array, &val)
    }
}

let treeNode = TreeNode.init(2)
let rightNode = TreeNode.init(3)
let leftNode = TreeNode.init(1)

treeNode.left = leftNode
treeNode.right = rightNode

//let A = kthSmallest_recursive(treeNode, 2)
//let B = kthSmallest_iterative(treeNode, 2)

// use counter to count the idx
func doKthSmallest_count(_ root: TreeNode, _ k: Int, _ idx: inout Int, _ val : inout Int) {
    if root.left != nil {
        doKthSmallest_count(root.left!, k, &idx, &val)
    }
    idx += 1
    if idx == k {
        val = root.val
        return
    }
    if root.right != nil {
        doKthSmallest_count(root.right! , k, &idx, &val)
    }
}

func pathSum(_ root: TreeNode?, _ sum: Int) -> Int {
    if root == nil {
        return 0
    }
    if root!.left == nil && root!.right == nil {
        return ((root!.val == sum ) ? 1 : 0)
    }
    
    var count = 0
    if (root!.left != nil) {
        count += pathSum(root!.left, sum - root!.val) + ((root!.val == sum ) ? 1 : 0) + pathSum(root!.left, sum)
    }
    if (root!.right != nil) {
        count += pathSum(root!.right, sum - root!.val) + ((root!.val == sum ) ? 1 : 0) + pathSum(root!.right, sum)
    }
    return count
}


//103. Binary Tree Zigzag Level Order Traversal   QuestionEditorial Solution  My Submissions
//Total Accepted: 77494
//Total Submissions: 247492
//Difficulty: Medium
//Contributors: Admin
//Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//3
/// \
//9  20
///  \
//15   7
//return its zigzag level order traversal as:
//[
//[3],
//[20,9],
//[15,7]
//]

func zigzagLevelOrder(_ root: TreeNode?) -> [[Int]] {
    if root == nil {
        return [[Int]]()
    }
    
    var queue = [TreeNode]()
    var res = [[Int]]()
    queue.append(root!)
    
    var reverse = false
    
    while !queue.isEmpty {
        let count = queue.count
        var subArray = [Int]()
        for _ in 0..<count {
           let node = queue.removeFirst()
           subArray.append(node.val)
           
            if node.left != nil {
                queue.append(node.left!)
            }
            if node.right != nil {
                queue.append(node.right!)
            }
        }
        if reverse {
            res.append(subArray.reversed())
        } else {
            res.append(subArray)
        }
        reverse = !reverse
    }
    return res
}

//114. Flatten Binary Tree to Linked List   QuestionEditorial Solution  My Submissions
//Total Accepted: 102256
//Total Submissions: 309986
//Difficulty: Medium
//Contributors: Admin
//Given a binary tree, flatten it to a linked list in-place.
//
//For example,
//Given
//
//1
/// \
//2   5
/// \   \
//3   4   6
//The flattened tree should look like:
//1
//\
//2
//\
//3
//\
//4
//\
//5
//\
//6

func flatten(_ root: TreeNode?) {
    if let VRoot = root {
        doFlatten(VRoot)
    }
}

func doFlatten(_ root: TreeNode) -> TreeNode {
    if root.left == nil && root.right == nil {
        return root
    }
    
    if root.left != nil && root.right != nil {
        var left = doFlatten(root.left!)
        var right = doFlatten(root.right!)
        left.right = root.left!
        root.left = nil
    }
    if root.left != nil {
        root.right = root.left
        root.left = nil
    }
    return  doFlatten(root.right!)
}

//func sortedArrayToBST(_ nums: [Int]) -> TreeNode? {
    
//}







