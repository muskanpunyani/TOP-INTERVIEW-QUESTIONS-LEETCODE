Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

    '.' Matches any single character.​​​​
    '*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:

Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

Example 5:

Input: s = "mississippi", p = "mis*is*p*."
Output: false

 

Constraints:

    0 <= s.length <= 20
    0 <= p.length <= 30
    s contains only lowercase English letters.
    p contains only lowercase English letters, '.', and '*'.
    It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.


*****************************************************
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        bool dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                dp[i][j]=false;
            }
        }
        dp[0][0]=true; // empty
        // fill first row
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]=='*' && dp[0][i-2]==true)  // as p is 0 indexed
            {
                dp[0][i]=true;
            }
        }
        // first col will be all false only bcz s will contain only char and char compared with null results in false
        for(int i=1;i<=n;i++) // for rest
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='.')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    if((j-2)>=0 &&(p[j-2]==s[i-1] || p[j-2]=='.')) // if char befre * matches with s
                    {
                        dp[i][j]=dp[i][j-2] || dp[i-1][j];
                    }
                    else if((j-2)>=0){
                        dp[i][j]=dp[i][j-2];
                    }
                }
            }
        }
        return dp[n][m];
      
    }
};
