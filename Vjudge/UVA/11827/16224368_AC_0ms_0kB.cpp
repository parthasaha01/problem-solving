#include<stdio.h>
#include<string.h>
char s[100005];
int a[100005], n;
void StringToArray(){
    int sz = strlen(s);
    n = 0;
    int val = 0;
    for(int i=0; i<sz; i++){
        if(s[i]==' '){
            if(val>0) a[++n] = val;
            val = 0;

        }else{
            val = (val*10) + (s[i]-'0');
        }
    }
    if(val>0) a[++n] = val;

//    for(int i=1; i<=n; i++){
//        printf("%d ",a[i]);
//    }
//    printf("\n");
}
int gcd(int x, int y){
    while(y!=0){
        int r = x%y;
        x = y;
        y = r;
    }
    return x;
}
int solve(){
    int maxx = 0;
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            int g = gcd(a[i], a[j]);
            if(g>maxx) maxx = g;
        }
    }
    return maxx;
}
int main(){
    int tt; scanf("%d",&tt);
    getchar();
    while(tt--){
        gets(s);
        StringToArray();
        int ans = solve();
        printf("%d\n",ans);
    }
    return 0;
}
