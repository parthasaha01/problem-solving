#include<bits/stdc++.h>
using namespace std;
int M[370],F[370];
int main()
{
    int n;

    while(cin>>n)
    {
        memset(M,0,sizeof(M));
        memset(F,0,sizeof(F));

        for(int i=1; i<=n; i++)
        {
            char ch;
            int b,e;
            cin >> ch >> b >> e;

            if(ch=='M'){
                for(int j=b; j<=e; j++){
                    M[j]++;
                }
            }
            else{
                for(int j=b; j<=e; j++){
                    F[j]++;
                }
            }
        }

        int maxx=0;

        /*for(int i=1; i<=366; i++)
        {
            if(M[i]==F[i]){
                if(M[i]+F[i]>maxx){
                    maxx=M[i]+F[i];
                }
            }
        }*/

        for(int i=1; i<=366; i++)
        {
            int cnt = min(M[i],F[i]);

            if(cnt>maxx){
                maxx=cnt;
            }
        }

        printf("%d\n",2*maxx);
    }

    return 0;
}
