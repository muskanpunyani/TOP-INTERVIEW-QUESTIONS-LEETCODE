Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]

 

Constraints:

    1 <= n <= 8


****************************
class Solution {
public:
// time=exponential
    void findparen(vector<string> &ans,int open,int close,string res)
    {
        if(open==0 && close==0) // both closing and opening end
        {
            ans.push_back(res);
            return;
        }
        if(open>0) 
        {
            findparen(ans,open-1,close,res+"("); // take open
        }
        if(close>open) // take close
        {
            findparen(ans,open,close-1,res+")"); // close can be taken only if it is greater than open else open needs to be taken first
        }
    }
    vector<string> generateParenthesis(int n) {
        // open means '('
        // close means ')'
        vector<string> ans;
        findparen(ans,n,n,"");
        return ans;
    }
};
