#include <iostream>
using namespace std;

// A function to find number of distinct
// prime factors of a given number n
int totalPrimeFactors(int n)
{
    // To keep track of count
    int count = 0;

    // 2s that divide n
    if (!(n%2))
    {
        count++;
        while (!(n%2))
            n /= 2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i*i <= n; i = i+2)
    {
        // i divides n
        if (!(n%i))
        {
            count++;
            while (!(n%i))
                n /= i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2) count++;

    return count;
}

// C++ function to count number
// of pair with given GCD and LCM
int countPairs(int G, int L)
{
    if(L % G != 0) return 0;

    int div = L/G;

    // answer is 2^totalPrimeFactors(L/G)
    return (1 << totalPrimeFactors(div));
}

// Driver code to test above functions
int main()
{
    int G = 2, L = 12;
    cin>>G>>L;
    int ans =  countPairs(G, L);
    cout << ans << endl;
    return 0;
}
