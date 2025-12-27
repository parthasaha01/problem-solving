#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main()
{
    int a[105];
    int n;

    while(scanf("%d",&n)==1)
    {
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }
        int cnt=0;
        int pos=0;
        for(int i=0; i<n; i++){
            if(a[i]<0){
                cnt++;
            }

            if(cnt==3){
                int diff = i-pos;
                v.push_back(diff);
                pos=i;
                cnt=1;
            }
        }

        if(pos<n){
            int diff = n-pos;
            v.push_back(diff);
        }

        int sz = v.size();

        printf("%d\n",sz);

        for(int i=0; i<sz; i++){
            if(i<sz-1){
                printf("%d ",v[i]);
            }
            else{
                printf("%d\n",v[i]);
            }
        }

        v.clear();
    }

    return 0;
}
