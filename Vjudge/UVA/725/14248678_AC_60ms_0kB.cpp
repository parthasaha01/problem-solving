#include<bits/stdc++.h>
using namespace std;
#define pss pair<string,string>
vector<int>vv;
vector< pair<string,string> > ans;
int a[15];
int duplicate(int u)
{
    memset(a,0,sizeof(a));

    while(u!=0)
    {
        int r = (u%10);
        if(a[r]>0)return 1;
        a[r]++;
        u /= 10;
    }
    return 0;
}
int iszero(int u)
{
    while(u!=0)
    {
        int r = (u%10);
        if(r==0)return 1;
        u /= 10;
    }
    return 0;
}
int conflict(int u,int v)
{
    memset(a,0,sizeof(a));
    while(u!=0)
    {
        int r = (u%10);
        if(a[r]>0)return 1;
        a[r]++;
        u /= 10;
    }
    while(v!=0)
    {
        int r = (v%10);
        if(a[r]>0)return 1;
        a[r]++;
        v /= 10;
    }
    return 0;
}
string inttostring(int u)
{
    string s;
    while(u!=0)
    {
        int r = (u%10);
        s += r+'0';
        u /= 10;
    }
    if(s.size()<5)s+='0';
    reverse(s.begin(),s.end());
    return s;
}
void fun(int n)
{
    for(int u=n; u<=99999; u+=n)
    {
        int nodu = floor(log10(u))+1;
        if(nodu<4)continue;
        if(duplicate(u))continue;
        if(nodu==4){
            if(iszero(u))continue;
            int v = u/n;
            int nodv = floor(log10(v))+1;
            if(nodv<5)continue;
            if(iszero(v))continue;
            if(duplicate(v))continue;
            if(conflict(u,v))continue;
            string s1 = inttostring(u);
            string s2 = inttostring(v);
            //cout << s1 << " " << s2 << endl;
            getchar();
            ans.push_back(make_pair(s1,s2));
        }
        else{
            int v = u/n;
            int nodv = floor(log10(v))+1;
            if(nodv<4)continue;
            if(nodv==4){
                if(iszero(u))continue;
                if(iszero(v))continue;
                if(duplicate(v))continue;
                if(conflict(u,v))continue;
                string s1 = inttostring(u);
                string s2 = inttostring(v);
                ans.push_back(make_pair(s1,s2));
            }
            else{
                if(duplicate(v))continue;
                if(conflict(u,v))continue;
                string s1 = inttostring(u);
                string s2 = inttostring(v);
                ans.push_back(make_pair(s1,s2));
            }
        }
    }
}
int main()
{
    int n,f=0;
    while(scanf("%d",&n))
    {
        if(n==0)break;

        if(f)printf("\n"); f=1;

        vv.clear();
        ans.clear();
        fun(n);

        int k = ans.size();
        if(k==0)printf("There are no solutions for %d.\n",n);
        else{
            //sort(ans.begin(),ans.end());
            for(int i=0; i<k; i++){
                string s1 = ans[i].first;
                string s2 = ans[i].second;
                cout << s1 << " / " << s2 << " = " << n << endl;
            }
        }
    }
    return 0;
}
