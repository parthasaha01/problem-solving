#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long int
vector<string>v;
string ss1,ss2,ss3,ss1r,ss2r,ss3r;
int c[mx];
string Reverse(string ss)
{
    string temp;
    int sz=ss.size();
    int j=0;
    for(int k=sz-1; k>=0; k--)
    {
        temp[j++]=ss[k];
    }

    return temp;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d",&c[i]);
        }
        getchar();

        char s[100005];
        for(int i=0; i<n; i++)
        {
            gets(s);
            //puts(s);
            v.push_back(s);
        }


        ll cost=0;
        int flag=0;
        for(int i=0; i<n-2; i++)
        {
            ss1=v[i];
            ss2=v[i+1];
            ll cost1=10000000005,cost2=1000000005;
            if(ss1>ss2)
            {
                ss1r=Reverse();
                ss2r=Reverse();

                if(ss1r<ss2){
                    cost1=c[i];
                }
                if(ss1<ss2r){
                    cost2=c[i];
                }

                if(cost<cos2){
                    ss
                }
            }
        }

        label:

        if(flag==-1)
        {
            printf("-1\n");
        }
        else
        {
            printf("%I64d\n",cost);
        }


        v.clear();
    }

    return 0;
}

