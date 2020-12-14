Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000

Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000

Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000

 

Constraints:

    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -106 <= nums1[i], nums2[i] <= 106


*****************************************************
class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //1) need to create a combined array first,then find median
        // o(n+m) space and o(n+m) time
        // where n and m are lengths of 2 arrays
        // this will be a brute force soln
        
        int n=nums1.size();
        int m=nums2.size();  // size of second
        if(m<n)              // if second arr is smaller, as we will perform binary search on smaller element
        {
            return findMedianSortedArrays(nums2,nums1);
        }
        int start=0;
        int end=n;
        while(start<=end)
        {
            int partx=(start+end)/2;  // find part
            int party=((m+n+1)/2) - partx;  // find part for y
            // finding partition for first arry ; nums1
            int aLeft= (partx==0)?INT_MIN: nums1[partx-1];  // a3
            int aRight= (partx==n)? INT_MAX: nums1[partx];  // a4
            // finding partition for second array; nums2
            int bLeft=(party==0)? INT_MIN: nums2[party-1];  // b5(b left)
            int bRight=(party==m)? INT_MAX: nums2[party];    // b6(b right)
            
            if(aLeft<=bRight && aRight>=bLeft)
            {
                if(((m+n)%2)==0)  // i.e even length
                {
                    double v1=max(aLeft,bLeft);
                    double v2=min(aRight,bRight);
                    return (double)((v1+v2)/2);
                }
                else{
                    return (double)max(aLeft,bLeft);
                }
            }
            else if(aLeft>bRight)  // a3>b6
            {
                end=partx-1;       // decrement end 
            }
            else {                 //bLeft> aRight  ; b5>a4
                start=partx+1;    // increment start
            }
        }
        return 0;
    }
};
