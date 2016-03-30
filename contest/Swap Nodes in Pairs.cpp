//
//  Swap Nodes in Pairs.cpp
//  contest
//
//  Created by andy on 21/5/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>

//Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

/**
 ** Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// 下面这个算法 是第一个版本， 但是如果 只有一个节点 会有问题
class SolutionA {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if (head == NULL ) {
            return head;
        }
        
        ListNode* secondNode = head->next;
        head->next = swapPairs(secondNode->next);
        secondNode->next = head;
        
        return secondNode;
    }
};

//第二个正确版本

class SolutionB {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* secondNode = head->next;
        head->next = swapPairs(secondNode->next);
        secondNode->next = head;
        
        return secondNode;
    }
};