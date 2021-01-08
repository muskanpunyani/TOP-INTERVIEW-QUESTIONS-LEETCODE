Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:

Input: digits = ""
Output: []

Example 3:

Input: digits = "2"
Output: ["a","b","c"]

 

Constraints:

    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].


*********************************
class Solution {
public:
    string fn(char n)
    {
    
        if(n=='2')
         return "abc";
        else if(n=='3')
         return "def";
        else if(n=='4')
         return "ghi";
        else if(n=='5')
         return "jkl";
        else if(n=='6')
         return "mno";
        else if(n=='7')
         return "pqrs";
        else if(n=='8')
         return "tuv";
        else if(n=='9')
         return "wxyz";

        
        return "";
        
     
    }
    void soln(string res,int index,string digits,vector<string> &ans)
    {
        if(index>=digits.length()) // if length of string =input
        {
            ans.push_back(res);
            return;
        }
        string s1=fn(digits[index]);
        for(int i=0;i<s1.length();i++)
        {
            res.push_back(s1[i]);  // put char
            soln(res,index+1,digits,ans); // recurse
            res.pop_back();     // pop back
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
            return ans;
        soln("",0,digits,ans);   // res,index,input,ans
        return ans;
    }
};
