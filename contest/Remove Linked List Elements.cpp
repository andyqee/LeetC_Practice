//
//  Remove Linked List Elements.cpp
//  contest
//
//  Created by andy on 8/5/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        if (head == NULL) {
            return head;
        }
        
        ListNode* newHead = head;
        ListNode* prev = head;
        ListNode* curr = head;
        
        while (curr) {
            
            if (newHead->val == val) {
                newHead = newHead->next;
                curr = newHead;
            } else {
                
                if (curr->val == val) {
                    prev->next = curr->next;
                    curr = curr->next;
                } else {
                    prev = curr;
                    curr = curr->next;
                }
                
            }
        }
        return newHead;
    }
};


//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//        ListNode **p = &head;
//        while(*p != NULL)
//        {
//            if((*p)->val == val)
//                *p = (*p)->next;
//            else
//                p = &((*p)->next);
//        }
//        return head;
//    }
//};
