#include<bits/stdc++.h>
#define ll long long
#define mx 100005

using namespace std;

int ar[mx], br[mx];
vector<int> tree[mx*4];
int sum[mx*4];
int lazy[mx*4];
void MergeNode(int nd, int l,int r){
    tree[nd].clear();
    int n1 = (int)tree[l].size();
    int n2 = (int)tree[r].size();
    int i=0, j=0;
    while(i<n1 && j<n2){
        if(tree[l][i]<=tree[r][j]){
            tree[nd].push_back(tree[l][i]); i++;
        }else{
            tree[nd].push_back(tree[r][j]); j++;
        }
    }

    while(i<n1){
        tree[nd].push_back(tree[l][i]); i++;
    }
    while(j<n2){
        tree[nd].push_back(tree[r][j]); j++;
    }
}
void build(int node, int b, int e){
	tree[node].clear();
	if(b==e){
        if(ar[b]==br[b]) sum[node] = 1;
        else sum[node] = 0;
        lazy[node] = -1;
		tree[node].push_back(br[b]);
		return;
	}
	int lson = node<<1, rson = lson + 1, mid = (b + e)>>1;
	build(lson, b, mid);
	build(rson, mid+1, e);
	sum[node] = sum[lson] + sum[rson];
	lazy[node] = -1;
	MergeNode(node,lson,rson);
	//merge(tree[lson].begin(), tree[lson].end(), tree[rson].begin(), tree[rson].end(), back_inserter(tree[node]));
}

void pushDown(int node, int b, int e)
{
	int lson = node<<1, rson = lson + 1, mid = (b + e)>>1;
	if(lazy[node] == -1) return;
	if(b != e){
		lazy[lson] = lazy[node];
		lazy[rson] = lazy[node];
	}
	int x = upper_bound(tree[node].begin(), tree[node].end(), lazy[node]) - tree[node].begin();
	int y = lower_bound(tree[node].begin(), tree[node].end(), lazy[node]) - tree[node].begin();
	sum[node] = x - y;
	lazy[node] = -1;
}

void update(int node, int b, int e, int i, int j, int v){
	pushDown(node, b, e);
	if(j < b || e < i) return;
	if(i <= b && e <= j){
		lazy[node] = v;
		pushDown(node, b, e);
		return;
	}
	int lson = node<<1, rson = lson + 1, mid = (b + e)>>1;

	update(rson, mid+1, e, i, j, v);
	update(lson, b, mid, i, j, v);
	sum[node] = sum[lson] + sum[rson];
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n, q;
		scanf("%d %d", &n, &q);
		for(int i = 1; i<=n; i++) scanf("%d",&ar[i]);
		for(int i = 1; i<=n; i++) scanf("%d",&br[i]);

		build(1, 1, n);

		while(q--){
		    int pr = sum[1];
			int x, y, z;
			scanf("%d%d%d",&x,&y,&z);
			int l = x^pr, r = y^pr, c = z^pr;
			update(1, 1, n, l, r, c);
			printf("%d\n", sum[1]);
		}
	}
	return 0;
}


