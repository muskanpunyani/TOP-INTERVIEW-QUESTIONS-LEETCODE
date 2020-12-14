Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

Example 3:

Input: s = "a"
Output: "a"

Example 4:

Input: s = "ac"
Output: "a"

 

Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters (lower-case and/or upper-case),


****************************************
class Solution {
public:
    string longestPalindrome(string s) {
        // time=0(n2) ; space=0(1)
        // even= i,i-1
        // odd= i+1,i-1
        int n=s.length();
        int max_length=1;
        int low,high;
        int start=0;
        string ans;
        for(int i=1;i<n;i++)  
        {
            low=i-1;       // even palindromes
            high=i;
            while(low>=0 && high<n  && (s[low]==s[high]))
            {
                    int len=high-low+1;
                    if(len>max_length)
                    {
                        start=low;
                        max_length=len;
                    }
                
                low--;
                high++;
            }
            low=i-1;
            high=i+1;  // for odd palindromes
            while(low>=0 && high<n  && (s[low]==s[high]))
            {
                int len=high-low+1;
                if(len>max_length)
                {
                    start=low;
                    max_length=len;
                }
                low--;
                high++;
             }
        }
        
        int end=start+max_length;
        for(int i=start;i<end;i++)  // push the greatest length palindrome in answer
        {
            ans.push_back(s[i]);
            
        }
        return ans;
    }
};
