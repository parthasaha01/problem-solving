#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;
    cin>>n>>a>>b;

    if(a>b)swap(a,b);

    if((a<=(n/2)) && (b>(n/2)))
    {
        printf("Final!\n");
        return 0;
    }

    set<int>ss;

    for(int i=1; i<=n; i++){
        ss.insert(i);
    }

    set<int> :: iterator it,jt,kt;


    int ans = 0;
    while(ss.size() > 1)
    {
        ans++;
        for(it=ss.begin(); it!=ss.end(); )
        {
            jt = it;
            it++;
            kt = it;

            if((*jt==a && *kt==b) || (*jt==b && *kt==a))
            {
                printf("%d\n",ans);
                return 0;
            }

            if(*kt==a || *kt==b)
            {
                ++it;
                ss.erase(*jt);
            }
            else
            {
                it++;
                ss.erase(*kt);
            }
        }
    }

    return 0;
}
