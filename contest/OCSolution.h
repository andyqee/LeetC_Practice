//
//  OCSolution.h
//  contest
//
//  Created by ethon_qi on 2/11/2016.
//  Copyright © 2016 andy. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OCSolution : NSObject

//15. 3Sum   QuestionEditorial Solution  My Submissions
//Total Accepted: 157590
//Total Submissions: 773029
//Difficulty: Medium
//Contributors: Admin
//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Note: The solution set must not contain duplicate triplets.
//
//For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//A solution set is:
//[
// [-1, 0, 1],
// [-1, -1, 2]
// ]

- (NSArray *)threeSum:(NSArray *)nums;

@end
