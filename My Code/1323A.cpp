#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main() {
	int tt; scanf("%d",&tt);
	
	for(int kase=1; kase<=tt; kase++){
		int n; scanf("%d",&n);
		for(int i=1; i<=n; i++){
			scanf("%d",&a[i]);
		}
		
		if(n==1){
			if(a[1]%2==0){
				printf("1\n1\n");
			}
			printf("-1\n");
		}else{
			if(a[1]%2==0){
				printf("1\n1\n");
			}else if(a[2]%2==0) {
				printf("1\n2\n");
			}else{
				printf("2\n1 2\n");
			}
		}			
	}
	return 0;
}
