#include<bits/stdc++.h>
using namespace std;
typedef long long i64;

int Hash(string &s,int m,i64 b, i64 mod)
{
    i64 h=0, p=1;
    for(int i=m-1; i>=0; i--){
        h = h+s[i]*p;
        h %= mod;
        p = (b*p)%mod;
    }
    return h;
}
int Match(string &txt,string &pat)
{
    int n = txt.size();
    int m = pat.size();

    if(n<m || n==0 || m==0) return -1;

    i64 b = 347, mod = 1000000007;
    i64 pm = 1;
    for(int i=1; i<=m-1; i++) pm = (pm*b)%mod;

    i64 hsh_txt = Hash(txt,m,b,mod);
    i64 hsh_pat = Hash(pat,m,b,mod);

    if(hsh_txt == hsh_pat) return 0;

    for(int i=m; i<n; i++){
        hsh_txt = (hsh_txt - (pm*txt[i-m])%mod)%mod;
        hsh_txt = (hsh_txt+mod)%mod;
        hsh_txt = (hsh_txt*b)%mod;
        hsh_txt = (hsh_txt+txt[i])%mod;

        if(hsh_txt == hsh_pat) return i-m+1;
    }

    return -1;
}
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        string txt,pat;
        cin >> txt >> pat;

        int pos = Match(txt,pat);

        if(pos==-1) printf("Not found\n");
        else printf("Found at position %d\n",pos+1);
    }
    return 0;
}
