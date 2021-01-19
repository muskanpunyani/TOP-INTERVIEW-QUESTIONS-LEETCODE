Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false

Example 2:

Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?

***********************************
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
    //0(n) time,0(1) memory
    ListNode* reverse(ListNode* temp)
    {
        ListNode* prev=NULL;
        ListNode* curr=temp;
        while(curr!=NULL)
        {
            ListNode* p=curr->next;
            curr->next=prev;
            prev=curr;
            curr=p;
        }
          return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)  // len=1
        {
            return true;
        }
        if(head->next->next==NULL) // len=2
        {
            return head->val==head->next->val;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL  && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* slow1=slow->next;
        slow->next=NULL;
        ListNode* mid_next=reverse(slow1);
        ListNode* node1=head;
        ListNode* node2=mid_next;
        while(node1!=NULL && node2!=NULL)
        {
         if(node1->val!=node2->val)
             return false;
            
            node1=node1->next;
            node2=node2->next;
                
        }
        return true;
    }
};
