Given a list of non-negative integers nums, arrange them such that they form the largest number.

Note: The result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"

Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"

Example 3:

Input: nums = [1]
Output: "1"

Example 4:

Input: nums = [10]
Output: "10"

 

Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 109



******************************
//time=0(nlogn) space=0(n)
bool comp(string a,string b)
{
    string a1=a.append(b);
    string a2=b.append(a);
    return a1>a2;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        bool all_zeros=true;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                all_zeros=false;
                break;
            }
        }
        if(all_zeros)
        {
            return "0";
        }
        vector<string> v;
        string ans;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back(to_string(nums[i]));
        }
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<v.size();i++)
        {
            ans+=v[i];
        }
        return ans;
        
    }
};
