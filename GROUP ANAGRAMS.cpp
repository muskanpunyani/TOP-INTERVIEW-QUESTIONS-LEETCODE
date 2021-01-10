Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]

 

Constraints:

    1 <= strs.length <= 104
    0 <= strs[i].length <= 100
    strs[i] consists of lower-case English letters.


******************************************
class Solution {
public:
    /*
   //1]  create a map of string to vector<string>
    // this map will have key as sorted string and values as all its anagrams
    // time=0(nklogk) where n is the length of strs and k is max length of string in strs
    // space=0(nk)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++)
        {
            string s1=strs[i];
            sort(s1.begin(),s1.end());
            m[s1].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it=m.begin();it!=m.end();it++)
        {
            ans.push_back(it->second);
        }
        return ans;
        
    }
    */
    /*
    second soln is to use 2 maps
    1 map for storing the freq of strings and other to store strings as above
    time=0(nk)
    space=0(n+k)
    */
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
         map<map<char,int>,vector<string>> m; //1st map for freq
         // second map for strings
         
         for(int i=0;i<strs.size();i++)
         {
             string s1=strs[i];
             map<char,int> temp1; // for freq
             for(auto j:s1)
             {
                 temp1[j]++; // store freq
             }
             // now check whether these same freq strings for every char are present in original map
             auto it=m.find(temp1);
             vector<string> val;
             if(m.find(temp1)!=m.end()) // i.e present
             {
                 it->second.push_back(s1);
             }
             else{ // means not presnt in map,need to enter
                 val.push_back(s1);
                 m.insert({temp1,val});
             }
         }
          vector<vector<string>> ans;
        for(auto it=m.begin();it!=m.end();it++)
        {
            ans.push_back(it->second);
        }
        return ans;
     }
    
};
