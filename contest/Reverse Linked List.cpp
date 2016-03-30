//
//  Reverse Linked List.cpp
//  contest
//
//  Created by andy on 15/5/15.
//  Copyright (c) 2015 andy. All rights reserved.
//


//Reverse a singly linked list.

#include <stdio.h>

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* next = head->next;
        curr->next = NULL;    //容易犯的错误是，这里忘记把链表的头节点 设置为NULL 。如果不设置 会导致死循环
        
        while (next) {
            ListNode* nnext = next->next;
            next->next = curr;
            
            curr = next;
            next = nnext;
            
        }
        return curr;
    }
};
