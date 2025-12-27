#include<bits/stdc++.h>
using namespace std;
vector<long long>vec;
long long sz = 32000;
bool flag[32005];
void prime()
{
    for(long long i=2; i<=sz; i++)
    {
        if(flag[i]==0)
        {
            vec.push_back(i);
            for(long long j = i*i; j<=sz; j+=i)
            {
               flag[j] = 1;
            }
        }
    }
}
int main()
{
    prime();
    long long n;
    while(scanf("%lld",&n)==1)
    {
        int chk = 0;
        while(1)
        {
            chk = 0;
            long long sq = sqrt(n);
            for(long long i=0; i<vec.size() && vec[i]<=sq; i++)
            {
                if(n%vec[i]==0)
                {
                    chk = 1;
                    break;
                }
            }
            if(chk==0)
                break;
            n--;
        }
        cout<<n<<endl;
    }
}
