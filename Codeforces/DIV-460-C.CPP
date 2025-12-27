#include<bits/stdc++.h>
using namespace std;
string s[2005];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;



    for(int i=0; i<n; i++)
    {
        cin>>s[i];
    }

    int cnt = 0;
    int tot = 0;

    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=0; j<m; j++)
        {
            if(s[i][j]=='.'){
                sum++;
                tot++;
                if(sum==k){
                    sum--;
                    cnt++;
                }
            }
            else{
                sum = 0;
            }

        }
    }

    if(k==1){
        //printf("%d\n",tot);
        cout << tot << endl;
        return 0;
    }

    for(int j=0; j<m; j++)
    {
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i][j]=='.'){
                sum++;
                if(sum==k){
                    sum--;
                    cnt++;
                }
            }
            else{
                sum = 0;
            }
        }
    }

    //printf("%d\n",cnt);
    cout << cnt << endl;

    //main();

    return 0;

}
