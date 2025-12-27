#include<bits/stdc++.h>
using namespace std;
string ss;
vector<int>vv;
int main()
{
    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++)
    {
        cin>>ss;
        int sz = ss.size();

        vv.clear();

        vv.push_back(0);

        if(ss[0]=='?')vv.push_back(0);

        int cnt;
        if(ss[0]=='?')cnt=0;
        else cnt=1;

        for(int i=1; i<sz; i++)
        {
            if(ss[i]=='?')
            {
                if(cnt!=0)
                {
                    if(ss[i-1]=='0')cnt=(-1)*cnt;
                    vv.push_back(cnt);
                }

                vv.push_back(0);
                cnt=0;
            }
            else if(ss[i]==ss[i-1])
            {
                cnt++;
            }
            else
            {
                if(cnt!=0)
                {
                    if(ss[i-1]=='0')cnt=(-1)*cnt;
                    vv.push_back(cnt);
                }
                cnt=1;
            }
        }

        if(cnt!=0)
        {
            if(ss[sz-1]=='0')cnt=(-1)*cnt;
            vv.push_back(cnt);
        }
        vv.push_back(0);

//        for(int i=0; i<vv.size(); i++)
//        {
//            printf("%d ",vv[i]);
//        }
//        printf("\n");

        int vz = vv.size();
        int ans=1;

        for(int i=1; i<vz-1; i++)
        {
            if(vv[i]!=0)
            {
                ans = max(ans,abs(vv[i]));
                continue;
            }

            if(vv[i-1]<0 && vv[i+1]<0)
            {
                vv[i]=1;

            }
            else if(vv[i-1]>0 && vv[i+1]>0)
            {
                vv[i]=-1;
            }
            else if(vv[i-1]<0 && vv[i+1]>0)
            {
                if(abs(vv[i-1])<=abs(vv[i+1]))
                {
                    vv[i]=vv[i-1]-1;
                    vv[i-1]=vv[i-1]-1;
                }
                else
                {
                    vv[i]=vv[i+1]+1;
                    vv[i+1]=vv[i+1]+1;
                }
            }
            else if(vv[i-1]>0 && vv[i+1]<0)
            {
                if(abs(vv[i-1])<=abs(vv[i+1]))
                {
                    vv[i]=vv[i-1]+1;
                    vv[i-1]=vv[i-1]+1;
                }
                else
                {
                    vv[i]=vv[i+1]-1;
                    vv[i+1]=vv[i+1]-1;
                }
            }
            else if(vv[i-1]<0 && vv[i+1]==0)
            {
                vv[i]=1;
            }
            else if(vv[i-1]>0 && vv[i+1]==0)
            {
                vv[i]=-1;
            }

            ans = max(ans,abs(vv[i]));
        }

        cout << "Case " << ks << ": " << ans << endl;

    }
    return 0;
}
