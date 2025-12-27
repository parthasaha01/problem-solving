#include<iostream>
using namespace std;
int main()
{
    int T,N,P,Q,i,result,test,weight;

    cin >> T;

    for(test=1; test<=T; test++)
    {
        cin >> N >> P >> Q;

        int egg[N];
        result=0;

        for(i=0; i<N; i++){
            cin >> egg[i];
        }

        if(P>N)
            P=N;

        for(i=0; i<P; i++){
            if(egg[i]<=Q){
                result++;
                Q -= egg[i];
            }
            else
                break;
        }

        cout << "Case " << test << ": " << result << endl;
    }

    return 0;
}
