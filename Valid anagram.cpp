Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

******************************
class Solution {
public:
    bool isAnagram(string s, string t) {
        // 1] sort both and if same then anagram
        // 2] same characters in both with freq using map or array
        // 3] If we use count array it will be more efficient as complexity will be constant 0(26)
        vector<int> count(26,0);
        if(s.length()!=t.length())
            return false;
        for(int i=0;i<s.length();i++)
        {
            count[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++)
        {
            count[t[i]-'a']--;
            if(count[t[i]-'a']<0)
                return false;
        }
        return true;
        
    }
};
