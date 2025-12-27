#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int main()
{
    int n,t,k,d;

    while(scanf("%d%d%d%d",&n,&t,&k,&d)==4)
    {
        int ss=0;
        int cnt=0;
        while(cnt<n)
        {
            cnt+=k;
            ss += t;
        }

        if(ss<=d+t){
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }

//        int pp=0;
//        cnt=0;
//
//        while(cnt<n)
//        {
//            cnt+=k;
//            if(pp>d){
//                cnt+=k;
//            }
//            pp+=t;
//        }
//
//        if(ss<=pp){
//            printf("NO\n");
//        }
//        else
//        {
//            printf("YES\n");
//        }
    }

    return 0;
}
