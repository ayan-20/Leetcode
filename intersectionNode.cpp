//Source : https://leetcode.com/problems/intersection-of-two-linked-lists/
//Author : Ayan Agrawal
//Date   : 28-06-2021

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        //It works because pointer A walks through List A and List B both
        //Pointer B also walks through List B and List A.
        //Regardless of the length of the two lists, the sum of the lengths are the same (i.e. a+b = b+a).
        //which means that the pointers sync up at the point of intersection.
        //If the lists never intersected, they'll sync up at the end of each list, both of which are null.
        
        if(headA==NULL || headB==NULL) return NULL;
        ListNode* ptr1 =headA;
        ListNode* ptr2 =headB;
        while(ptr1!=ptr2)
        {
            if(ptr1==NULL) ptr1 = headB;
            else ptr1=ptr1->next;
            if(ptr2==NULL) ptr2 = headA;
            else ptr2=ptr2->next; 
        }
        return ptr1;
    }
};