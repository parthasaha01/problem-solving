#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define D double
#define pb push_back
#define mp make_pair
#define sf scanf
#define pf printf
#define ff first
#define ss second
#define sz 10005
#define sq(x) x*x
#define eps 1e-8
#define PI (2*acos(0.0))
#define mem(a, b) memset(a, b, sizeof a)
#define dist(x1, y1, x2, y2) sqrt(sq(x1-x2)+sq(y1-y2))
#define FastIO ios_base::sync_with_stdio(0)
const int inf = 0x7f7f7f7f;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n,m;
vector<int>vec[sz];
vector<int>gp;
int vis[sz];
int ans[sz];


void dfs(int x)
{
	vis[x] = 1 ;
	gp.push_back(x);
	for(int i=0; i<vec[x].size(); i++)
	{
		int v = vec[x][i];
		if(vis[v]==-1)
		dfs(v);
	}
}

void clr()
{
	for(int i=0; i<sz; i++)
	{
		vec[i].clear();
		ans[i] = 0 ;
		vis[i] = -1;
	}
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //FastIO;
		int t,cas = 1 ;
		sf("%d",&t);
		while(t--)
		{
			sf("%d%d",&n,&m);
			clr();
			int x,y;
			for(int i=0; i<m; i++)
			{
			sf("%d%d",&x,&y);
			vec[x].push_back(y);
			vec[y].push_back(x);
			}


			for(int i=1; i<=n; i++)
			{
				if(vis[i]==-1)
				{
						gp.clear();
						dfs(i);
						for(int j=0; j<gp.size(); j++)
						{
							int v = gp[j];
							ans[v] = gp.size()-1;
						}
				}
			}
			pf("Case #%d:\n",cas++);
			for(int i=1; i<=n; i++)
			{
				if(i==1)
				pf("%d",ans[i]);
				else
				pf(" %d",ans[i]);
			}
			pf("\n");
		}

   return 0;
}




