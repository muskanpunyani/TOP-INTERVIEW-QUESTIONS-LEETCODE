Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

 

Constraints:

    0 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lower-case English letters.


******************************************************
time= 0(n)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0)
            return "";
        string prefix=strs[0];
        for(int i=1;i<n;i++)
        {
            if(strs[i].length()==0) {//This will optimize the code; code will work without these too
                prefix="";
            }
            
            int j=0;
            for(j=0;j<prefix.length()&& j<strs[i].length();j++) // checking prefix in strings
            {
                if(prefix[j]!=strs[i][j])  // if any char does not match,break at that point
                {
                    break;
                }
            }
           prefix= prefix.substr(0,j); // reduce prefix 
            
        }
        return prefix;
        
        
    }
};
