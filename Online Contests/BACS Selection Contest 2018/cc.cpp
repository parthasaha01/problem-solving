#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ans[100005];
int Find(int n)
{
    int bit=0;
    while(n!=0) {
        bit++;
        n >>= 1;
    }
    return bit;
}
 int solvexx(int n)
{
    int msb = Find(n);
    int vv = (1<<(msb-1));
    int ans = (n^vv);
    ans <<= 1;
    ans |= 1;
    return ans;
}

int main()
{
    for(int i=1; i<=100002; i++){
        ans[i] = solvexx(i);
    }
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int x,l,n; scanf("%d%d%d",&x,&l,&n);

        int cnt = 0;
        if(x>l)cnt+=x-l;
        int tot = n-l+1;
        for(int i=l; i<=n; i++){
            if(ans[i]==x)cnt++;
        }

        int gcd = __gcd(cnt,tot);
        int lob = cnt/gcd;
        int hor = tot/gcd;
        printf("Case %d: %d/%d\n",ks,lob,hor);
    }
    return 0;
}
/*

49 35
81 35
145 35
273 35
529 35
1041 35
2065 35
4113 35
8209 35
16401 35
32785 35
65553 35

*/
