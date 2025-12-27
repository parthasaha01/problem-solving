#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mx 100005
vector< pair<int,int> > vv;
int a[mx];
int main()
{
    int tt ; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        sort(a+1,a+n+1);

        int b = a[1];
        int e = a[1];

        vv.clear();

        for(int i=2; i<=n; i++)
        {
            if(a[i]-a[i-1]<=1){
                e = a[i];
            }
            else{
                vv.push_back(mp(b,e));
                b = a[i];
                e = a[i];
            }
        }
        vv.push_back(mp(b,e));

        int k = vv.size();
        printf("Set #%d:",ks);

        for(int i=0; i<k; i++)
        {
            int x = vv[i].first;
            int y = vv[i].second;

            if(i==k-1){
                if(x==y){
                    printf(" %d\n",x);
                }
                else{
                    printf(" %d-%d\n",x,y);
                }
            }
            else{
                if(x==y){
                    printf(" %d,",x);
                }
                else{
                    printf(" %d-%d,",x,y);
                }
            }

        }

        printf("\n");

    }

    return 0;
}
