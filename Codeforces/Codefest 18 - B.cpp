#include<bits/stdc++.h>
using namespace std;
#define mx 200005
#define ll long long int
int n,s,a[mx];
int Search(int v)
{
    int cnt = 0;
    int lo = 1;
    int hi = n;

    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(a[md]<=v){
            cnt = md;
            lo = md+1;
        }
        else{
            hi = md-1;
        }
    }

    return cnt;
}
int main()
{
    scanf("%d %d",&n,&s);
    int flag = 0;
    int cnt = 0;
    int kom = 0;
    int besi = 0;
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        if(a[i]==s){
            flag = 1;
            cnt++;
        }
        else if(a[i]<s){
            kom++;
        }
        else{
            besi++;
        }
    }

    sort(a+1,a+n+1);

    long long int ans = 0;

    int pos = (n/2)+1;
    int nn = n/2;

    if(kom>nn){
        int d = kom-nn;
        for(int i=nn+1; i<=kom; i++){
            ans += (ll)abs(s-a[i]);
        }

        printf("%I64d\n",ans);
    }
    else{
        if(cnt>0){
            if(kom+cnt>=pos){
                printf("%I64d\n",ans);
            }
            else{
                for(int i=kom+cnt+1; i<=pos; i++){
                    ans += (ll)abs(a[i]-s);
                }
                printf("%I64d\n",ans);
            }
        }
        else{
            if(kom+cnt>=pos){
                printf("%I64d\n",ans);
            }
            else{
                for(int i=kom+cnt+1; i<=pos; i++){
                    ans += (ll)abs(a[i]-s);
                }
                printf("%I64d\n",ans);
            }
        }
    }

    //main();

    return 0;
}
