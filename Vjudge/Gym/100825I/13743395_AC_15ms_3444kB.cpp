#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
string gr[12],s;
map< pii, int>vv;
char ans[15][15];
int col[105],a[15][15],b[15][15],sz,n,flag,p;
void solve()
{
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(col[a[i][j]]==1){
                if(p>=sz){
                    flag = 0;
                    return;
                }
                ans[i][j] = s[p];
                p++;
            }
        }
    }

//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=n; j++){
//            printf("%c ",ans[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");

    for(int j=n,x=1; j>=1; j--,x++){
        for(int i=1,y=1; i<=n; i++,y++){
            b[i][j] = a[x][y];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            a[i][j] = b[i][j];
        }
    }

}
int main()
{
    cin>>n;


    for(int i=0; i<n; i++){
        cin>>gr[i];
    }

    cin>>s;
    sz = n*n;

    for(int i=1,k=0; i<=n; i++){
        for(int j=1; j<=n; j++){
            k++;
            vv[mp(i,j)] = k;
        }
    }

//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=n; j++){
//            printf("%d ",vv[mp(i,j)]);
//        }
//        printf("\n");
//    }

    int dot = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(gr[i][j]=='.'){
                //vis[i+1][j+1]=1;
                col[vv[mp(i+1,j+1)]]=1;
                dot++;
            }
        }
    }

    for(int i=0; i<=11; i++){
        for(int j=0; j<=11; j++){
            ans[i][j] = '#';
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            a[i][j] = vv[mp(i,j)];
        }
    }

    flag = 1;
    p = 0;
    for(int i=1,k=0; i<=4; i++){
        solve();
        if(flag==0)break;
    }

    if(flag==0){
        cout << "invalid grille" << endl;
        return 0;
    }

    string res;
    int valid = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(ans[i][j]=='#'){
                valid = 0;
                break;
            }
            else{
                res+=ans[i][j];
            }
        }
    }

    if(valid==0){
        cout << "invalid grille" << endl;
        return 0;
    }
    else{
        cout << res << endl;
    }
    return 0;
}
