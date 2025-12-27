#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool flag[20005];
ll a[20005],s[20005];
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n; scanf("%d",&n);

        for(int i=1; i<n; i++)scanf("%lld",&a[i]);

//        for(int i=1; i<n; i++)printf("%lld ",a[i]);
//        printf("\n");

        memset(flag,false,sizeof(flag));
        memset(s,0,sizeof(s));
        s[0]=0;
        flag[0]=true;
        ll maxx = 0;

        for(int i=1; i<n; i++){
            if(s[i-1]+a[i]<0){
                s[i]=0;
                flag[i]=true;
            }
            else{
                s[i]+=s[i-1]+a[i];
            }

            if(s[i]>=maxx){
                maxx = s[i];
            }
        }

//        for(int i=1; i<n; i++)printf("%lld ",s[i]);
//        printf("\n");

        if(maxx==0)
        {
            printf("Route %d has no nice parts\n",ks);
            continue;
        }

//        printf("maxx=%d\n",maxx);

        bool start = false;
        int x,y,d;
        int ax,ay,dd;
        dd=0;
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]==maxx && start==false)
            {
                start = true;
                y = i+1;
            }

            if(flag[i]==true && start==true){
                x = i+1;
                d = y-x+1;
                if(d>=dd){
                    ax=x;
                    ay=y;
                    dd=d;
                }
                start=false;
            }
        }

        printf("The nicest part of route %d is between stops %d and %d\n",ks,ax,ay);
    }

    return 0;
}

/*
4
10
1 2 3 -3 -4 100 -3 -10 10
17
4 -5 4 -4 4 4 -4 4 -10 4 -4 5 4 -4 4 -5

*/
