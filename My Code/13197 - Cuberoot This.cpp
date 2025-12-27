#include<bits/stdc++.h>
using namespace std;
vector<int>vv;
int main()
{
    int a,p;

    while(scanf("%d%d",&a,&p)==2)
    {
        if(a>p)swap(a,p);

        vv.clear();

        for(int x=0; x<p; x++)
        {
            int nn = x*x*x;
            int rr = nn%p;

            if(rr==a)
            {
                vv.push_back(x);
            }
        }

        int sz = vv.size();

        if(sz==0)
        {
            printf("\n");
            continue;
        }

        for(int i=0; i<sz; i++)
        {
            if(i==sz-1)
            {
                printf("%d\n",vv[i]);
            }
            else
            {
                printf("%d ",vv[i]);
            }
        }

    }

    return 0;
}

