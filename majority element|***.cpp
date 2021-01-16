Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

 

Constraints:

    n == nums.length
    1 <= n <= 5 * 104
    -231 <= nums[i] <= 231 - 1

 
Follow-up: Could you solve the problem in linear time and in O(1) space?
************************************
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // in 0(n) space we can create a map and check majority elemnt
        // now we want 0(1) space and O(n) time
        /*
        1] for this we have boyer-moore voting algorithm
        2] what this algo say is we will take the first element as majority
        and if we see that elemnt again count++
        and if we see any other elemnt count--
        3] when count reaches 0 , forget what u were doing and take the first elemt ater that as majority and repeat the process
        eg 
        [7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 7, 7, 7, 7]

Here, the 7 at index 0 is selected to be the first candidate for majority element. count will eventually reach 0 after index 5 is processed, so the 5 at index 6 will be the next candidate. In this case, 7 is the true majority element, so by disregarding this prefix, we are ignoring an equal number of majority and minority elements - therefore, 7 will still be the majority element in the suffix formed by throwing away the first prefix.

[7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 5, 5, 5, 5]

Now, the majority element is 5 (we changed the last run of the array from 7s to 5s), but our first candidate is still 7. In this case, our candidate is not the true majority element, but we still cannot discard more majority elements than minority elements (this would imply that count could reach -1 before we reassign candidate, which is obviously false).

Therefore, given that it is impossible (in both cases) to discard more majority elements than minority elements, we are safe in discarding the prefix and attempting to recursively solve the majority element problem for the suffix. Eventually, a suffix will be found for which count does not hit 0, and the majority element of that suffix will necessarily be the same as the majority element of the overall array.
        */
        int majority;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)         // for count=0 majority is changed
                majority=nums[i];
            
            count+=(nums[i]==majority ? 1:-1); // if same as majority +1,else -1
        }
        return majority;
    }
};
