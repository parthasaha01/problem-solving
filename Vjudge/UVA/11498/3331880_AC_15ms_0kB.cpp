#include<iostream>
using namespace std;
int main()
{
    int K,N,M,X,Y;

    while(cin >> K)
    {
        if(K==0)
            break;

        cin >> N >> M;

        while(K--)
        {
            cin >> X >> Y;

            if(X==N || Y==M)
                cout << "divisa" << endl;
            else if(X>N){
                if(Y>M)
                    cout << "NE" << endl;
                else    //Y<M
                    cout << "SE" << endl;
            }
            else{   // X<N
                if(Y>M)
                    cout << "NO" << endl;
                else    // Y<M
                    cout << "SO" << endl;
            }
        }
    }

    return 0;
}
