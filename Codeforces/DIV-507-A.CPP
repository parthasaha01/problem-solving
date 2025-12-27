#include<bits/stdc++.h>
using namespace std;
int n,a,b,c[105];
int fun()
{
    int minn = min(a,b);
    int cost = 0;
    for(int i=1,j=n; i<=j; i++,j--)
    {
        if(i==j){
            if(c[i]==2){
                cost += minn;
            }
        }
        else{
            if(c[i]==2&&c[j]==2){
                cost += 2*minn;
            }
            else if(c[i]==2||c[j]==2){
                if(c[i]==2){
                    if(c[j]==0){
                        cost += a;
                    }
                    else{
                        cost += b;
                    }
                }
                else{
                    if(c[i]==0){
                        cost += a;
                    }
                    else{
                        cost += b;
                    }
                }
            }
            else if(c[i]!=c[j]){
                return -1;
            }
        }
    }

    return cost;
}
int main()
{
    cin>>n>>a>>b;
    for(int i=1; i<=n; i++){
        cin>>c[i];
    }

    cout << fun() << endl;

    //main();

    return 0;
}

/*

13 10 5
1 2 1 0 2 2 2 2 2 0 1 0 2
12 10 5
1 2 1 0 2 2 2 2 0 1 0 2
*/
