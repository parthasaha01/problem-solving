#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int q[mx],a[mx];
bool cmp(int x, int y){
    return x>y;
}
int main()
{
    int n,m;

    while(scanf("%d",&m)==1)
    {
        int minq = 100000000;
        for(int i=0; i<m; i++){
            scanf("%d",&q[i]);
            minq = min(minq,q[i]);
        }
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }

        //sort(q,q+m);
        sort(a,a+n,cmp);

        int cnt=0;
        int sum=0;

        for(int i=0; i<n; i++)
        {
            if(cnt==minq){
                cnt=0;
                i++;
            }
            else
            {
                sum+=a[i];
                cnt++;
            }
        }

        printf("%d\n",sum);
    }

    return 0;
}
