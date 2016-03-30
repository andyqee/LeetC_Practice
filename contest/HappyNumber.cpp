//
//  HappyNumber.cpp
//  contest
//
//  Created by andy on 7/5/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>

/**
 *
 *  https://leetcode.com/problems/happy-number/
 */

//Write an algorithm to determine if a number is "happy".
//
//A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
//
//Example: 19 is a happy number
//
//1^2 + 9^2 = 82
//8^2 + 2^2 = 68
//6^2 + 8^2 = 100
//1^2 + 0^2 + 0^2 = 1

// 这个和linkedlist 找cycle 一样，用快慢指针

class Solution {
    
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        
        do {
            slow = cal(slow);
            fast = cal(cal(fast));
            
        } while (slow != fast);
        return (slow == 1);
    }
    
    int cal(int n) {
        int t = n;
        int sum = 0;
        while (t != 0) {
            sum += (t % 10) * (t % 10);
            t = t / 10;
        }
        return sum;
    }
};

// 用表的方法，更快，但消费内存空间

//class Solution {
//public:
//    int tran(int n){
//        int ans = 0;
//        while(n){
//            ans += pow(n%10, 2);
//            n/=10;
//        }
//        return ans;
//    }
//    bool isHappy(int n) {
//        bool rep[1000];
//        memset(rep, 0, sizeof(rep));
//        n = tran(n);
//        while(!rep[n]){
//            rep[n] = true;
//            if(n == 1)
//                return true;
//            n = tran(n);
//        }
//        return false;
//    }
//};

/**
 *
 *  还有数学技巧性比较强的方法
 */

//public boolean isHappy(int n) {
//    if(n<=0) return false;
//    while(true){
//        int sum=0;
//        while(n!=0){
//            sum+=(n%10)*(n%10);
//            n=n/10;
//        }
//        if(sum/10==0){
//            if(sum==1||sum==7) return true;
//            else return false;
//        }
//        n=sum;
//    }
//}

//bool isHappy(int n) {
//    while(n>6){
//        int next = 0;
//        while(n){next+=(n%10)*(n%10); n/=10;}
//        n = next;
//    }
//    return n==1;
//}
