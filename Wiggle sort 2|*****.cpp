 *****************************************************************
 soln 1=> average 0(n) time
 // hard to understand
 ********************************************************************
 
 void wiggleSort(vector<int>& nums) {
      if (nums.empty()) {
			return;
		}    
		int n = nums.size();
		
		// Step 1: Find the median    		
		vector<int>::iterator nth = next(nums.begin(), n / 2);
		nth_element(nums.begin(), nth, nums.end());
		int median = *nth;

		// Step 2: Tripartie partition within O(n)-time & O(1)-space.    		
		auto m = [n](int idx) { return (2 * idx + 1) % (n | 1); };    		
		int first = 0, mid = 0, last = n - 1;
		while (mid <= last) {
			if (nums[m(mid)] > median) {
				swap(nums[m(first)], nums[m(mid)]);
				++first;
				++mid;
			}
			else if (nums[m(mid)] < median) {
				swap(nums[m(mid)], nums[m(last)]);
				--last;
			}				
			else {
				++mid;
			}
		}
    }
};

********************************************
SOLUTION 2 |EASY

Sort and then write the smaller half of the numbers on the even indexes and the larger half of the numbers on the odd indexes, both from the back. Example:

Small half:    4 . 3 . 2 . 1 . 0 .
Large half:    . 9 . 8 . 7 . 6 . 5
----------------------------------
Together:      4 9 3 8 2 7 1 6 0 5

So write nums from the back, interweaving sorted[0..4] (indexed by j) and sorted[5..9] (indexed by k).

time=0(nlogn)
space=0(n)
********************************************
class Solution {
public:
    // time=0(nlogn)
    // space=0(n)
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int> sortednums=nums;
        sort(sortednums.begin(),sortednums.end());
        int mid=(n+1)/2;
        int front=0;
        int i=n-1;
        while(i>=0)
        {
            if((i%2)==0){ // even index
                nums[i]=sortednums[front];
                front++;
            }
            else{
                //odd index
                nums[i]=sortednums[mid];
                mid++;
            }
        i--;    
        }
        
    }
};
