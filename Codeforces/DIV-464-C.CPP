#include<bits/stdc++.h>
using namespace std;
int a[100005],sum[100005];
int main()
{
    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    int s,f; scanf("%d%d",&s,&f);

    sum[0]=0;


    for(int i=1; i<=n; i++){
        sum[i] = sum[i-1]+a[i];
    }

    int maxx = 0;
    int pos = 0;
    int d = f-s;

    for(int i=1; i<=n; i++)
    {
        if(i<=s)
        {
            int b = s-i+1;
            int e = b+d-1;
            int v = sum[e]-sum[b-1];
            if(v>maxx){
                maxx = v;
                pos = i;
            }
        }
        else if(i>=f)
        {
            int e = n-(i-f);
            int b = e-d+1;
            int v = sum[e]-sum[b-1];
            if(v>maxx){
                maxx = v;
                pos = i;
            }
        }
        else
        {
            int p = i-s;

            int b,e;
            e = n;
            b = n-p+1;
            int v = sum[e]-sum[b-1];

            b = 1;
            e = d-p;
            v += sum[e]-sum[b-1];

            if(v>maxx){
                maxx = v;
                pos = i;
            }

        }
    }

    //printf("%d %d\n",pos,maxx);
    printf("%d\n",pos);

    return 0;
}
