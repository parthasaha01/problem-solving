#include<bits/stdc++.h>
using namespace std;
int cnt[15];
int a[3][3]={{3,6,9},{1,4,7},{2,5,8}};
char ss[1005];
int fun(int n)
{
    int k=0;
    while(n!=0)
    {
        int r=n%3;
        bool flag=false;
        for(int i=0; i<3; i++)
        {
            int c=a[r][i];
            if(cnt[c]>0){
                n-=c;
                flag=true;
                cnt[c]--;
                break;
            }
        }
        if(flag==false){
            k=1-k;
            break;
        }

        int ct=0;
        for(int x=1; x<=9; x++){
            ct+=cnt[x];
        }
        if(ct<=0){
            break;
        }
        k=1-k;
    }

    return k;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        scanf("%s",ss);
        int sz=strlen(ss);
        sort(ss,ss+sz);
        memset(cnt,0,sizeof(cnt));
        int sum=0;

        for(int i=0; i<sz; i++){
            int c=ss[i]-'0';
            cnt[c]++;
            sum+=c;
        }

        int ans=fun(sum);

        if(ans==0){
            printf("Case %d: S\n",ks);
        }
        else{
            printf("Case %d: T\n",ks);
        }
    }

    return 0;
}
