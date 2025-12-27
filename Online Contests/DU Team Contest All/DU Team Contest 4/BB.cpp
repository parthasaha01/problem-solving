#include<bits/stdc++.h>
using namespace std;
string ss[15];
string gm;

struct dt
{
    int wh[3];
    int bl[3];
    int ow[3];
    int ob[3];
}st[1005];
struct dd
{
    int vv;
    int id;
}cn[1005];
bool cmp(dd x, dd y)
{
    if(x.vv == y.vv)
        return x.id < y.id;

    return x.vv > y.vv;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        map<int,string>mp;
        queue<int>qq;

        for(int i=1; i<=n; i++){
            cin>>ss[i];
            mp[i]=ss[i];
            qq.push(i);
        }

        cin>>gm;
        int sz = gm.size();

        int tp;
        tp = qq.front();
        qq.pop();
        st[1].wh[1] = tp;
        st[1].ow[1] = tp;

        tp = qq.front();
        qq.pop();
        st[1].bl[1] = tp;
        st[1].ob[1] = tp;

        tp = qq.front();
        qq.pop();
        st[1].wh[2] = tp;
        st[1].ow[2] = tp;

        tp = qq.front();
        qq.pop();
        st[1].bl[2] = tp;
        st[1].ob[2] = tp;

        for(int k=0; k<sz; k++)
        {
            if(gm[k]=='W')
            {
                int tm;
                tm = st[k+1].wh[1];
                st[k+2].wh[1] = st[k+1].wh[2];
                st[k+2].wh[2] = tm;
                st[k+2].ow[1] = st[k+1].ow[1];
                st[k+2].ow[2] = st[k+1].ow[2];

                tm = qq.front();
                qq.pop();
                qq.push(st[k+1].bl[2]);
                st[k+2].bl[1] = tm;
                st[k+2].bl[2] = st[k+1].bl[1];
                st[k+2].ob[1] = st[k+2].bl[2];
                st[k+2].ob[2] = st[k+2].bl[1];
            }
            else
            {
                int tm;
                tm = st[k+1].bl[1];
                st[k+2].bl[1] = st[k+1].bl[2];
                st[k+2].bl[2] = tm;
                st[k+2].ob[1] = st[k+1].ob[1];
                st[k+2].ob[2] = st[k+1].ob[2];

                tm = qq.front();
                qq.pop();
                qq.push(st[k+1].wh[2]);
                st[k+2].wh[1] = tm;
                st[k+2].wh[2] = st[k+1].wh[1];
                st[k+2].ow[1] = st[k+2].wh[2];
                st[k+2].ow[2] = st[k+2].wh[1];
            }
        }

        cn[1].vv = 1;
        cn[1].id = 1;
        for(int k=1; k<sz; k++){
            if(gm[k]==gm[k-1]){
                cn[k+1].vv = cn[k].vv+1;
                cn[k+1].id = k+1;
            }
            else{
                cn[k+1].vv = 1;
                cn[k+1].id = k+1;
            }
        }

        sort(cn+1,cn+sz+1,cmp);

        int mx = cn[1].vv;
        queue<int>ans;

        for(int i=1; i<=sz; i++)
        {
            if(cn[i].vv<mx)break;

            int id = cn[i].id-mx+1;

            if(gm[id-1]=='W')
            {
                int id1 = st[id].ow[1];
                int id2 = st[id].ow[2];

                ans.push(id1);
                ans.push(id2);
            }
            else
            {
                int id1 = st[id].ob[1];
                int id2 = st[id].ob[2];

                ans.push(id1);
                ans.push(id2);
            }

        }

        while(!ans.empty())
        {
            int id1 = ans.front();
            ans.pop();
            int id2 = ans.front();
            ans.pop();

            cout << mp[id1] << " " << mp[id2] << endl;

        }

    }

    return 0;
}
