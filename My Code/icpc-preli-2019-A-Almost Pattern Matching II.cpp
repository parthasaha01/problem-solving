#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define MX 1200007
#define base 13331
string s,p;
ull hashS[MX],hashP[MX],pw[MX];
int main()
{
    int t,k;
    pw[0]=1;
    for(int i=1; i<MX; i++)
        pw[i]=pw[i-1]*base;
    cin>>t;
    for(int cs=1; cs<=t; cs++)
    {
        cin>>s>>p>>k;
        memset(hashS,0,sizeof(hashS));
        memset(hashP,0,sizeof(hashP));
        int lS=s.size(),lP=p.size();
        s='@'+s;
        p='#'+p;
        for(int i=1; i<=lS; i++)
            hashS[i]=hashS[i-1]*base+s[i];
        for(int i=1; i<=lP; i++)
            hashP[i]=hashP[i-1]*base+p[i];
        ll cnt=0;
        for(int i=1; i<=lS; i++)
        {
            if(i+lP-1>lS)
                continue;
            int misMatch=0,lim=i+lP-1,prevL=i,L,R,mid,upvalid=-1;
            while(misMatch<=k && prevL<=lim)
            {
                L=prevL,R=lim,mid,upvalid=-1;
                bool flag=false;
                while(L<=R)
                {
                    mid=(L+R)/2;
                    ull LF=hashS[mid]-hashS[L-1]*pw[mid-L+1];
                    int m=L-i+1;
                    int n=mid-i+1;
                    ull RT=hashP[n]-hashP[m-1]*pw[n-m+1];
                    if(LF==RT)
                    {
                        L=mid+1;
                        upvalid=max(upvalid,mid);
                    }
                    else
                        R=mid-1;
                }
                if(upvalid!=-1)
                {
                    prevL=upvalid+1;
                }
                else
                {
                    misMatch++;
                    prevL=mid+1;
                }
            }
            if(misMatch<=k)
            {
                cnt++;
            }
        }
        printf("Case %d: %lld\n",cs,cnt);
    }
}
