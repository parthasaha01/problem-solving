#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 31630
vector <int> primes;
bool check [MAX + 7], seg [100007];

void sieve()
{
    check [0] = check [1] = true;
    primes.push_back(2);

    for (ll i = 3; i <= 316; i += 2)
    {
        if (!check [i]){

            primes.push_back (i);

            for (ll j = i * i; j <= MAX; j += 2 * i)
                check [j] = true;
        }
    }

    for(int i=317; i<=MAX; i+=2)
    {
        if (!check [i])
            primes.push_back (i);
    }
}

void segmented_sieve (int a, int b)
{
    vector <int> p;

    if (a < 2) a = 2;
    if (a == 2) p.push_back (2);
    if (a % 2 == 0) a++;

    memset (seg, false,sizeof(seg));

    for (int i = 0; primes [i] * primes [i] <= b; i++)
    {
        int start = (a/primes[i])*primes[i];
        if(start<a) start += primes[i];
        if(start==primes[i]) start += primes[i];

        for (int j = start; j <= b; j += primes [i])
            seg [j - a] = true;
    }

    for (int i = a; i <= b; i++)
        if (!seg [i - a])
            p.push_back (i);

    int sz = p.size ();
    for (int i = 0; i < sz; i++)
        printf("%d\n",p[i]);
}

int main(){
    sieve ();
    int t,l,r; scanf ("%d", &t);
    for (int kase = 1; kase <= t; kase++)
    {
        if (kase > 1) printf("\n");
        scanf ("%d %d", &l, &r);
        segmented_sieve (l, r);
    }
    return 0;
}
