#include<bits/stdc++.h>
using namespace std;
#define mx 30005
stack<int>st;
int aa[2][mx];
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);

        for(int i=1; i<=n; i++)
            scanf("%d",&aa[1][i]);
        aa[1][n+1]=0;

//        for(int i=1; i<=rr; i++){
//            for(int j=1; j<=cc+1; j++){
//                printf("%d ",aa[i][j]);
//            }
//            printf("\n");
//        }

        int ans=0;

        for(int i=1; i<=1; i++)
        {
            int bg=1;
            for(int j=1; j<=n+1; j++)
            {
                int pp = aa[i][j];

                if(st.empty()){
                    if(pp)st.push(j);
                    else bg=j+1;
                }
                else{
                    if(pp>=aa[i][st.top()]){
                        st.push(j);
                    }
                    else{
                        int tp = st.top();
                        while(aa[i][tp]>pp){
                            st.pop();
                            int area;
                            if(st.empty()) area = aa[i][tp]*(j-bg);
                            else area = aa[i][tp]*(j-tp);

                            cout << " j=" << j << " bg=" << bg <<" aa=" << aa[i][tp] << " area=" << area << " - tp=" << tp;
                            printf(" sz = %d\n",st.size());
                            ans = max(ans,area);
                            if(st.empty())break;
                            tp = st.top();
                        }
                        if(pp)st.push(j);
                        if(pp==0)bg=j+1;
                    }
                }
            }
            while(!st.empty())st.pop();
        }

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}

/*
20
2 2 3 0 4 4 0 2 3 4 5 0 3 1 10 9 7 6 5 3

*/

