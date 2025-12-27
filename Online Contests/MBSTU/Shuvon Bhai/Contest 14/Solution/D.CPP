#include <iostream>
using namespace std;
int power[1005];
int deg[1005];
int mas[1005][10005];
int n,m;
int answers[1006];
void input()
{
    cin>>n>>m;

    int v=1<<n;

    cout << v << endl;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        mas[a][power[a]++] = b;
        deg[b]++;
    }
    for(int i=0;i<n;i++)
        cin>>answers[i];
}
void solve()
{
    for(int i=0;i<n;i++)
    {
        if (deg[answers[i]]>0)
        {
            cout<<"NO";
            return;
        }
        for(int j=0; j<power[answers[i]]; j++)
            deg[mas[answers[i]][j]]--;
    }
    cout<<"YES";
}
int main()
{
    input();
    solve();
    return 0;
}
