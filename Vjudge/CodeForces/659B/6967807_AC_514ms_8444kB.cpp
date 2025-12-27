#include<bits/stdc++.h>
using namespace std;
struct dt
{
    string name;
    int mrk;
}st;
vector<dt>v[10005];
bool cmp(dt x, dt y)
{
    return x.mrk>y.mrk;
}
int main()
{
    int n,m;

    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0; i<=m; i++)
        {
            v[i].clear();
        }

        for(int i=0; i<n; i++)
        {
            string s;
            int r, ma;
            cin >> s >> r >> ma;
            dt man;
            man.name=s;
            man.mrk=ma;
            v[r].push_back(man);
        }

        for(int i=1; i<=m; i++)
        {
            sort(v[i].begin(),v[i].end(),cmp);
        }

        for(int i=1; i<=m; i++)
        {
            int sz=v[i].size();

            if(sz<=2)
            {
                dt man1,man2;
                man1=v[i][0];
                man2=v[i][1];

                cout << man1.name << " " << man2.name << endl;
            }
            else
            {
                dt man1, man2, man3;
                man1=v[i][0];
                man2=v[i][1];
                man3=v[i][2];

                if(man2.mrk==man3.mrk){
                    cout << '?' << endl;
                }
                else{
                    cout << man1.name << " " << man2.name << endl;
                }
            }
        }
    }

    return 0;
}
