raction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:

Input: numerator = 2, denominator = 1
Output: "2"

Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"

Example 4:

Input: numerator = 4, denominator = 333
Output: "0.(012)"

Example 5:

Input: numerator = 1, denominator = 5
Output: "0.2"

 

Constraints:

    -231 <= numerator, denominator <= 231 - 1
    denominator != 0

***************************
class Solution {
public:
    // The time com should be O (denominator), cause the mod must be less than denominator. so you can run from 1 to mod times
    string fractionToDecimal(int numerator, int denominator) {
       if(numerator==0)
           return "0";
        string ans;
        if((numerator>0 && denominator<0) || (numerator<0 && denominator>0))
        {
            ans+="-"; // for -ve ans
        }
        long n=abs(numerator);
        long d=abs(denominator);
        long r=n%d;
        long q=n/d;
        ans+=to_string(q);  // add quotient to ans
        if(r==0)  // if we got 0 remainder
        {
            return ans;  // stop and return ans
        }
        //else rem is not 0
        ans+=".";  // decimal
        unordered_map<long,int> m; // map of remainder and place where this rem started
        while(r!=0)
        {
            if(m.find(r)!=m.end()) // rem is already in map,i.e repeated
            {
                ans.insert(m[r],"(");  //inserting opening at position of repeat
              //  ans+=to_string(r);
                ans+=")";               // put this at ending and break
                break;
            }
            // rem not in map
            m[r]=ans.size(); // remember the first position where remainder is seen
            r=r*10;
            q=r/d;
            r=r%d;
            ans+=to_string(q);
            
        }
        return ans;
    }
};
