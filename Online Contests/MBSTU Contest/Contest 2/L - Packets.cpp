#include<bits/stdc++.h>
using namespace std;
int a[7];
int cnt[7];
int main()
{
    int total,need,rem,div;
    while(1)
    {
        scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]);

        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]==0)
            break;

        memset(cnt,0,sizeof(cnt));
        total=0;
        total += a[6];
        total += a[5];
        cnt[1] += a[5]*11;
        total += a[4];
        cnt[2] += a[4]*5;
        total += (a[3]+3)/4;
        rem = a[3]%4;
        if(rem==1){
            cnt[2] += 5;
            cnt[1] += 7;
        }
        else if(rem==2){
            cnt[2] += 3;
            cnt[1] += 6;
        }
        else if(rem==3){
            cnt[2] += 1;
            cnt[1] += 5;
        }

        if(a[2]<=cnt[2])
        {
            cnt[1] += 4*(cnt[2]-a[2]);
        }
        else
        {
            need = a[2]-cnt[2];
            div = (need+8)/9;
            total += div;
            rem = need%9;
            if(rem!=0){
                cnt[1] += 4*(9-rem);
            }
        }

        if(a[1]>cnt[1])
        {
            need = a[1]-cnt[1];
            div = (need+35)/36;
            total += div;
        }

        printf("%d\n",total);
    }

    return 0;
}
