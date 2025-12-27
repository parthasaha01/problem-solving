#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; scan("%d",&n);

    for(int i=1; i<n; i++){
        int u,v; scanf("%d%d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }



}
