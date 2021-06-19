//Source : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
//Author : Ayan Agrawal
//Date   : 19-06-2021


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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* midOfList(ListNode* head)
    {
        ListNode *slow = head, *fast = head, *prev=head;
        while(fast && fast->next)
        {
            prev =slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev!=NULL) prev->next=NULL;
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        
        //find mid of linked list then recursively make the subtrees
        //Important point here is breaking the link of left sublist with right sublist
        //Beacuse we are treating it as a seperate list
        //end of the right sublist is already pointing to null.
        
        if(head==NULL) return NULL;
        ListNode* mid = midOfList(head);
        TreeNode* root = new TreeNode(mid->val);
        if(head==mid) return root;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
};