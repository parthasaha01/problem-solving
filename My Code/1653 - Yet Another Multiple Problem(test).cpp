#include<bits/stdc++.h>
using namespace std;
int fr[15];
vector<int>a;
int n,m;
int dp[105][10005][2];
string s;
int fun(int p,int v,int f,int cc,string ss)
{

    cout << "ha = " << ss << " " << p << " " << v << " " << f << " " << cc << endl;

    if(v==0 && p>0 && f){
        cout << ss << " " << p << " " << v << " " << f << endl;
        return 0;
    }
    if(p==100)return 100000;
    if(dp[p][v][f]!=-1)return dp[p][v][f];

    int ret = 100000;
    for(int i=0; i<a.size(); i++){
        string xx = ss;
        xx += a[i]+'0';
        ret = min(ret,1+fun(p+1,((v*10)+a[i])%n,f|(a[i]>0),0,xx));
    }
    return dp[p][v][f] = ret;
}
void path(int p,int v,int f,string ss)
{
    cout << ss << " " << p << " " << v << " " << f << endl;

    if(v==0 && p>1 && f)return;
    if(p==100)return;



    int ret = fun(p,v,f,1,"");

    cout << "ret = " << ret << endl;

    for(int i=0; i<a.size(); i++){
        cout << "partha " << (f|(a[i]>0)) << endl;
        int ff = 1+fun(p+1,((v*10)+a[i])%n,f|(a[i]>0),1,"");
        cout << "f=" << f << "a[i]=" << a[i] << endl;
        if(ff==ret){
            string xx = ss;
            xx += a[i]+'0';
            if(f==1 || (a[i]>0))s += a[i]+'0';
            cout << "fgggd partha" << endl;
            path(p+1,((v*10)+a[i])%n,f|(a[i]>0),xx);
            break;
        }
    }

}
int main()
{
    int ks=0;
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(fr,0,sizeof(fr));
        for(int i=1; i<=m; i++){
            int x; scanf("%d",&x);
            fr[x] = 1;
        }

        a.clear();
        for(int i=0; i<10; i++){
            if(fr[i]==0)a.push_back(i);
        }

        for(int i=0; i<a.size(); i++){
            printf("%d ",a[i]);
        }
        printf("\n");

        memset(dp,-1,sizeof(dp));
        int f = fun(0,0,0,0,"");
        cout << "f=" << f << endl;
        s="";

        if(f<100000){
            path(0,0,0,"");
            printf("Case %d: ",++ks);
            cout << s << endl;
        }
        else{
            printf("Case %d: -1\n",++ks);
        }
    }
    return 0;
}

