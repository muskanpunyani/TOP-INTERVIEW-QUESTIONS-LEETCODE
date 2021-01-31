Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

 

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

 

Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz


***********************************************
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
    // 1 pass means 2 pointers
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast=head;
       for(int i=0;i<n;i++) // fast is nth node from begin
       {
           fast=fast->next;
       }
        if(fast==NULL)   // if nth from begin is last then nth from end will be head,thus remove head
            return head->next;
        
        // slow points to nth node from end
        //move till fast reaches end then slow reaches nth node from end
        while( fast->next!=NULL)
        {
         
            slow=slow->next;
            fast=fast->next;
        }
       //slow points to a prev node of nth from end
        slow->next=slow->next->next;
        
        return head;
    }
};
