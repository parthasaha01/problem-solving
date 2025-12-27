#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int a[mx+5],last[mx+5],p[mx+5];
char s[mx+5];
int main()
{
    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }


    scanf("%s",s);
    //printf("%s\n",s);

    for(int i=1; i<n; i++)
    {
        p[i] = s[i-1]-'0';
    }

//    for(int i=1; i<n; i++)
//    {
//        printf("%d",p[i]);
//    }
//    printf("\n");

    //last[n] = n;
    int cur = n;
    int flag = 1;

    for(int i=n-1; i>=1; i--)
    {
        if(p[i]==0)cur=i;
        if(cur<a[i]){
            flag = 0;
            break;
        }
    }

    if(flag==0){
        printf("NO\n");
        return 0;
    }
    else{
        printf("YES\n");
        return 0;
    }

    return 0;

}
