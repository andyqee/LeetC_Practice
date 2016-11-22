//
//  OCSolution.m
//  contest
//
//  Created by ethon_qi on 2/11/2016.
//  Copyright © 2016 andy. All rights reserved.
//

#import "OCSolution.h"

@implementation OCSolution

- (NSArray *)threeSum:(NSArray<NSNumber *> *)nums
{
    NSMutableArray *resu = [NSMutableArray array];
    NSMutableSet *set = [NSMutableSet set];

    for (NSUInteger idx = 0; idx < nums.count; idx++) {
        NSInteger left = 0 - nums[idx].integerValue;
        
        NSMutableArray *subArray = [NSMutableArray array];
        [subArray addObject:nums[idx]];
        
        for (NSUInteger j = 0; j < nums.count; j++) {
            if (j != idx) {
                if ([set containsObject:@(left - nums[j].integerValue)]) {
                    [subArray addObject:nums[j]];
                    [subArray addObject:@(left - nums[j].integerValue)];
                    
                    [set addObject:nums[j]];
                    [resu addObject:subArray];
                }
            }
        }
    }
    
    return resu;
}

@end
