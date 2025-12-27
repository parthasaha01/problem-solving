#include <bits/stdc++.h>
using  namespace std;
#define ll long long
#define mx 100005
vector<int>adj[mx];
ll n, x, ans, value[mx], subTreeSum[mx];
int IsDeleted[mx], IsChildDeleted[mx], IsLeaf[mx];
ll dp[mx][2];
void dfs(int u,int p) {
	subTreeSum[u] = value[u];
	IsChildDeleted[u] = 0;
	IsLeaf[u] = 1;
	dp[u][1] = -x;
	dp[u][0] = value[u];

	for(int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i];
		if(v==p) continue;
		dfs(v,u);
		dp[u][0] += max(dp[v][0],dp[v][1]);
		IsLeaf[u] = 0;
		subTreeSum[u] += subTreeSum[v];
		IsChildDeleted[u] += IsChildDeleted[v];
	}





	if(IsChildDeleted[u]==0) {
	    if(subTreeSum[u]>= 0) {
	        IsDeleted[u] = 0;
	    }else{
	        if(-subTreeSum[u] >= x) {
	            IsDeleted[u] = 1;
	            IsChildDeleted[u] = 1;
	            subTreeSum[u] = 0;
	        }else{
	            IsDeleted[u] = 0;
	        }
	    }
	}else {
	    ll temp = IsChildDeleted[u]*x;
	    if(subTreeSum[u] >= 0) {
	        if(subTreeSum[u] <= temp){
	            IsDeleted[u] = 1;
	            IsChildDeleted[u] = 1;
	            subTreeSum[u] = 0;
	        }else {
	            IsDeleted[u] = 0;
	        }
	    }else {
	       IsDeleted[u] = 1;
	       IsChildDeleted[u] = 1;
	       subTreeSum[u] = 0;
	    }
	}

	/*if(subTreeSum[u]>= 0){
	    IsDeleted[u] = 0;
	}else{
	    if(IsChildDeleted[u]==0) {
	        if(-subTreeSum[u] >= x){
	            IsDeleted[u] = 1;
	            subTreeSum[u] = 0;
	            IsChildDeleted[u] = 1;
	        }else{
	            IsDeleted[u] = 0;
	        }
	    }
	    else {
	        IsDeleted[u] = 1;
	        subTreeSum[u] = 0;
	        IsChildDeleted[u] = 1;
	    }
	}*/

	/*if(subTreeSum[u]>= 0){
	    IsDeleted[u] = 0;
	}else if((-(subTreeSum[u])>0) && IsChildDeleted[u]){
	    IsDeleted[u] = 1;
	    subTreeSum[u] = 0;
	    IsChildDeleted[u] = 1;
	}else if((-(subTreeSum[u])>x) && (!IsChildDeleted[u])){
	    IsDeleted[u] = 1;
	    subTreeSum[u] = 0;
	    IsChildDeleted[u] = 1;
	}else{
	    IsDeleted[u] = 0;
	}*/

	/*dp[u][0] = -(subTreeSum[u] + x); // if we delete the node
	dp[u][1] = value[u]; // if we don't delete the node
	for(int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i];
		if(v==p) continue;
		dp[u][1] += max(dp[v][0], dp[v][1]);
	}*/
}
void solve(int u,int p) {
    if(IsDeleted[u]){
        ans -= x;
        return;
    }

	ans += value[u];
	for(int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i];
		if(v==p) continue;
		solve(v,u);

		/*if(dp[v][0]>dp[v][1]) {
			ans -= x;
		}else {
			solve(v,u);
		}*/
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt; cin>>tt;
	for(int ks=1; ks<=tt; ks++) {
		cin>>n>>x;

		for(int i=1; i<=n; i++) cin>>value[i];

		for(int i=1; i<n; i++) {
			int u,v; cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(1,0);

		ans = 0;

		solve(1,0);

		ans = max(ans,-x);

		ans = max(dp[1][0], dp[1][1]);

		cout<<ans<<'\n';

		for(int i=0; i<=n; i++) {
			adj[i].clear();
			value[i] = 0;
			subTreeSum[i] = 0;
			//dp[i][0] = dp[i][1] = 0;
			IsDeleted[i] = 0;
			IsChildDeleted[i] = 0;
		}
	}

	return 0;
}

/*
7
3 5
1 -5 -10
1 2
2 3
3 5
1 5 -10
1 2
2 3
3 7
1 5 -2
1 2
2 3
2 5
-1 -10
1 2
1 10
-10
1 10
-9
1 10
-11

*/

/*
3
1 10
-10
1 10
-9
1 10
-11
*/
