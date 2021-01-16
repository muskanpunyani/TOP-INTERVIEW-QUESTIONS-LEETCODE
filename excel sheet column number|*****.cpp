Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

Example 1:

Input: "A"
Output: 1

Example 2:

Input: "AB"
Output: 28

Example 3:

Input: "ZY"
Output: 701

 

Constraints:

    1 <= s.length <= 7
    s consists only of uppercase English letters.
    s is between "A" and "FXSHRXW".


*********************
class Solution {
public:
    //eg "zy"=26*26 + 25
    // "AB" = 26*1+2;
    //"ABC" = 1 (for a)
   // 1*26 +[2=b]    (for ab)
    //28*26+[3=c]    (for abc)
    // [[[[a]b]c]d]
    // starting=val, next=26*prev+val, next=26*prev+val
    // val is a=1,b=2,c=3.....
    int titleToNumber(string s) {
        int ans=0;         // initially 0
        for(int i=0;i<s.length();i++)
        {
            ans=(26*ans)+(s[i]-'A' + 1);  // +1 (bcz A-'A'=0 but val is 1)
        }
        return ans;
    }
};
