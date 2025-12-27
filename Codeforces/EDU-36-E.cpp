#include<bits/stdc++.h>
using namespace std;
map<int,int> tt;
int main()
{
    int n,q;
    int x,y,k;
    scanf("%d%d",&n,&q);
    int ans=n;
    tt[n]=1;
    for(int i=0; i<q; i++)
    {
        scanf("%d%d%d",&x,&y,&k);
        //auto it=tt.lower_bound(x);
        map<int, int>::iterator it;
        it=tt.lower_bound(x);

        while(it!=tt.end())
        {
            int l=it->second,r=it->first;
            if(y<l) break;
            int temp=min(r,y)-max(l,x)+1;
            ans-=temp;
            tt.erase(it++);
            if(r>y) tt[r]=y+1;
            if(l<x) tt[x-1]=l;
        }
        if(k==2)
        {
            tt[y]=x;
            ans+=y-x+1;
        }
        /*
        for(auto it:tt)
        {
        	cout<<it.first<<" "<<it.second<<endl;
        }
        */
        printf("%d\n",ans);
    }
    return 0;
}
