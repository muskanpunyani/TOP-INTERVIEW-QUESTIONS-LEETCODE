Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false


**********************************
class Solution {
public:
   // time=0(n2)
    bool answer(string s,unordered_set<string> &s1,unordered_map<string,bool> &dp)
    {
        int n=s.length();
        if(!n)
            return true;
        if(dp.find(s)!=dp.end())  // check if s in in dp map
        {
            return dp[s];
        }
        for(int i=0;i<n;i++)
        {
            if(s1.find(s.substr(0,i+1))!=s1.end())  // i.e substring till i is in set
            {
                if(answer(s.substr(i+1),s1,dp))    // if prev string was in word dict and remaining is also in set then true
                {
                    dp[s]=true;
                    return true;
                }
            }
        }
        dp[s]=false;
        return false;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string> s1;   // for word dict,using set as easier to search
        unordered_map <string,bool> dp;  // dp of string and its result(i.e true or false)
        for(int i=0;i<wordDict.size();i++)
        {
            s1.insert(wordDict[i]);
        }
        return answer(s,s1,dp);
        
    }
};
