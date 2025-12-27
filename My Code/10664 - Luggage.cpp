#include<bits/stdc++.h>
using namespace std;
int n,a[22];
bool vs[22][4005],ans;
string ss;
void fun(int p,int v)
{
    if(ans==true)return;
    if(v==0){ ans=true;return; }
    if(p>n)return;

    if(vs[p][v]==true)return;
    vs[p][v]=true;

    if(v-a[p]>=0)fun(p+1,v-a[p]);
    fun(p+1,v);
}
int main()
{
    int tt; scanf("%d",&tt);
    getchar();
    for(int ks=1; ks<=tt; ks++)
    {
        getline(cin,ss);

        stringstream cc(ss);
        int sum=0,x;
        n=0;
        while(cc>>x)
        {
            a[++n]=x;
            sum+=x;
        }

        if(sum&1){
            printf("NO\n");
            continue;
        }

        int v = sum/2;
        ans = false;

        memset(vs,false,sizeof(vs));
        fun(1,v);

        if(ans)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


