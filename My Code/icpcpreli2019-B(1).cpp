#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef tree<
pair<int,int>,
null_type,
less< pair<int, int> >,
rb_tree_tag,
tree_order_statistics_node_update>
indexed_multiset;

indexed_multiset OS[100005];
int par[100005];

int _find(int u)
{
    if(par[u]==u)
        return u;
    return par[u] = _find(par[u]);
}

void Make(int a, int t, int c){
    int u = _find(a);
    OS[u].insert(make_pair(t,c));
}

void _union(int a, int b)
{
    int x = _find(a);
    int y = _find(b);
    if(x!=y)
    {
        if((int)OS[x].size()>OS[y].size())
        {
            par[y] = x;
            for(auto ii : OS[y]){
                OS[x].insert(ii);
            }
            OS[y].clear();
        }
        else
        {
            par[x] = y;
            for(auto ii : OS[x]){
                OS[y].insert(ii);
            }
            OS[x].clear();
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        int n,q;
        scanf("%d",&n);
        scanf("%d",&q);
        for(int i = 1; i <= n; i++) {
            par[i] = i;
            OS[i].clear();
        }

        printf("Case %d:\n",t);

        for(int i = 1; i <= q; i++)
        {
            int x; scanf("%d",&x);
            if(x==0)
            {
                int L,R;
                scanf("%d",&L);
                scanf("%d",&R);
                _union(L,R);
            }
            else if(x==1)
            {
                int L,R;
                scanf("%d",&L);
                scanf("%d",&R);
                Make(L,R,i);
            }
            else if(x==2)
            {
                int U,L,R;
                scanf("%d",&U);
                scanf("%d",&L);
                scanf("%d",&R);
                int a = _find(U);
                int b = OS[a].order_of_key(make_pair(L,-1));
                int c = OS[a].order_of_key(make_pair(R,q+1));
                printf("%d\n",c - b);
            }
        }
    }
    return 0;
}
