

#import "tree.h"

//#include <stdio.h>
//#include <vector>

//using namespace std;

@interface TreeNode : NSObject
@property (nonatomic, strong) TreeNode *left;
@property (nonatomic, strong) TreeNode *right;
@property (nonatomic) NSInteger val;

@end

@implementation TreeNode

@end


@implementation Solution (kthSmallest_I)

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

// iteratvie

// 1. 注意k 的范围

// inorder left < root < right

// 这个递归版本，确实很容易出错。 尤其是在使用while 控制的时候容易写错

//avg: T = O(height) S = O(height)

- (NSInteger)kthSmallest_I:(TreeNode *)treeNode withK:(NSInteger)k
{
	if (treeNode == nil) {
		return NSIntegerMax;
	}
	NSInteger count = 0;   
	NSMutableArray *stack = [NSMutableArray array]; 
	TreeNode *node = treeNode;
	if (stack.count != 0 || node != nil) {
		while (node != nil) {
			[stack addObject:node];
			node = node.left;
		}
		node = [stack lastObject];
		[stack removeLastObject];
		count++;
		if (count == k) {
			return node.val;
		}
		node = node.right;
	}
	return NSIntegerMax;
}

// dfs 
static NSMutableArray<NSNumber *> *valArray;

- (NSInteger)kthSmallest_R:(TreeNode *)treeNode withK:(NSInteger)k
{
	if (treeNode == nil) {
		return NSIntegerMax;
	}
	valArray = [NSMutableArray array];
	[self kthSmallest_R:treeNode withK:k];
	return [valArray[k - 1] integerValue];
}

- (void)doKthSamllest:(TreeNode *)treeNode withK:(NSInteger)k  
{
	if (treeNode.left != nil) {
		[self doKthSamllest:treeNode.left withK:k];
	}
	[valArray addObject:@(treeNode.val)];
	if([valArray count] == k) {
		return;
	}
	if (treeNode.right != nil) {
		[self doKthSamllest:treeNode.right withK:k];
	}
}

// // bfs 有重复计算，但是想法是很不错的

// public int kthSmallest(TreeNode root, int k) {
//         int count = countNodes(root.left);
//         if (k <= count) {
//             return kthSmallest(root.left, k);
//         } else if (k > count + 1) {
//             return kthSmallest(root.right, k-1-count); // 1 is counted as current node
//         }
        
//         return root.val;
//     }
    
//     public int countNodes(TreeNode n) {
//         if (n == null) return 0;
        
//         return 1 + countNodes(n.left) + countNodes(n.right);
//     }

@end

// 437.437. Path Sum III   QuestionEditorial Solution  My Submissions
// Total Accepted: 3607
// Total Submissions: 9536
// Difficulty: Easy
// Contributors: Stomach_ache
// You are given a binary tree in which each node contains an integer value.

// Find the number of paths that sum to a given value.

// The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

// The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

// Example:

// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

//       10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1

// Return 3. The paths that sum to 8 are:

// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3. -3 -> 11

@implementation Solution (PathSum_3)
//写了几遍，竟然全错了, 对题目的意思弄错了

//- (NSInteger)pathSumWithRoot:(TreeNode *)root andSum:(NSInteger)sum 
//{
	// if (root == nil) {
	// 	return 0;
	// } 
	// NSInteger count = 0;

	// if (root.left != nil) {
	// 	count += [self pathSumWithRoot:root.left andSum:sum - root.val] + (root.val == sum) ? 1 : 0;
	// 	count += [self pathSumWithRoot:root.left andSum:sum]; //凡事涉及到整数求和，必须考虑到数据规模是否会导致越界
	// }
	// if (root.right != nil) {
	// 	count += [self pathSumWithRoot:root.right andSum:sum - root.val] + (root.val == sum) ? 1 : 0;
	// 	count += [self pathSumWithRoot:root.right andSum:sum]
	// }

	// return count;
//}

@end

@implementation Solution (BinaryTreePaths)

//对题目的意思
// Space = O(nlgn) 
// TODO: 这个问题的时间复杂度的分析 T = 
// my solution

- (NSArray<NSString *> *)binaryTreePaths:(TreeNode *)node 
{
	if(node == nil) {
		return nil;
	}
	NSMutableArray *rest = [NSMutableArray array];

	if(node.left != nil) {
		NSArray *leftSubRes = [self binaryTreePaths:node.left];
		for (NSString *subRes in leftSubRes) {
			[rest addObject: [NSString stringWithFormat:@"%ld->%@", (long)node.val, subRes]];
		}
	}
	if(node.right != nil) {
		NSArray *rightSubRes = [self binaryTreePaths:node.right];
		for (NSString *subRes in rightSubRes) {
			[rest addObject: [NSString stringWithFormat:@"%ld->%@", (long)node.val, subRes]];
		}
	} 
	if(node.right == nil && node.left == nil) {
		[rest addObject: [NSString stringWithFormat:@"%ld", (long)node.val]];
	}
	return rest;
}
// From web
- (NSArray<NSString *> *)binaryTreePaths_LJSolution:(TreeNode *)node 
{
	if(!node) {
		return nil;
	}
	NSMutableArray *rest = [NSMutableArray array];
	[self binaryTreePath:node prefixStr:[@"" mutableCopy] array:rest];
	return rest;
}

- (void)binaryTreePath:(TreeNode *)node prefixStr:(NSMutableString *)prefixStr array:(NSMutableArray *)array
{
	if(!node.left && !node.right) {
        [prefixStr appendString:[NSString stringWithFormat:@"%ld", (long)node.val]];
		[array addObject:prefixStr];
	}
	if(!node.left) {
		NSMutableString *temp = [prefixStr mutableCopy];
        [temp appendString:[NSString stringWithFormat:@"%ld->", (long)node.left.val]];
		[self binaryTreePath:node.left prefixStr:temp array:array];
	}
	if(!node.right) {
		NSMutableString *temp = [prefixStr mutableCopy];
        [temp appendString:[NSString stringWithFormat:@"%ld->", (long)node.right.val]];
		[self binaryTreePath:node.right prefixStr:temp array:array];
	}
}

//vector<string> binaryTreePaths(TreeNode* root) {
//
//}

@end
