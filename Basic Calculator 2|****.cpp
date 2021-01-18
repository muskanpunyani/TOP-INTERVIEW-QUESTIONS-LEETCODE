Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

 

Example 1:

Input: s = "3+2*2"
Output: 7

Example 2:

Input: s = " 3/2 "
Output: 1

Example 3:

Input: s = " 3+5 / 2 "
Output: 5

 

Constraints:

    1 <= s.length <= 3 * 105
    s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
    s represents a valid expression.
    All the integers in the expression are non-negative integers in the range [0, 231 - 1].
    The answer is guaranteed to fit in a 32-bit integer.



**************************************************
using stack=> time=0(n) space=0(n)
**************************************************
class Solution {
public:
    int calculate(string s) {
        // should apply bodmass rule 
        stack<int> st;
        int curr=0;
        char sign='+';
        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i]))   //if digit
            {
                curr=curr*10 +(s[i]-'0');
            }
            // if operator
            if((!isdigit(s[i]) && !isspace(s[i]))|| (i==s.length()-1) )
            { //i==s.length()-1 bcz if elem is last there will be no operator after that and thus we need to perform operation
                if(sign=='+')
                {
                    st.push(curr);
                }
                else if(sign=='-')
                {
                    st.push(-curr);
                }
                else{
                    if(sign=='*')
                    {
                        int top=st.top();
                        st.pop();
                        int num=top*curr;
                        st.push(num);
                    }
                    else {
                        int top=st.top();
                        st.pop();
                        int num=top/curr;
                        st.push(num);
                    }
                }
                curr=0;
                sign=s[i];
            }
        }
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};

****************************************************
without stack => space=0(1)

this is same as with stack,its just that in the stack soln for + and - all values are added , we can do it beforehand only
i.e we can take a top variable and add it directly to ans when '+' or '-' arrives

in case of mul and divide we only want top elemnt to be multiplied or divided with curr elemnt and we are storing top elem in top so no need of anything
at last we should add the top to final res
*****************************************************
class Solution {
public:
    int calculate(string s) {
        // should apply bodmass rule 
        stack<int> st;
        int curr=0;
        char sign='+';
        int top=0;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i]))   //if digit
            {
                curr=curr*10 +(s[i]-'0');
            }
            // if operator
            if((!isdigit(s[i]) && !isspace(s[i]))|| (i==s.length()-1) )
            { //i==s.length()-1 bcz if elem is last there will be no operator after that and thus we need to perform operation
                if(sign=='+')
                {
                    ans+=top;   //
                    top= curr;  //
                }
                else if(sign=='-')
                {
                    ans+=top;   //
                    top= -curr;  //
                }
                else{
                    if(sign=='*')
                    {
                        int num=top*curr;  //
                        top=num;           //
                    }
                    else {
                        int num=top/curr;  //
                         top=num;          //
                    }
                }
                curr=0;
                sign=s[i];
            }
        }
        ans+=top;   //
        return ans;
    }
};
