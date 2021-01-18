Count the number of prime numbers less than a non-negative number, n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:

Input: n = 0
Output: 0

Example 3:

Input: n = 1
Output: 0

 

Constraints:

    0 <= n <= 5 * 106



*********************
class Solution {
public:
    int countPrimes(int n) {
        // using sieve of eranthosis, time=0(nlog log n), space=0(n)
        if(n==0)
            return 0;
        vector<bool> v(n,true);
        v[0]=false;
        v[1]=false;
        for(int i=2;i<sqrt(n);i++)
        {
            if(v[i]==true)
            {
                for(int j=i*i;j<n;j+=i)
                {
                    v[j]=false;
                }
            }
        }
        int c=0;
        // calculating no of primes with val true
        for(int i=0;i<n;i++)
        {
            if(v[i]==true)
                c++;
        }
        return c;
    }
};
