//
//  Remove Nth Node From End of List.cpp
//  contest
//
//  Created by andy on 21/5/15.
//  Copyright (c) 2015 andy. All rights reserved.
//

#include <stdio.h>

//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//Given linked list: 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note:
//Given n will always be valid.
//Try to do this in one pass.

using namespace std;

/**
 * Definition for singly-linked list.
 **/

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
// 这是一个次的代码

class SolutionA {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return head;
        }
#warning 这个代码的问题是，如果这行N 真好是这个链表的长度，那么删除的是第一个点。 那么就有问题了
        
        ListNode* newHead = head;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        //fast 指针提前走n 步
        while (n--) {
            fast = fast->next;
        }
        
        while (fast->next == NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        
        return newHead;
    }
};

class SolutionB {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return head;
        }
        //在链表的头部，新添加一个新的head。 用于删除是链表头的情形
        
        ListNode newHead(-1);
        newHead.next = head;      //指针用 ->
        
        ListNode* fast = &newHead;
        ListNode* slow = &newHead;
        
        //fast 指针提前走n 步
        while (n--) {
            fast = fast->next;
        }
        
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode *tmp = slow->next;      // 这个对于链表头也是成立的。
        slow->next = slow->next->next;
        delete tmp;                      // 需要手动清理这个被删掉的对象，这个和Java 不同，如果没有引用指向它，那么会被自动回收。

        head = newHead.next;
        
        return head;
    }
};


#warning 这个是比较酷的办法

//class Solution
//{
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n)
//    {
//        ListNode** t1 = &head, *t2 = head;
//        for(int i = 1; i < n; ++i)
//        {
//            t2 = t2->next;
//        }
//        while(t2->next != NULL)
//        {
//            t1 = &((*t1)->next);
//            t2 = t2->next;
//        }
//        *t1 = (*t1)->next;
//        return head;
//    }
//};