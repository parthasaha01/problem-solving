#include<bits/stdc++.h>
using namespace std;
struct info
{
    int b,e;
}a[25];
bool cmp(info x, info y)
{
    if(x.e==y.e){
        return x.b < y.b;
    }
    else{
        return x.e < y.e;
    }
}
int main()
{
    int t,n,m;
    scanf("%d",&t);

    while(t--)
    {
        int k=0;
        while(scanf("%d%d",&n,&m))
        {
            if(n==0 && m==0){
                break;
            }
            a[k].b=n;
            a[k].e=m;
            k++;
        }

        sort(a,a+k,cmp);

        /*for(int i=0; i<k; i++){
            printf("%d %d\n",a[i].b,a[i].e);
        }*/

        int cnt=0;
        int pre=0;
        for(int i=0; i<k; i++){
            if(a[i].b>=pre){
                ++cnt;
                pre = a[i].e;
            }
        }

        printf("%d\n",cnt);
    }

    return 0;
}
