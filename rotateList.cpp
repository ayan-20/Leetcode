//Source : https://leetcode.com/problems/rotate-list/
//Author : Ayan Agrawal
//Date   : 23-07-2021

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL, *curr = head;
        while(curr)
        {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        
        //first reversing first k nodes then remaining n-k node
        //then reversing whole list
        
        if(head ==NULL) return head;
        int size = 0;
        ListNode* d = head;
        while(d)
        {
            size++;
            d=d->next;
        }
        while(k>=size) k = k%size;
        k = size-k;
        int c=1;
        ListNode* temp = head,*temp2 = head;
        while(temp && c<k)
        {
            c++;temp=temp->next;
        }
        ListNode *second = temp->next;
        temp->next =NULL;
        ListNode* head1 = reverse(head);
        ListNode* head2 = reverse(second);
        temp2 ->next = head2;
        return reverse(head1);
    }
};