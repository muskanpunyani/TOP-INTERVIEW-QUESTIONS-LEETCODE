Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

******************************
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
 // time=space=0(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector< vector<int> > ans;  //to store final ans
           if(root==NULL)
        {
            return ans;
        }
        int val1=0 ;  //if val is false then left to right else right to left
        queue<TreeNode*> q;  //queue
     
        q.push(root);  //pushing root element initially
        //applying bfs
        while(q.empty()!=true)  //for every level q is filled with elements
        {
            int l=q.size();   //size of queue
            vector<int> v1(l);  //vector to store val of every level
            for(int i=0;i<l;i++)    //traversing the size of queue
            {
                TreeNode* opt=q.front();   //take the first elem
                q.pop();   //pop it out
                if(opt->left)   //push left elem
                {
                    q.push(opt->left);
                }
                if(opt->right)  //push right elem
                {
                    q.push(opt->right);
                }
                if(val1==0)   //left to right
                {
                    v1[i]=opt->val;
                }
                else{        //right to left
                    v1[l-i-1]=opt->val;   //pushed in reverse order
                }
                
            }
            val1=!val1;   //reverese the direction
            ans.push_back(v1);   //push the level vector
           
            
        }
        return ans;
        
    }
};
