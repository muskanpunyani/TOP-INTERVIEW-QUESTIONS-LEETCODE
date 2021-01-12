Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:

Input: "race a car"
Output: false

 

Constraints:

    s consists only of printable ASCII characters.


*****************************************
class Solution {
public:
    bool isPalindrome(string s) {
        // NEED TO CONSIDER ONLY ALPHANUMERIC
        // we will use 2 pointers
        // pointer 1 for start and pointer 2 for end
        // time=0(n)
        //space=0(1)
        int l=0;
        int r=s.length()-1;
        int n=s.length();
        while(l<r)
        {
            while(l< r && !isalnum(s[l])) // means s[l] is not alpha numeric
            {
                l++;
            }
            while(l<r && !isalnum(s[r])) // means s[r] is not alpha numeric
            {
                r--;
            }
            if(tolower(s[l])!=tolower(s[r])) // if char doesnt match not palindrome
            {
                return false;
            }
            else{    // change l and r
                l++;
                r--;
            }
        }
        return true;
        
    }
};
