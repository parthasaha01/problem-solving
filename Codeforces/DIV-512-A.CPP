#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int main(){
    //int n;
    int f = 0;
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++){
        int x; scanf("%d",&x);
        if(x==1){
            f = 1;
        }
    }

    if(f){
        printf("HARD\n");
    }
    else{
        printf("EASY\n");
    }

    return 0;
}
