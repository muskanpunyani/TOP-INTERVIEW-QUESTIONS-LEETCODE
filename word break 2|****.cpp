Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]

Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]


*****************************
class Solution {
public:
//O(len(wordDict) ^ len(s / minWordLenInDict)), = time
unordered_set<string> dict;   //set to store the dictionary variable
unordered_map<string, vector<string>> dp;   // map dp ; word break 1 was having bool it is having vector<string>*

vector<string> helper(string s) {
    if(dp.find(s) != dp.end())     // if string s is in dp
    {
        return dp[s];
    }
    string prefix = "";
    vector<string> res;    // result vector
    for(int i = 0; i < s.length(); i++) {
        prefix += s[i];    // find every character
        
        if(dict.find(prefix) == dict.end())  // if the prefix is not found then move ahead
        {
            continue;
        }
        
        if(i != s.length()-1) {   // if prefix is found in set and i is not equal to length that is more substring can be found
            vector<string> suffixAnswer = helper(s.substr(i+1));   // recursion for remaining string
            for(string str:suffixAnswer)   //   for the strings in suffixanswer
            {
                res.push_back(prefix+" "+str);   // push the prefix and string
            }
        } else {   // if that was last string,push it directly
            res.push_back(prefix);
        }
    }                
    return dp[s] = res;   // dp[string]=res
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    for(string str: wordDict)
    {
        dict.insert(str);   //insert dictionary in set so that finding it becomes easier
    }
    return helper(s);    //find the ans
}
};
