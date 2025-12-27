#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#define max 22000
#define infinity 999999999
int status[max];
int dist[max];
int tst,n,m,s,t,wt;
struct st
{
	int v;
	unsigned int w;
};
class compare
{
	public:
	bool operator()(const st& v1,const st& v2)
	{
		return v1.w>v2.w;
	}
};
using namespace std;
priority_queue<st,vector<st>,compare> pq;
vector<st> adj[max];
void dijkstra()
{
	for(int i=0;i<n;i++)
	{
		dist[i]=infinity;
	}
	dist[s]=0;
	st s1={s,dist[s]};
	pq.push(s1);
	while(!pq.empty())
	{
		st cv=pq.top();
		pq.pop();
		//status[cv.v]=1;
		int size=adj[cv.v].size();
		for(int i=0;i<size;i++)
		{
			int u=adj[cv.v][i].v;
			int w=adj[cv.v][i].w;
			if(dist[u]>dist[cv.v]+w)
			{
				dist[u]=dist[cv.v]+w;
                st s1={u,dist[u]};
                pq.push(s1);

			}

		}
	}
}
int main()
{
    cin>>tst;int k=0;
    int v1,v2;
    while(tst--)
    {
    	 cin>>n>>m>>s>>t;
    	 //memset(status,0,sizeof(status));
    	 k++;
    	 for(int i=0;i<m;i++)
    	 {
    	 	cin>>v1>>v2>>wt;
    	 	st s1={v2,wt};
    	 	adj[v1].push_back(s1);
    	 	st s2={v1,wt};
    	 	adj[v2].push_back(s2);
    	 }
    	 dijkstra();
    	 int l=dist[t];
    	 if(dist[t]==infinity)
    	 {
    	 	cout<<"Case #"<<k<<": unreachable"<<"\n";

    	 }
    	 else
    	 {
    	    cout<<"Case #"<<k<<": "<<l<<"\n";
    	 }
    	 for(int i=0;i<n;i++)
    	 {
    	 	adj[i].clear();
    	 }
    }
    return 0;

}
