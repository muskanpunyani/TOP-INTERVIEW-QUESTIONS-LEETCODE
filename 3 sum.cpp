

******************************************************
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v1;
       sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<3)
        {
            return v1;
        }
        for(int i=0;i<n-1;i++)
        {
            if(i!=0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
            if((nums[i]+nums[j]+nums[k])==0)
            {
                v1.push_back({nums[i],nums[j],nums[k]});
                j++;
                while(j<k && nums[j]==nums[j-1])
                {
                    j++;
                }
                
            }
            else if((nums[i]+nums[j]+nums[k])  < 0)
            {
                j++;
            }
            else if((nums[i]+nums[j]+nums[k]) > 0)
            {
                k--;
            }
                
            }
        }
      return v1;
        
    }
};
