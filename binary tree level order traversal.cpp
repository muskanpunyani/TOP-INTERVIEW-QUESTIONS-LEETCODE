Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]


***********************************
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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> q;
      
        q.push(root);
         
        while(q.empty()==false)
        {
            int count=q.size();  // the sub vector will be of queue size
            vector<int> v;
            for(int i=0;i<count;i++){
          
            TreeNode* node=q.front();
            q.pop();
            v.push_back(node->val);
            
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
            }
            ans.push_back(v);
          }
        
        return ans;
        
        
    }
};
