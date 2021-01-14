Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

 

Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:

Input: head = []
Output: []

 

Constraints:

    The number of nodes in the list is in the range [0, 5 * 104].
    -105 <= Node.val <= 105



****************************************

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
    // using merge sort
    // time=0(nlogn)
    // space=0(1)
    ListNode* merge(ListNode* l1,ListNode* l2) //merge two sorted ll
    {
        
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l2->val < l1->val)
        {
            return merge(l2,l1);
        }
        if(l1->next==NULL)
        {
            l1->next=l2;
            return l1;
        }
        ListNode* curr1=l1;
        ListNode* next1=l1->next;
        ListNode* curr2=l2;
        ListNode* next2=l2->next;
        while(next1 && curr2)
        {
            if((curr2->val>=curr1->val) && (curr2->val<=next1->val)) // curr2 lies bn curr1 and next1
            {
                next2=curr2->next;
                curr1->next=curr2;
                curr2->next=next1;
                curr1=curr2;
                curr2=next2;
            }
            else{
             if(next1->next) // if not null
            {
                curr1=curr1->next;
                next1=next1->next;
            }
            else{
                next1->next=curr2;
                return l1;
            }
            }
            
        }
        return l1;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        // slow points to prev mid
        ListNode* mid=slow->next;
        slow->next=NULL;
        ListNode* l1=sortList(head); // start to mid-1
        ListNode* l2=sortList(mid); // mid to end
        return merge(l1,l2);
        }
};
