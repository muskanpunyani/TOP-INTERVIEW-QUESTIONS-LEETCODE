You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:

Input: lists = []
Output: []

Example 3:

Input: lists = [[]]
Output: []

 

Constraints:

    k == lists.length
    0 <= k <= 10^4
    0 <= lists[i].length <= 500
    -10^4 <= lists[i][j] <= 10^4
    lists[i] is sorted in ascending order.
    The sum of lists[i].length won't exceed 10^4.


************************************************
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
    ListNode* domerge(ListNode* l1,ListNode* l2) // function to merge two  sorted list (same)
    {
        if(l1==l2)
            return l1;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l2->val < l1->val)     // smaller head will be taken
        {
            return domerge(l2,l1);
        }
        if(l1->next==NULL)  // if only 1 element in 1st list
        {
            l1->next=l2;
            return l1;
        }
        ListNode* curr1=l1;
        ListNode* next1=l1->next;
        ListNode* curr2=l2;
        ListNode* next2=l2->next;
        while(curr2 && next1 )     // curr2 lies bn curr1 and next 1
        {
            // check
            if(curr1->val<=curr2->val && curr2->val<=next1->val)
            {
                next2=curr2->next;
                curr1->next=curr2;
                curr2->next=next1;
                curr1=curr2;
                curr2=next2;
            }
            else{
                if(next1->next) // if ll 1 is having more nodes
                {
                    curr1=curr1->next;
                    next1=next1->next;
                }
                else {   // if this is the last node of l1 then just combine it to l2
                    next1->next=curr2;
                    return l1;
                }
            }
        }
        return l1;
        
    }
    ListNode* merge(vector<ListNode*>& lists,int start,int end)
    {
        if(start==end)          
        {
            return lists[start];
        }
        if(start+1==end) // pair of 2
        {
            return domerge(lists[start],lists[end]);
        }
        int mid=((start+end)/2);
        ListNode* l1= merge(lists,start,mid); // divide
        ListNode* l2= merge(lists,mid+1,end);
        return domerge(l1,l2);                // merge
        
    
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // using divide and conquer
        int n=lists.size();
        if(n==0)
        {
            return NULL;  // empty
        }
        if(n==1)
        {
            return lists[0];  // only 1 list
        }
        int start=0;
        int end=n-1;
        return merge(lists,start,end);
        
    }
};
