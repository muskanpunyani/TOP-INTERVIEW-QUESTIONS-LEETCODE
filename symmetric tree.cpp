Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

 

Follow up: Solve it both recursively and iteratively.


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
    bool ans(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL && root2==NULL)
            return true;
        if(root1==NULL || root2==NULL)
            return false;
        bool res=(root1->val==root2->val)&& ans(root1->left,root2->right) && ans(root1->right,root2->left);
        return res;
    }
    bool isSymmetric(TreeNode* root) {
        return ans(root,root);
    }
};
